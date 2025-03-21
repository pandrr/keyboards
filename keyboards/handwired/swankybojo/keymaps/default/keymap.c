// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_ESC,   KC_Q,   KC_W,   KC_F, KC_P,   KC_B,             KC_J,     KC_L,  KC_U,    KC_Y,   KC_SCLN, KC_BSPC,
        KC_TAB,   KC_A,   KC_S,   KC_R, KC_T,   KC_G,             KC_M,     KC_N,  KC_E,    KC_I,   KC_O,    KC_ENTER,
        KC_LSFT,  KC_Z,   KC_X,   KC_C, KC_D,   KC_V,             KC_K,     KC_H,  KC_COMM, KC_DOT,KC_SLSH, KC_LSFT,
             KC_LALT, KC_LCTL, KC_LGUI, MT(MOD_LSFT,KC_ENTER),    KC_SPACE, MO(1), MO(2),   MO(3)
    ),

    [1] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  QK_BOOT,      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,  XXXXXXX, KC_DEL,
        XXXXXXX, XXXXXXX, XXXXXXX, S(KC_TAB),KC_TAB,   XXXXXXX,      XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
                          _______, _______,  _______,  _______,      _______, _______, _______, _______  
    ),
    /*
     *      1 2 3 4 5   6 7 8 9 0        
     *      ~ [ { ( -   + ) } ] |        
     *      ? ` ' " _   = / ; : \        
     */
    [2] = LAYOUT(
        _______, KC_1,    KC_2,        KC_3,    KC_4,       KC_5,            KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_TILD, KC_LBRC,     KC_LCBR, KC_LPRN,    KC_MINUS,        KC_PLUS,  KC_RPRN, KC_RCBR, KC_RBRC, KC_PIPE, _______,
        _______, S(KC_SLSH),S(KC_GRV), KC_QUOT, S(KC_QUOT), S(KC_MINUS),     KC_EQUAL, KC_SLSH, KC_SCLN, KC_COLN, KC_BSLS, _______,
                            _______, _______, _______, _______,              _______, _______, _______, _______
    ),
    
    [3] = LAYOUT(
        _______,        KC_Q, KC_W, HYPR(KC_F), KC_R,       HYPR(KC_T),   KC_Y ,      KC_U ,         HYPR(KC_UP) ,  KC_O ,          KC_P,    _______,
        LGUI(KC_TILDE), KC_A, KC_S, HYPR(KC_R), HYPR(KC_T), KC_G ,        HYPR(KC_M), HYPR(KC_LEFT), HYPR(KC_DOWN), HYPR(KC_RIGHT), _______, _______,
        _______,        KC_Z, KC_X, HYPR(KC_C), HYPR(KC_D), KC_V ,        KC_K,       HYPR(KC_H) ,   KC_VOLD,KC_VOLU,       _______, _______,
                          _______, _______, _______, _______,      _______, _______, _______, _______
    ),
    
    [4] = LAYOUT(
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______,      _______, _______, _______, _______
    ),

    [5] = LAYOUT(
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______,      _______, _______, _______, _______
    ),
};
