#pragma once
#include QMK_KEYBOARD_H

#ifdef TAP_DANCE_ENABLE

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

#elif

#    define HT_1_F KC_1
#    define HT_2_F KC_2
#    define HT_3_F KC_3
#    define HT_4_F KC_4
#    define HT_5_F KC_5
#    define HT_6_F KC_6
#    define HT_7_F KC_7
#    define HT_8_F KC_8
#    define HT_9_F KC_9
#    define HT_PLUS_F KC_11
#    define HT_PMNS_F KC_12

#endif
