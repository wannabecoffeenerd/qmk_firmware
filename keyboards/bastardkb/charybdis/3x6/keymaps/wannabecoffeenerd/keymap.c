/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keycodes.h"

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUMBER,
    LAYER_SYMBOL,
    LAYER_NAV,
};

#define NUMBER OSL(LAYER_NUMBER)
#define SYMBOL OSL(LAYER_SYMBOL)
#define TOBASE TG(LAYER_NAV)
#define TONAV TO(LAYER_NAV)
#define MONAV MO(LAYER_NAV)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         TONAV,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_BSPC, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  NUMBER,  SYMBOL,  OSM(MOD_LSFT),    OSM(MOD_LCTL),  KC_SPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NUMBER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      XXXXXXX, KC_VOLD, KC_VOLU, G(KC_LSFT), KC_LGUI, KC_ASTR,  HT_PLUS_F11, HT_7_F7, HT_8_F8, HT_9_F9, LCTL(KC_B), XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, KC_PEQL, KC_COLN, XXXXXXX, KC_SLSH,    HT_PMNS_F12, HT_4_F4, HT_5_F5, HT_6_F6,  KC_ENT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,  KC_TAB, KC_MPLY, KC_MNXT, KC_PDOT, KC_PEQL,    KC_PDOT,     HT_1_F1, HT_2_F2, HT_3_F3, KC_BSPC, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  NUMBER,  SYMBOL,  KC_LSFT,    KC_P0,  KC_SPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYMBOL] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, KC_TILD, KC_COLN, XXXXXXX, KC_LPRN, XXXXXXX,    XXXXXXX, KC_RPRN, KC_PLUS, KC_QUES, KC_PIPE, XXXXXXX,
  // ├──────────────────────────────────────────────────────╮ ├──────────────────────────────────────────────────────┤
       XXXXXXX,  KC_GRV, KC_DQUO, KC_PEQL, KC_LCBR,   KC_LT,      KC_GT, KC_RCBR, KC_PMNS, KC_UNDS, KC_SCLN, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,  KC_TAB, XXXXXXX, KC_SCLN, KC_LBRC, XXXXXXX,    QK_BOOT, KC_RBRC, KC_COMM,  KC_DOT, KC_BSPC, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  NUMBER,  SYMBOL,  KC_LSFT,    KC_LCTL,  KC_SPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT(
  // ╭──────────────────────────────────────
      XXXXXXX, XXXXXXX, XXXXXXX, A(KC_RIGHT), G(S(KC_Z)), XXXXXXX, G(KC_C), G(KC_Z), TOBASE,  KC_DEL, G(KC_V), XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, G(KC_X), XXXXXXX, XXXXXXX,    KC_LEFT, KC_DOWN,   KC_UP,  KC_RIGHT, KC_ENT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,  KC_TAB,  KC_DEL, XXXXXXX,  KC_END, A(KC_LEFT),    XXXXXXX, POINTER_DEFAULT_DPI_FORWARD, POINTER_DEFAULT_DPI_REVERSE, XXXXXXX, KC_BSPC, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  NUMBER,  SYMBOL,  KC_LSFT,    KC_LCTL, TOBASE
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

// combos
const uint16_t PROGMEM combo_monav[] = {OSM(MOD_LCTL), KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_escape[] = {KC_A, KC_Z, COMBO_END};

// modifiers
const uint16_t PROGMEM combo_lgui[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_lalt[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM combo_laltgui[] = {KC_A, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_rgui[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_ralt[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM combo_raltgui[] = {KC_J, KC_K, KC_L, COMBO_END};

// mouse controls
const uint16_t PROGMEM combo_btn1[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_btn2[] = {KC_M, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_dragscroll[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};

// symbols
const uint16_t PROGMEM combo_exlm[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM combo_at[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM combo_dlr[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM combo_perc[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_circ[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_ampr[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM combo_astr[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM combo_slsh[] = {KC_O, KC_L, COMBO_END};
const uint16_t PROGMEM combo_bsls[] = {KC_P, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_tild[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_monav, MONAV),
    COMBO(combo_enter, KC_ENT),
    COMBO(combo_escape, KC_ESC),

    COMBO(combo_tab, KC_TAB),
    COMBO(combo_lgui, KC_LGUI),
    COMBO(combo_lalt, KC_LALT),
    COMBO(combo_laltgui, LALT(KC_LGUI)),
    COMBO(combo_rgui, KC_RGUI),
    COMBO(combo_ralt, KC_RALT),
    COMBO(combo_raltgui, RALT(KC_RGUI)),

    COMBO(combo_btn1, KC_BTN1),
    COMBO(combo_btn2, KC_BTN2),
    COMBO(combo_dragscroll, DRAGSCROLL_MODE),

    COMBO(combo_exlm, KC_EXLM),
    COMBO(combo_at, KC_AT),
    COMBO(combo_hash, KC_HASH),
    COMBO(combo_dlr, KC_DLR),
    COMBO(combo_perc, KC_PERC),
    COMBO(combo_circ, KC_CIRC),
    COMBO(combo_ampr, KC_AMPR),
    COMBO(combo_astr, KC_ASTR),
    COMBO(combo_slsh, KC_SLSH),
    COMBO(combo_bsls, KC_BSLS),
    COMBO(combo_tild, KC_TILD),
};
