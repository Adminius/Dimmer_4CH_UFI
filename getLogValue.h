word startValue = 139;
word maxValue = 3998;
int steps = 256;

word getLogValue(byte index){
    if (index >0){
        word result = round(startValue * pow(pow(maxValue * 1.00 / (startValue * 1.00), 1.00/(steps-1)),index));
        if(result > maxValue)
            return maxValue;
        else
            return result;
    }else{
        return 0;
    }
}
