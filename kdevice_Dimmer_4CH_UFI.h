#define MANUFACTURER_ID 7070
#define DEVICE_ID 102
#define REVISION 2

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
#define COMOBJ_power_supply 25
#define COMOBJ_power_supply_input 26
#define COMOBJ_all_ch_sc 27
#define PARAM_ch0_gamma 0
#define PARAM_ch0_time_soft 1
#define PARAM_ch0_time_rel 2
#define PARAM_ch0_day_min 3
#define PARAM_ch0_day_max 4
#define PARAM_ch0_night_min 5
#define PARAM_ch0_night_max 6
#define PARAM_ch0_sc0_nr 7
#define PARAM_ch0_sc0_value 8
#define PARAM_ch0_sc1_nr 9
#define PARAM_ch0_sc1_value 10
#define PARAM_ch0_sc2_nr 11
#define PARAM_ch0_sc2_value 12
#define PARAM_ch0_sc3_nr 13
#define PARAM_ch0_sc3_value 14
#define PARAM_ch0_sc4_nr 15
#define PARAM_ch0_sc4_value 16
#define PARAM_ch1_gamma 17
#define PARAM_ch1_time_soft 18
#define PARAM_ch1_time_rel 19
#define PARAM_ch1_day_min 20
#define PARAM_ch1_day_max 21
#define PARAM_ch1_night_min 22
#define PARAM_ch1_night_max 23
#define PARAM_ch1_sc0_nr 24
#define PARAM_ch1_sc0_value 25
#define PARAM_ch1_sc1_nr 26
#define PARAM_ch1_sc1_value 27
#define PARAM_ch1_sc2_nr 28
#define PARAM_ch1_sc2_value 29
#define PARAM_ch1_sc3_nr 30
#define PARAM_ch1_sc3_value 31
#define PARAM_ch1_sc4_nr 32
#define PARAM_ch1_sc4_value 33
#define PARAM_ch2_gamma 34
#define PARAM_ch2_time_soft 35
#define PARAM_ch2_time_rel 36
#define PARAM_ch2_day_min 37
#define PARAM_ch2_day_max 38
#define PARAM_ch2_night_min 39
#define PARAM_ch2_night_max 40
#define PARAM_ch2_sc0_nr 41
#define PARAM_ch2_sc0_value 42
#define PARAM_ch2_sc1_nr 43
#define PARAM_ch2_sc1_value 44
#define PARAM_ch2_sc2_nr 45
#define PARAM_ch2_sc2_value 46
#define PARAM_ch2_sc3_nr 47
#define PARAM_ch2_sc3_value 48
#define PARAM_ch2_sc4_nr 49
#define PARAM_ch2_sc4_value 50
#define PARAM_ch3_gamma 51
#define PARAM_ch3_time_soft 52
#define PARAM_ch3_time_rel 53
#define PARAM_ch3_day_min 54
#define PARAM_ch3_day_max 55
#define PARAM_ch3_night_min 56
#define PARAM_ch3_night_max 57
#define PARAM_ch3_sc0_nr 58
#define PARAM_ch3_sc0_value 59
#define PARAM_ch3_sc1_nr 60
#define PARAM_ch3_sc1_value 61
#define PARAM_ch3_sc2_nr 62
#define PARAM_ch3_sc2_value 63
#define PARAM_ch3_sc3_nr 64
#define PARAM_ch3_sc3_value 65
#define PARAM_ch3_sc4_nr 66
#define PARAM_ch3_sc4_value 67
#define PARAM_ps_control 68
#define PARAM_ps_delay_on 69
#define PARAM_ps_delay_off 70
        
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
    /* Index 25 - power_supply */ KnxComObject(KNX_DPT_1_001, 0x34),
    /* Index 26 - power_supply_input */ KnxComObject(KNX_DPT_1_001, 0x2b),
    /* Index 27 - all_ch_sc */ KnxComObject(KNX_DPT_17_001, 0x2a)
};
const byte KnxDevice::_numberOfComObjects = sizeof (_comObjectsList) / sizeof (KnxComObject); // do not change this code
       
