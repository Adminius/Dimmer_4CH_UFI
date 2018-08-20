#define MANUFACTURER_ID 7070
#define DEVICE_ID 102
#define REVISION 1

#define COMOBJ_ch1_sw 0
#define COMOBJ_ch1_dimrel 1
#define COMOBJ_ch1_dimabs 2
#define COMOBJ_ch1_sc 3
#define COMOBJ_ch1_state 4
#define COMOBJ_ch1_value 5
#define COMOBJ_ch2_sw 6
#define COMOBJ_ch2_dimrel 7
#define COMOBJ_ch2_dimabs 8
#define COMOBJ_ch2_sc 9
#define COMOBJ_ch2_state 10
#define COMOBJ_ch2_value 11
#define COMOBJ_ch3_sw 12
#define COMOBJ_ch3_dimrel 13
#define COMOBJ_ch3_dimabs 14
#define COMOBJ_ch3_sc 15
#define COMOBJ_ch3_state 16
#define COMOBJ_ch3_value 17
#define COMOBJ_ch4_sw 18
#define COMOBJ_ch4_dimrel 19
#define COMOBJ_ch4_dimabs 20
#define COMOBJ_ch4_sc 21
#define COMOBJ_ch4_state 22
#define COMOBJ_ch4_value 23
#define COMOBJ_night 24
#define COMOBJ_all_ch_sc 25

#define PARAM_dimmspeed 0
#define PARAM_ch0_dimch 1
#define PARAM_ch0_day_min 2
#define PARAM_ch0_day_max 3
#define PARAM_ch0_night_min 4
#define PARAM_ch0_night_max 5
#define PARAM_ch0_sc0_nr 6
#define PARAM_ch0_sc0_value 7
#define PARAM_ch0_sc1_nr 8
#define PARAM_ch0_sc1_value 9
#define PARAM_ch0_sc2_nr 10
#define PARAM_ch0_sc2_value 11
#define PARAM_ch0_sc3_nr 12
#define PARAM_ch0_sc3_value 13
#define PARAM_ch0_sc4_nr 14
#define PARAM_ch0_sc4_value 15
#define PARAM_ch1_dimch 16
#define PARAM_ch1_day_min 17
#define PARAM_ch1_day_max 18
#define PARAM_ch1_night_min 19
#define PARAM_ch1_night_max 20
#define PARAM_ch1_sc0_nr 21
#define PARAM_ch1_sc0_value 22
#define PARAM_ch1_sc1_nr 23
#define PARAM_ch1_sc1_value 24
#define PARAM_ch1_sc2_nr 25
#define PARAM_ch1_sc2_value 26
#define PARAM_ch1_sc3_nr 27
#define PARAM_ch1_sc3_value 28
#define PARAM_ch1_sc4_nr 29
#define PARAM_ch1_sc4_value 30
#define PARAM_ch2_dimch 31
#define PARAM_ch2_day_min 32
#define PARAM_ch2_day_max 33
#define PARAM_ch2_night_min 34
#define PARAM_ch2_night_max 35
#define PARAM_ch2_sc0_nr 36
#define PARAM_ch2_sc0_value 37
#define PARAM_ch2_sc1_nr 38
#define PARAM_ch2_sc1_value 39
#define PARAM_ch2_sc2_nr 40
#define PARAM_ch2_sc2_value 41
#define PARAM_ch2_sc3_nr 42
#define PARAM_ch2_sc3_value 43
#define PARAM_ch2_sc4_nr 44
#define PARAM_ch2_sc4_value 45
#define PARAM_ch3_dimch 46
#define PARAM_ch3_day_min 47
#define PARAM_ch3_day_max 48
#define PARAM_ch3_night_min 49
#define PARAM_ch3_night_max 50
#define PARAM_ch3_sc0_nr 51
#define PARAM_ch3_sc0_value 52
#define PARAM_ch3_sc1_nr 53
#define PARAM_ch3_sc1_value 54
#define PARAM_ch3_sc2_nr 55
#define PARAM_ch3_sc2_value 56
#define PARAM_ch3_sc3_nr 57
#define PARAM_ch3_sc3_value 58
#define PARAM_ch3_sc4_nr 59
#define PARAM_ch3_sc4_value 60
        
