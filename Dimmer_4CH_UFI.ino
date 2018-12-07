//Hardware settings
#define PWM_START_VALUE 139
#define PWM_MAX_VALUE 3999
#define PWM_STEPS 256

//KNX stuff
#define PROG_BUTTON_PIN 7
#define PROG_LED_PIN 8
#define KNX_SERIAL Serial1

//libraries
#include <Dimmer32u4.h>        //http://librarymanager/All#Dimmer32u4
#include <DimmerControl.h>     //http://librarymanager/All#DimmerControl
#include <KonnektingDevice.h>  //http://librarymanager/All#Konnekting
#include "kdevice_Dimmer_4CH_UFI.h"

//Debug
//#define KDEBUG // comment this line to disable DEBUG mode
#ifdef KDEBUG
#include <DebugUtil.h>
#define DEBUGSERIAL Serial
#endif

//DPT3.007 stuff
#define DPT3_007_MASK_DIRECTION B1000
#define DPT3_007_INCREASE       B1000
#define DPT3_007_DECREASE       B0000
#define DPT3_007_MASK_STEP      B0111
#define DPT3_007_STOP           B0000

//XML file settings
#define CHANNELS 4            // amount of channels
#define PARAMS_PER_CHANNEL 17 // amount of parameters per channel channel
#define FIRST_PARAM 0         // first paramter of first channel
#define FIRST_SCENE_PARAM 7   // id of first chX_sc0_nr parameter
#define COMOBJ_PER_CHANEL 6   // maximum of objects / channel
#define FIRST_KNX_OBJ 0       // task 0, channel 0
#define SCENES 5              // scenes per channel

byte currentValue[CHANNELS];
bool lastState[CHANNELS];
byte valueMinDay[CHANNELS];
byte valueMaxDay[CHANNELS];
byte valueMinNight[CHANNELS];
byte valueMaxNight[CHANNELS];
byte sceneActive[CHANNELS][SCENES];
byte sceneValue[CHANNELS][SCENES];
float gamma[CHANNELS] = {2.0, 2.0, 2.0, 2.0};
byte softOnOffTimeList[] = {0,3,5,7,10,15,20}; //hundreds of milliseconds: 0,300,500...
byte relDimTimeList[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,20}; //seconds
bool powerSupplyState = false;
bool powerSupplyStateLast = false;
bool powerSupplyControl = false;
word powerSupplyOnDelay = 0;
unsigned long powerSupplyOffDelay = 0;

#define NO_TASK 0xFF

byte newTaskType[CHANNELS];
byte newTaskValue[CHANNELS];

//all Pins are inverted
Dimmer32u4 pins[] = {
    Dimmer32u4(5,true),
    Dimmer32u4(9,true),
    Dimmer32u4(10,true),
    Dimmer32u4(11,true)
};

//create array of DimmerControls
DimmerControl channels[] = {
    DimmerControl(0),
    DimmerControl(1),
    DimmerControl(2),
    DimmerControl(3)
};

word getLogValue(byte index, float gamma, byte startValue, word maxValue, word steps){
    if (index > 0){
        word result = round(pow((float)index / (float)(steps - 1.0), gamma) * (float)(maxValue - startValue) + startValue);
        if(result > maxValue)
            return maxValue;
        else
            return result;
    }else{
        return 0;
    }
}

void setChannelValue(byte channel, byte index){
    pins[channel].setValue(getLogValue(index, gamma[channel], PWM_START_VALUE, PWM_MAX_VALUE, PWM_STEPS));
}


#include "knxEvents.h"

//interrupt every 1ms
SIGNAL(TIMER0_COMPA_vect) 
{
    for(byte ch = 0; ch < CHANNELS;ch++){
        channels[ch].task();
    }
}


