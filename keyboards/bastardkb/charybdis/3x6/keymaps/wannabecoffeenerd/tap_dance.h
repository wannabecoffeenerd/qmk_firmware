#pragma once
#include QMK_KEYBOARD_H

enum {
    TD_HT_START,
    TD_HT_1_F1 = 0,
    TD_HT_2_F2,
    TD_HT_3_F3,
    TD_HT_4_F4,
    TD_HT_5_F5,
    TD_HT_6_F6,
    TD_HT_7_F7,
    TD_HT_8_F8,
    TD_HT_9_F9,
    TD_HT_PLUS_F11,
    TD_HT_PMNS_F12,
    TD_HT_END,
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_tapdance(uint16_t keycode, keyrecord_t *record);