byte KonnektingDevice::_paramSizeList[] = {
    /* Index 0 - ch0_gamma */ PARAM_UINT8,
    /* Index 1 - ch0_time_soft */ PARAM_UINT8,
    /* Index 2 - ch0_time_rel */ PARAM_UINT8,
    /* Index 3 - ch0_day_min */ PARAM_UINT8,
    /* Index 4 - ch0_day_max */ PARAM_UINT8,
    /* Index 5 - ch0_night_min */ PARAM_UINT8,
    /* Index 6 - ch0_night_max */ PARAM_UINT8,
    /* Index 7 - ch0_sc0_nr */ PARAM_UINT8,
    /* Index 8 - ch0_sc0_value */ PARAM_UINT8,
    /* Index 9 - ch0_sc1_nr */ PARAM_UINT8,
    /* Index 10 - ch0_sc1_value */ PARAM_UINT8,
    /* Index 11 - ch0_sc2_nr */ PARAM_UINT8,
    /* Index 12 - ch0_sc2_value */ PARAM_UINT8,
    /* Index 13 - ch0_sc3_nr */ PARAM_UINT8,
    /* Index 14 - ch0_sc3_value */ PARAM_UINT8,
    /* Index 15 - ch0_sc4_nr */ PARAM_UINT8,
    /* Index 16 - ch0_sc4_value */ PARAM_UINT8,
    /* Index 17 - ch1_gamma */ PARAM_UINT8,
    /* Index 18 - ch1_time_soft */ PARAM_UINT8,
    /* Index 19 - ch1_time_rel */ PARAM_UINT8,
    /* Index 20 - ch1_day_min */ PARAM_UINT8,
    /* Index 21 - ch1_day_max */ PARAM_UINT8,
    /* Index 22 - ch1_night_min */ PARAM_UINT8,
    /* Index 23 - ch1_night_max */ PARAM_UINT8,
    /* Index 24 - ch1_sc0_nr */ PARAM_UINT8,
    /* Index 25 - ch1_sc0_value */ PARAM_UINT8,
    /* Index 26 - ch1_sc1_nr */ PARAM_UINT8,
    /* Index 27 - ch1_sc1_value */ PARAM_UINT8,
    /* Index 28 - ch1_sc2_nr */ PARAM_UINT8,
    /* Index 29 - ch1_sc2_value */ PARAM_UINT8,
    /* Index 30 - ch1_sc3_nr */ PARAM_UINT8,
    /* Index 31 - ch1_sc3_value */ PARAM_UINT8,
    /* Index 32 - ch1_sc4_nr */ PARAM_UINT8,
    /* Index 33 - ch1_sc4_value */ PARAM_UINT8,
    /* Index 34 - ch2_gamma */ PARAM_UINT8,
    /* Index 35 - ch2_time_soft */ PARAM_UINT8,
    /* Index 36 - ch2_time_rel */ PARAM_UINT8,
    /* Index 37 - ch2_day_min */ PARAM_UINT8,
    /* Index 38 - ch2_day_max */ PARAM_UINT8,
    /* Index 39 - ch2_night_min */ PARAM_UINT8,
    /* Index 40 - ch2_night_max */ PARAM_UINT8,
    /* Index 41 - ch2_sc0_nr */ PARAM_UINT8,
    /* Index 42 - ch2_sc0_value */ PARAM_UINT8,
    /* Index 43 - ch2_sc1_nr */ PARAM_UINT8,
    /* Index 44 - ch2_sc1_value */ PARAM_UINT8,
    /* Index 45 - ch2_sc2_nr */ PARAM_UINT8,
    /* Index 46 - ch2_sc2_value */ PARAM_UINT8,
    /* Index 47 - ch2_sc3_nr */ PARAM_UINT8,
    /* Index 48 - ch2_sc3_value */ PARAM_UINT8,
    /* Index 49 - ch2_sc4_nr */ PARAM_UINT8,
    /* Index 50 - ch2_sc4_value */ PARAM_UINT8,
    /* Index 51 - ch3_gamma */ PARAM_UINT8,
    /* Index 52 - ch3_time_soft */ PARAM_UINT8,
    /* Index 53 - ch3_time_rel */ PARAM_UINT8,
    /* Index 54 - ch3_day_min */ PARAM_UINT8,
    /* Index 55 - ch3_day_max */ PARAM_UINT8,
    /* Index 56 - ch3_night_min */ PARAM_UINT8,
    /* Index 57 - ch3_night_max */ PARAM_UINT8,
    /* Index 58 - ch3_sc0_nr */ PARAM_UINT8,
    /* Index 59 - ch3_sc0_value */ PARAM_UINT8,
    /* Index 60 - ch3_sc1_nr */ PARAM_UINT8,
    /* Index 61 - ch3_sc1_value */ PARAM_UINT8,
    /* Index 62 - ch3_sc2_nr */ PARAM_UINT8,
    /* Index 63 - ch3_sc2_value */ PARAM_UINT8,
    /* Index 64 - ch3_sc3_nr */ PARAM_UINT8,
    /* Index 65 - ch3_sc3_value */ PARAM_UINT8,
    /* Index 66 - ch3_sc4_nr */ PARAM_UINT8,
    /* Index 67 - ch3_sc4_value */ PARAM_UINT8,
    /* Index 68 - ps_control */ PARAM_UINT8,
    /* Index 69 - ps_delay_on */ PARAM_UINT16,
    /* Index 70 - ps_delay_off */ PARAM_UINT8
};
const int KonnektingDevice::_numberOfParams = sizeof (_paramSizeList); // do not change this code