void setup(){
    //setup timer0 interrupt
    OCR0A = 0xFF;
    TIMSK0 |= _BV(OCIE0A);
    
#ifdef KDEBUG
    DEBUGSERIAL.begin(115200);
    while(!DEBUGSERIAL);
    Debug.setPrintStream(&DEBUGSERIAL);
#endif
    Konnekting.init(KNX_SERIAL, PROG_BUTTON_PIN, PROG_LED_PIN, MANUFACTURER_ID, DEVICE_ID, REVISION);

    //power supply settings
    powerSupplyControl = Konnekting.getUINT8Param(PARAM_ps_control);
    powerSupplyOnDelay = Konnekting.getUINT16Param(PARAM_ps_delay_on); //milliseconds
    powerSupplyOffDelay = Konnekting.getUINT8Param(PARAM_ps_delay_off) * 60000; //minutes

    //channel settings
    for(byte ch = 0; ch < CHANNELS; ch++){
        //on start all channels are off
        lastState[ch] = false;
        newTaskType[ch] = NO_TASK;
        //set function that should be called to control output
        channels[ch].setValueIdFunction(&setChannelValue);
        //init pwm
        pins[ch].init();
        //read paramters
        gamma[ch] = Konnekting.getUINT8Param(ch * PARAMS_PER_CHANNEL+FIRST_PARAM + 0) * 0.1;
        channels[ch].setDurationAbsolute(softOnOffTimeList[Konnekting.getUINT8Param(ch * PARAMS_PER_CHANNEL + FIRST_PARAM + 1)] * 100);
        channels[ch].setDurationRelative(relDimTimeList[Konnekting.getUINT8Param(ch * PARAMS_PER_CHANNEL + FIRST_PARAM + 2)] * 1000);
        valueMinDay[ch] = Konnekting.getUINT8Param(ch * PARAMS_PER_CHANNEL+FIRST_PARAM + 3);
        valueMaxDay[ch] = Konnekting.getUINT8Param(ch * PARAMS_PER_CHANNEL+FIRST_PARAM + 4);
        valueMinNight[ch] = Konnekting.getUINT8Param(ch * PARAMS_PER_CHANNEL+FIRST_PARAM + 5);
        valueMaxNight[ch] = Konnekting.getUINT8Param(ch * PARAMS_PER_CHANNEL+FIRST_PARAM + 6);
        for (int sc = 0; sc < SCENES; sc++){
            sceneActive[ch][sc] = Konnekting.getUINT8Param(ch * PARAMS_PER_CHANNEL + sc * 2 + FIRST_SCENE_PARAM);
            sceneValue[ch][sc] = Konnekting.getUINT8Param(ch * PARAMS_PER_CHANNEL + sc * 2 + FIRST_SCENE_PARAM + 1);
        }
        if(powerSupplyControl){
            channels[ch].setPowerSupplyOnDelay(powerSupplyOnDelay); //milliseconds
            channels[ch].setPowerSupplyOffDelay(powerSupplyOffDelay); //milliseconds
        }
    }

    //set day values until we know if it is day or night
    setNightValues(false);
    Debug.println(F("Setup ready :)"));
}

void loop(){
    Knx.task();
    if (Konnekting.isReadyForApplication()) {
        
        //assumption: all channels are off -> power supply must be off
        bool powerSupplyStateTemp = false;
        
        //we got from external source, that power supply is already on
        if(powerSupplyState){
            powerSupplyStateTemp = true;
            powerSupplyStateLast = true;
        }
            
        for(byte ch = 0; ch < CHANNELS; ch++){
            if(channels[ch].updateAvailable()){
                if(channels[ch].getCurrentValue()){
                    Knx.write(ch*COMOBJ_PER_CHANEL+FIRST_KNX_OBJ+4,DPT1_001_on); //state = on
                    Debug.println(F("Send to Obj: %d value: 1"), ch * COMOBJ_PER_CHANEL + FIRST_KNX_OBJ + 4);
                }else{
                    Knx.write(ch*COMOBJ_PER_CHANEL+FIRST_KNX_OBJ+4,DPT1_001_off); //state = off
                    Debug.println(F("Send to Obj: %d value: 0"), ch * COMOBJ_PER_CHANEL + FIRST_KNX_OBJ + 4);
                }
                Knx.write(ch*COMOBJ_PER_CHANEL+FIRST_KNX_OBJ+5,channels[ch].getCurrentValue());
                Debug.println(F("Send to Obj: %d value: %d"), ch * COMOBJ_PER_CHANEL + FIRST_KNX_OBJ + 5, channels[ch].getCurrentValue());
                channels[ch].resetUpdateFlag();
            }
            //check if at least one channel is on -> power supply must be on
            if(channels[ch].getPowerSupplyState()){
                powerSupplyStateTemp = true;
            }
        }
        
        //notify all channels about power supply state
        if(powerSupplyStateTemp){
            //if power supply is on, we don't need delay any more for other channels -> set on-delay to 0 for all, because it easier
            for(byte ch = 0; ch < CHANNELS; ch++){
                channels[ch].setPowerSupplyOnDelay(0);
            }
        }else{
            //if power supply is off, restore on-delay-setting for all channels
            for(byte ch = 0; ch < CHANNELS; ch++){
                channels[ch].setPowerSupplyOnDelay(powerSupplyOnDelay);
            }
        }
        
        //power supply control
        if(powerSupplyControl && powerSupplyStateTemp != powerSupplyStateLast){
           Debug.println(F("powerSupplyStateTemp: %d"),powerSupplyStateTemp);
            if(powerSupplyStateTemp){
                Knx.write(COMOBJ_power_supply,DPT1_001_on);
                Debug.println(F("Send to Obj: %d PowerSupply on"),COMOBJ_power_supply);
            }else{
                Knx.write(COMOBJ_power_supply,DPT1_001_off);
                Debug.println(F("Send to Obj: %d PowerSupply off"),COMOBJ_power_supply);
            }
            powerSupplyStateLast = powerSupplyStateTemp;
        }
    }
}
