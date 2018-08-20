#include <math.h>
#include <Dimmer32u4.h>        //http://librarymanager/All#Dimmer32u4
#include <DimmerControl.h>     //http://librarymanager/All#DimmerControl
#include <KonnektingDevice.h>  //http://librarymanager/All#Konnekting
#include "getLogValue.h"
#include "kdevice_Dimmer_4CH_UFI.h"

//#define KDEBUG // comment this line to disable DEBUG mode
#ifdef KDEBUG
#include <DebugUtil.h>
#define DEBUGSERIAL Serial
#endif

//KNX stuff
#define PROG_BUTTON_PIN 7
#define PROG_LED_PIN 8
#define KNX_SERIAL Serial1

#define DPT3_007_MASK_DIRECTION B1000
#define DPT3_007_INCREASE       B1000
#define DPT3_007_DECREASE       B0000
#define DPT3_007_MASK_STEP      B0111
#define DPT3_007_STOP           B0000

#define CHANNELS 4            // amount of channels
#define PARAMS_PER_CHANNEL 15 // maximum of parameters / channel
#define FIRST_PARAM 1
#define FIRST_SCENE_PARAM 6
#define COMOBJ_PER_CHANEL 6   // maximum of objects / channel
#define FIRST_KNX_OBJ 0       // task 0, channel 0
#define SCENES 5

byte valueMinDay[CHANNELS];
byte valueMaxDay[CHANNELS];
byte valueMinNight[CHANNELS];
byte valueMaxNight[CHANNELS];
byte sceneActive[CHANNELS][SCENES];
byte sceneValue[CHANNELS][SCENES];

Dimmer32u4 pin5(5,true);
Dimmer32u4 pin9(9,true);
Dimmer32u4 pin10(10,true);
Dimmer32u4 pin11(11,true);

DimmerControl channels[] = {
    DimmerControl(),
    DimmerControl(),
    DimmerControl(),
    DimmerControl()
};

#include "knxEvents.h"

void setCh0Pin5(byte index){
    pin5.setValue(getLogValue(index));
}
void setCh1Pin9(byte index){
    pin9.setValue(getLogValue(index));
}
void setCh2Pin10(byte index){
    pin10.setValue(getLogValue(index));
}
void setCh3Pin11(byte index){
    pin11.setValue(getLogValue(index));
}


//interrupt every 1ms
SIGNAL(TIMER0_COMPA_vect) 
{
    channels[0].task();
    channels[1].task();
    channels[2].task();
    channels[3].task();
}


void setup(){
    OCR0A = 0xFF;
    TIMSK0 |= _BV(OCIE0A);
#ifdef KDEBUG
    DEBUGSERIAL.begin(115200);
    while(!DEBUGSERIAL);
    Debug.setPrintStream(&DEBUGSERIAL);
#endif
    Konnekting.init(KNX_SERIAL,PROG_BUTTON_PIN,PROG_LED_PIN,MANUFACTURER_ID,DEVICE_ID,REVISION);

    //Optonal: how long should it if you turn on/off? (default 300ms)
    //led1.setDurationAbsolute(300); //milliseconds
    //Optonal: how long should it take if you dimming up/down (default 4000ms)
    //led1.setDurationRelative(4000); //milliseconds
    
    //Mandatory: set function that should be called to control output (
    channels[0].setValueFunction(&setCh0Pin5);
    channels[1].setValueFunction(&setCh1Pin9);
    channels[2].setValueFunction(&setCh2Pin10);
    channels[3].setValueFunction(&setCh3Pin11);
    pin5.init();
    pin9.init();
    pin10.init();
    pin11.init();

    for(byte ch = 0;ch < CHANNELS; ch++){
        valueMinDay[ch] = Konnekting.getUINT8Param(ch*PARAMS_PER_CHANNEL+FIRST_PARAM+1);
        valueMaxDay[ch] = Konnekting.getUINT8Param(ch*PARAMS_PER_CHANNEL+FIRST_PARAM+2);
        valueMinNight[ch] = Konnekting.getUINT8Param(ch*PARAMS_PER_CHANNEL+FIRST_PARAM+3);
        valueMaxNight[ch] = Konnekting.getUINT8Param(ch*PARAMS_PER_CHANNEL+FIRST_PARAM+4);
        for (int sc = 0;sc < SCENES;sc++){
            sceneActive[ch][sc] = Konnekting.getUINT8Param(ch*PARAMS_PER_CHANNEL+sc*2+FIRST_SCENE_PARAM);
            sceneValue[ch][sc] = Konnekting.getUINT8Param(ch*PARAMS_PER_CHANNEL+sc*2+FIRST_SCENE_PARAM+1);
        }
    }
    setDayNightValues(false);
    Debug.println(F("Setup ready :)"));
}

void loop(){
    Knx.task();
    if (Konnekting.isReadyForApplication()) {
        for(byte ch = 0;ch<CHANNELS;ch++){
            if(channels[ch].updateAvailable()){
                if(channels[ch].getCurrentValue()){
                    Knx.write(ch*COMOBJ_PER_CHANEL+FIRST_KNX_OBJ+4,1); //state = on
                    Debug.println(F("Send to Obj: %d value: 1"),ch*COMOBJ_PER_CHANEL+FIRST_KNX_OBJ+4);
                }else{
                    Knx.write(ch*COMOBJ_PER_CHANEL+FIRST_KNX_OBJ+4,0); //state = off
                    Debug.println(F("Send to Obj: %d value: 0"),ch*COMOBJ_PER_CHANEL+FIRST_KNX_OBJ+4);
                }
                Knx.write(ch*COMOBJ_PER_CHANEL+FIRST_KNX_OBJ+5,channels[ch].getCurrentValue());
                Debug.println(F("Send to Obj: %d value: %d"),ch*COMOBJ_PER_CHANEL+FIRST_KNX_OBJ+5,channels[ch].getCurrentValue());
            }
        }
    }
}