KnxComObject KnxDevice::_comObjectsList[] = {
    /* Index 0 - ch1_sw */ KnxComObject(KNX_DPT_1_001, 0x2a),
    /* Index 1 - ch1_dimrel */ KnxComObject(KNX_DPT_3_007, 0x2a),
    /* Index 2 - ch1_dimabs */ KnxComObject(KNX_DPT_5_004, 0x2a),
    /* Index 3 - ch1_sc */ KnxComObject(KNX_DPT_17_001, 0x2a),
    /* Index 4 - ch1_state */ KnxComObject(KNX_DPT_1_001, 0x34),
    /* Index 5 - ch1_value */ KnxComObject(KNX_DPT_5_004, 0x34),
    /* Index 6 - ch2_sw */ KnxComObject(KNX_DPT_1_001, 0x2a),
    /* Index 7 - ch2_dimrel */ KnxComObject(KNX_DPT_3_007, 0x2a),
    /* Index 8 - ch2_dimabs */ KnxComObject(KNX_DPT_5_004, 0x2a),
    /* Index 9 - ch2_sc */ KnxComObject(KNX_DPT_17_001, 0x2a),
    /* Index 10 - ch2_state */ KnxComObject(KNX_DPT_1_001, 0x34),
    /* Index 11 - ch2_value */ KnxComObject(KNX_DPT_5_004, 0x34),
    /* Index 12 - ch3_sw */ KnxComObject(KNX_DPT_1_001, 0x2a),
    /* Index 13 - ch3_dimrel */ KnxComObject(KNX_DPT_3_007, 0x2a),
    /* Index 14 - ch3_dimabs */ KnxComObject(KNX_DPT_5_004, 0x2a),
    /* Index 15 - ch3_sc */ KnxComObject(KNX_DPT_17_001, 0x2a),
    /* Index 16 - ch3_state */ KnxComObject(KNX_DPT_1_001, 0x34),
    /* Index 17 - ch3_value */ KnxComObject(KNX_DPT_5_004, 0x34),
    /* Index 18 - ch4_sw */ KnxComObject(KNX_DPT_1_001, 0x2a),
    /* Index 19 - ch4_dimrel */ KnxComObject(KNX_DPT_3_007, 0x2a),
    /* Index 20 - ch4_dimabs */ KnxComObject(KNX_DPT_5_004, 0x2a),
    /* Index 21 - ch4_sc */ KnxComObject(KNX_DPT_17_001, 0x2a),
    /* Index 22 - ch4_state */ KnxComObject(KNX_DPT_1_001, 0x34),
    /* Index 23 - ch4_value */ KnxComObject(KNX_DPT_5_004, 0x34),
    /* Index 24 - night */ KnxComObject(KNX_DPT_1_001, 0x2b),
    /* Index 25 - all_ch_sc */ KnxComObject(KNX_DPT_17_001, 0x2a)
};
const byte KnxDevice::_numberOfComObjects = sizeof (_comObjectsList) / sizeof (KnxComObject); // do not change this code
       
