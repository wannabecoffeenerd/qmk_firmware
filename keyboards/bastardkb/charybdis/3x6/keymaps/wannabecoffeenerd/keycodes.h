#pragma once
#include QMK_KEYBOARD_H

#ifdef TAP_DANCE_ENABLE
#include "tap_dance.h"
#    define HT_1_F1 TD(TD_HT_1_F1)
#    define HT_2_F2 TD(TD_HT_2_F2)
#    define HT_3_F3 TD(TD_HT_3_F3)
#    define HT_4_F4 TD(TD_HT_4_F4)
#    define HT_5_F5 TD(TD_HT_5_F5)
#    define HT_6_F6 TD(TD_HT_6_F6)
#    define HT_7_F7 TD(TD_HT_7_F7)
#    define HT_8_F8 TD(TD_HT_8_F8)
#    define HT_9_F9 TD(TD_HT_9_F9)
#    define HT_PLUS_F11 TD(TD_HT_PLUS_F11)
#    define HT_PMNS_F12 TD(TD_HT_PMNS_F12)

#else

#    define HT_1_F1 KC_P1
#    define HT_2_F2 KC_P2
#    define HT_3_F3 KC_P3
#    define HT_4_F4 KC_P4
#    define HT_5_F5 KC_P5
#    define HT_6_F6 KC_P6
#    define HT_7_F7 KC_P7
#    define HT_8_F8 KC_P8
#    define HT_9_F9 KC_P9
#    define HT_PLUS_F11 KC_PLUS
#    define HT_PMNS_F12 KC_PMNS

#endif
