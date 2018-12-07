void setNightValues(bool night){
    if(night){
        //night values
        for(byte ch = 0;ch < CHANNELS; ch++){
            channels[ch].setMinValue(valueMinNight[ch]);
            channels[ch].setMaxValue(valueMaxNight[ch]);
        }
    }else{
        //day values
        for(byte ch = 0;ch < CHANNELS; ch++){
            channels[ch].setMinValue(valueMinDay[ch]);
            channels[ch].setMaxValue(valueMaxDay[ch]);
        }
    }
}

void taskSoftOnOff(byte channel, byte value){
    if(value == 0)
        channels[channel].taskSoftOff();
    else
        channels[channel].taskSoftOn();
}

void taskDimUpDownStop(byte channel, byte value){
    //use only 3 last bits
    byte step = value & DPT3_007_MASK_STEP;
    //true = increase, false = decrease
    bool direction = value & DPT3_007_MASK_DIRECTION;
    Debug.println(F("value: %d, step: %d, direction: %d"), value, step, direction);
    //if step == B?????000 then stop
    if(step == DPT3_007_STOP)
        channels[channel].taskStop();
    else
        if(direction)
            channels[channel].taskDimUp();
        else
            channels[channel].taskDimDown();
}

void taskNewValue(byte channel, byte value){
    channels[channel].taskNewValue(value);
}

void taskScene(byte channel, byte value){
    if (value != 0xFF){
        for(byte sc = 0; sc < SCENES; sc++){
            if (sceneActive[channel][sc] == value){
                channels[channel].taskNewValue(sceneValue[channel][sc]);
            }
        }
    }
}

void knxEvents(byte comObjIndex) {
    byte channel = floor((comObjIndex-FIRST_KNX_OBJ) / COMOBJ_PER_CHANEL); 
    byte newTask = ((comObjIndex-FIRST_KNX_OBJ) % COMOBJ_PER_CHANEL);
    if(channel < CHANNELS){ 
        Debug.println(F("comObjIndex: %d channel: %d newTask: %d"), comObjIndex, channel, newTask);
        switch (newTask){
            case 0 : // Switch
                taskSoftOnOff(channel, Knx.read(comObjIndex));
                break;
          
            case 1 : // Relative dimming
                taskDimUpDownStop(channel, Knx.read(comObjIndex));
                break;
       
            case 2 : // Absolute dimming
                taskNewValue(channel, Knx.read(comObjIndex));
                break;
                
            case 3 : // Scene 
                taskScene(channel, Knx.read(comObjIndex));
                break;
            default:
                break;
        }
    }
    if(comObjIndex == COMOBJ_night){
        setNightValues(Knx.read(comObjIndex));
        Debug.println(F("comObjIndex: %d nightMode: %d"), comObjIndex, Knx.read(comObjIndex));
    }
    if(comObjIndex == COMOBJ_power_supply_input){
        powerSupplyState = Knx.read(comObjIndex);
        Debug.println(F("comObjIndex: %d power supply: %d"), comObjIndex, powerSupplyState);
    }
    //workaround until beta5
    if(comObjIndex == COMOBJ_all_ch_sc){
        Debug.println(F("comObjIndex: %d all scenes: %d"), comObjIndex, Knx.read(comObjIndex));
        for(byte ch = 0; ch < CHANNELS; ch++){
            taskScene(ch, Knx.read(comObjIndex));
        }
    }
}