byte KonnektingDevice::_paramSizeList[] = {
    /* Index 0 - dimmspeed */ PARAM_UINT8,
    /* Index 1 - ch0_dimch */ PARAM_UINT8,
    /* Index 2 - ch0_day_min */ PARAM_UINT8,
    /* Index 3 - ch0_day_max */ PARAM_UINT8,
    /* Index 4 - ch0_night_min */ PARAM_UINT8,
    /* Index 5 - ch0_night_max */ PARAM_UINT8,
    /* Index 6 - ch0_sc0_nr */ PARAM_UINT8,
    /* Index 7 - ch0_sc0_value */ PARAM_UINT8,
    /* Index 8 - ch0_sc1_nr */ PARAM_UINT8,
    /* Index 9 - ch0_sc1_value */ PARAM_UINT8,
    /* Index 10 - ch0_sc2_nr */ PARAM_UINT8,
    /* Index 11 - ch0_sc2_value */ PARAM_UINT8,
    /* Index 12 - ch0_sc3_nr */ PARAM_UINT8,
    /* Index 13 - ch0_sc3_value */ PARAM_UINT8,
    /* Index 14 - ch0_sc4_nr */ PARAM_UINT8,
    /* Index 15 - ch0_sc4_value */ PARAM_UINT8,
    /* Index 16 - ch1_dimch */ PARAM_UINT8,
    /* Index 17 - ch1_day_min */ PARAM_UINT8,
    /* Index 18 - ch1_day_max */ PARAM_UINT8,
    /* Index 19 - ch1_night_min */ PARAM_UINT8,
    /* Index 20 - ch1_night_max */ PARAM_UINT8,
    /* Index 21 - ch1_sc0_nr */ PARAM_UINT8,
    /* Index 22 - ch1_sc0_value */ PARAM_UINT8,
    /* Index 23 - ch1_sc1_nr */ PARAM_UINT8,
    /* Index 24 - ch1_sc1_value */ PARAM_UINT8,
    /* Index 25 - ch1_sc2_nr */ PARAM_UINT8,
    /* Index 26 - ch1_sc2_value */ PARAM_UINT8,
    /* Index 27 - ch1_sc3_nr */ PARAM_UINT8,
    /* Index 28 - ch1_sc3_value */ PARAM_UINT8,
    /* Index 29 - ch1_sc4_nr */ PARAM_UINT8,
    /* Index 30 - ch1_sc4_value */ PARAM_UINT8,
    /* Index 31 - ch2_dimch */ PARAM_UINT8,
    /* Index 32 - ch2_day_min */ PARAM_UINT8,
    /* Index 33 - ch2_day_max */ PARAM_UINT8,
    /* Index 34 - ch2_night_min */ PARAM_UINT8,
    /* Index 35 - ch2_night_max */ PARAM_UINT8,
    /* Index 36 - ch2_sc0_nr */ PARAM_UINT8,
    /* Index 37 - ch2_sc0_value */ PARAM_UINT8,
    /* Index 38 - ch2_sc1_nr */ PARAM_UINT8,
    /* Index 39 - ch2_sc1_value */ PARAM_UINT8,
    /* Index 40 - ch2_sc2_nr */ PARAM_UINT8,
    /* Index 41 - ch2_sc2_value */ PARAM_UINT8,
    /* Index 42 - ch2_sc3_nr */ PARAM_UINT8,
    /* Index 43 - ch2_sc3_value */ PARAM_UINT8,
    /* Index 44 - ch2_sc4_nr */ PARAM_UINT8,
    /* Index 45 - ch2_sc4_value */ PARAM_UINT8,
    /* Index 46 - ch3_dimch */ PARAM_UINT8,
    /* Index 47 - ch3_day_min */ PARAM_UINT8,
    /* Index 48 - ch3_day_max */ PARAM_UINT8,
    /* Index 49 - ch3_night_min */ PARAM_UINT8,
    /* Index 50 - ch3_night_max */ PARAM_UINT8,
    /* Index 51 - ch3_sc0_nr */ PARAM_UINT8,
    /* Index 52 - ch3_sc0_value */ PARAM_UINT8,
    /* Index 53 - ch3_sc1_nr */ PARAM_UINT8,
    /* Index 54 - ch3_sc1_value */ PARAM_UINT8,
    /* Index 55 - ch3_sc2_nr */ PARAM_UINT8,
    /* Index 56 - ch3_sc2_value */ PARAM_UINT8,
    /* Index 57 - ch3_sc3_nr */ PARAM_UINT8,
    /* Index 58 - ch3_sc3_value */ PARAM_UINT8,
    /* Index 59 - ch3_sc4_nr */ PARAM_UINT8,
    /* Index 60 - ch3_sc4_value */ PARAM_UINT8,
    /* Index 61 - ch4_dimch */ PARAM_UINT8,
    /* Index 62 - ch4_day_min */ PARAM_UINT8,
    /* Index 63 - ch4_day_max */ PARAM_UINT8,
    /* Index 64 - ch4_night_min */ PARAM_UINT8,
    /* Index 65 - ch4_night_max */ PARAM_UINT8,
    /* Index 66 - ch4_sc0_nr */ PARAM_UINT8,
    /* Index 67 - ch4_sc0_value */ PARAM_UINT8,
    /* Index 68 - ch4_sc1_nr */ PARAM_UINT8,
    /* Index 69 - ch4_sc1_value */ PARAM_UINT8,
    /* Index 70 - ch4_sc2_nr */ PARAM_UINT8,
    /* Index 71 - ch4_sc2_value */ PARAM_UINT8,
    /* Index 72 - ch4_sc3_nr */ PARAM_UINT8,
    /* Index 73 - ch4_sc3_value */ PARAM_UINT8,
    /* Index 74 - ch4_sc4_nr */ PARAM_UINT8,
    /* Index 75 - ch4_sc4_value */ PARAM_UINT8,
    /* Index 76 - ch5_dimch */ PARAM_UINT8,
    /* Index 77 - ch5_day_min */ PARAM_UINT8,
    /* Index 78 - ch5_day_max */ PARAM_UINT8,
    /* Index 79 - ch5_night_min */ PARAM_UINT8,
    /* Index 80 - ch5_night_max */ PARAM_UINT8,
    /* Index 81 - ch5_sc0_nr */ PARAM_UINT8,
    /* Index 82 - ch5_sc0_value */ PARAM_UINT8,
    /* Index 83 - ch5_sc1_nr */ PARAM_UINT8,
    /* Index 84 - ch5_sc1_value */ PARAM_UINT8,
    /* Index 85 - ch5_sc2_nr */ PARAM_UINT8,
    /* Index 86 - ch5_sc2_value */ PARAM_UINT8,
    /* Index 87 - ch5_sc3_nr */ PARAM_UINT8,
    /* Index 88 - ch5_sc3_value */ PARAM_UINT8,
    /* Index 89 - ch5_sc4_nr */ PARAM_UINT8,
    /* Index 90 - ch5_sc4_value */ PARAM_UINT8,
    /* Index 91 - ch6_dimch */ PARAM_UINT8,
    /* Index 92 - ch6_day_min */ PARAM_UINT8,
    /* Index 93 - ch6_day_max */ PARAM_UINT8,
    /* Index 94 - ch6_night_min */ PARAM_UINT8,
    /* Index 95 - ch6_night_max */ PARAM_UINT8,
    /* Index 96 - ch6_sc0_nr */ PARAM_UINT8,
    /* Index 97 - ch6_sc0_value */ PARAM_UINT8,
    /* Index 98 - ch6_sc1_nr */ PARAM_UINT8,
    /* Index 99 - ch6_sc1_value */ PARAM_UINT8,
    /* Index 100 - ch6_sc2_nr */ PARAM_UINT8,
    /* Index 101 - ch6_sc2_value */ PARAM_UINT8,
    /* Index 102 - ch6_sc3_nr */ PARAM_UINT8,
    /* Index 103 - ch6_sc3_value */ PARAM_UINT8,
    /* Index 104 - ch6_sc4_nr */ PARAM_UINT8,
    /* Index 105 - ch6_sc4_value */ PARAM_UINT8,
    /* Index 106 - ch7_dimch */ PARAM_UINT8,
    /* Index 107 - ch7_day_min */ PARAM_UINT8,
    /* Index 108 - ch7_day_max */ PARAM_UINT8,
    /* Index 109 - ch7_night_min */ PARAM_UINT8,
    /* Index 110 - ch7_night_max */ PARAM_UINT8,
    /* Index 111 - ch7_sc0_nr */ PARAM_UINT8,
    /* Index 112 - ch7_sc0_value */ PARAM_UINT8,
    /* Index 113 - ch7_sc1_nr */ PARAM_UINT8,
    /* Index 114 - ch7_sc1_value */ PARAM_UINT8,
    /* Index 115 - ch7_sc2_nr */ PARAM_UINT8,
    /* Index 116 - ch7_sc2_value */ PARAM_UINT8,
    /* Index 117 - ch7_sc3_nr */ PARAM_UINT8,
    /* Index 118 - ch7_sc3_value */ PARAM_UINT8,
    /* Index 119 - ch7_sc4_nr */ PARAM_UINT8,
    /* Index 120 - ch7_sc4_value */ PARAM_UINT8,
    /* Index 121 - ch8_dimch */ PARAM_UINT8,
    /* Index 122 - ch8_day_min */ PARAM_UINT8,
    /* Index 123 - ch8_day_max */ PARAM_UINT8,
    /* Index 124 - ch8_night_min */ PARAM_UINT8,
    /* Index 125 - ch8_night_max */ PARAM_UINT8,
    /* Index 126 - ch8_sc0_nr */ PARAM_UINT8,
    /* Index 127 - ch8_sc0_value */ PARAM_UINT8,
    /* Index 128 - ch8_sc1_nr */ PARAM_UINT8,
    /* Index 129 - ch8_sc1_value */ PARAM_UINT8,
    /* Index 130 - ch8_sc2_nr */ PARAM_UINT8,
    /* Index 131 - ch8_sc2_value */ PARAM_UINT8,
    /* Index 132 - ch8_sc3_nr */ PARAM_UINT8,
    /* Index 133 - ch8_sc3_value */ PARAM_UINT8,
    /* Index 134 - ch8_sc4_nr */ PARAM_UINT8,
    /* Index 135 - ch8_sc4_value */ PARAM_UINT8
};
const int KonnektingDevice::_numberOfParams = sizeof (_paramSizeList); // do not change this code
