#include "tap_dance.h"

bool process_record_tapdance(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case TD(TD_HT_START) ... TD(TD_HT_END) :  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [TD_HT_1_F1] = ACTION_TAP_DANCE_TAP_HOLD(KC_1, KC_F1),
    [TD_HT_2_F2] = ACTION_TAP_DANCE_TAP_HOLD(KC_2, KC_F2),
    [TD_HT_3_F3] = ACTION_TAP_DANCE_TAP_HOLD(KC_3, KC_F3),
    [TD_HT_4_F4] = ACTION_TAP_DANCE_TAP_HOLD(KC_4, KC_F4),
    [TD_HT_5_F5] = ACTION_TAP_DANCE_TAP_HOLD(KC_5, KC_F5),
    [TD_HT_6_F6] = ACTION_TAP_DANCE_TAP_HOLD(KC_6, KC_F6),
    [TD_HT_7_F7] = ACTION_TAP_DANCE_TAP_HOLD(KC_7, KC_F7),
    [TD_HT_8_F8] = ACTION_TAP_DANCE_TAP_HOLD(KC_8, KC_F8),
    [TD_HT_9_F9] = ACTION_TAP_DANCE_TAP_HOLD(KC_9, KC_F9),
    [TD_HT_PLUS_F11] = ACTION_TAP_DANCE_TAP_HOLD(KC_PLUS, KC_F11),
    [TD_HT_PMNS_F12] = ACTION_TAP_DANCE_TAP_HOLD(KC_PMNS, KC_F12),
};
