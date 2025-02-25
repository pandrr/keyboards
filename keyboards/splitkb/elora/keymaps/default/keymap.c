// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
//#include "drivers/sensors/pimoroni_trackball.h"

enum layers {
    _COLEMAK= 0,
    _QWERTY,
    _MYSTUFF,
    _MOUSE,
    _SYM,
    _OSM,
    _ADJUST,
};

uint8_t led_min=0,led_max=1;
//uint8_t led_min=1,led_max=255;
int lastScroll=0;//timer_read();


#define USE_I2C

#define SYM    MO(_SYM)
//#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)


#define HORO_S MT(MOD_LCTL,KC_S)
#define HORO_D MT(MOD_LALT,KC_D)
#define HORO_F MT(MOD_LGUI,KC_F)


#define HORO_N MT(MOD_RGUI,KC_N)
#define HORO_E MT(MOD_RALT,KC_E)
#define HORO_L MT(MOD_RCTL,KC_L)

#define MOHO_TAB MT(MOD_LGUI,KC_TAB)
#define MOHO_ENT MT(MOD_LSFT,KC_ENT)

enum custom_keycodes{
    VIM_CMD
};

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
    * Base Layer: QWERTY
    *
    * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
    * |  Esc   |   1  |   2  |   3  |   4  |   5  |      |LShift|  |RShift|      |   6  |   7  |   8  |   9  |   0  |  Esc   |
    * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
    * |  Tab   |   Q  |   W  |   E  |   R  |   T  |      |LCtrl |  | RCtrl|      |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
    * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
    * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |      | LAlt |  | RAlt |      |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
    * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
    * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
    *                        |      |      | Enter|      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    *
    * ,----------------------------.      ,------.                 ,----------------------------.      ,------.
    * | Prev | Next | Pause | Stop |      | Mute |                 | Prev | Next | Pause | Stop |      | Mute |
    * `----------------------------'      `------'                 `----------------------------'      '------'
    */
    [_COLEMAK] = LAYOUT_myr(
        KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,            KC_LSFT,   _______,      KC_6 ,  KC_7 ,  _______ , KC_9 ,  KC_0 ,      KC_BSPC,
        KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,            KC_LCTL,   _______,      KC_J ,  KC_L ,  KC_U ,    KC_Y ,  KC_SCLN ,   KC_QUOTE,
        KC_LSFT , KC_A ,  KC_S   ,  KC_R,     KC_T ,   KC_G ,            KC_LALT,   KC_8,         KC_M ,  KC_N,   KC_E,     KC_I ,  KC_O,       KC_ENT,
        KC_LCTL , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LBRC,   KC_MINS,  KC_EQL,      KC_RBRC, KC_K ,  KC_H ,  KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                 OSM(MOD_LALT), KC_LCTL, KC_LGUI, KC_BSPC,  TT(_MOUSE),  MO(_MOUSE),     KC_SPC, KC_ENT, TT(_MYSTUFF), KC_HYPR,

      KC_A, KC_B, KC_Q, KC_S ,   KC_MUTE,                            KC_B, KC_C, KC_D, KC_E,    KC_A
    ),

    [_QWERTY] = LAYOUT_myr(
        _______, _______, _______, _______, _______, _______,         _______, _______,          _______, _______, _______, _______,  _______, _______,
        _______, KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,            KC_LCTL,   _______,      KC_Y ,  KC_U ,  KC_I ,    KC_O ,  KC_P ,   _______,
        _______, KC_A ,  KC_S   ,  KC_D,     KC_F ,   KC_G ,            KC_LALT,   KC_8,         KC_H ,  KC_J,   KC_K,     KC_L ,  KC_SCLN,       _______,
        _______, KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,   KC_MINS,  KC_EQL,      KC_RBRC, KC_N ,  KC_M ,  _______, _______ , _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

      KC_A, KC_B, KC_Q, KC_S ,   KC_MUTE,                            KC_B, KC_C, KC_D, KC_E,    KC_A
    ),

     [_MYSTUFF] = LAYOUT_myr(
       VIM_CMD, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______,  _______, KC_DEL,
       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, KC_UP,   _______,  _______, _______,
       _______,OSM(MOD_LALT),OSM(MOD_LSFT),OSM(MOD_LCTL),OSM(MOD_LGUI), _______,          _______, _______,          _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
       _______, _______, _______, _______, _______, QK_REP, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, TG(_MYSTUFF), _______,


        _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
     ),


/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |      |      |  |      |      | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,----------------------------.      ,------.                 ,----------------------------.      ,------.
 * | Prev | Next | Pause | Stop |      | Mute |                 | Prev | Next | Pause | Stop |      | Mute |
 * `----------------------------'      `------'                 `----------------------------'      '------'
 */
    [_MOUSE] = LAYOUT_myr(
        _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
        _______, _______, MS_ACL0, MS_ACL1, MS_ACL2, _______,          _______, _______,          MS_BTN1, _______, MS_UP, _______, _______, _______,
        _______, _______, MS_BTN2, MS_BTN3, MS_BTN1, _______,          _______, _______,          MS_BTN3, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MS_BTN2, _______, _______, _______,  _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),







/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |    `   |  1   |  2   |  3   |  4   |  5   |      |      |  |      |      |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |      |      |  |      |      |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,--------A---------------------.      ,------.                ,---------------------------.      ,------.
 * |        |      |      |      |      |      |                |      |      |      |      |      |      |
 * `-----------------------------'      `------'                `---------------------------'      '------'
 */
    [_SYM] = LAYOUT_myr(
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,          _______, _______,            KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,          _______, _______,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),
// /*
//  * Layer template - LAYOUT
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
     [_OSM] = LAYOUT(
       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
       _______,OSM(MOD_LALT),OSM(MOD_LSFT),OSM(MOD_LCTL),OSM(MOD_LGUI), _______,          _______, _______,          _______, OSM(MOD_RGUI), OSM(MOD_RCTL), OSM(MOD_RALT), OSM(MOD_RSFT), _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),

//  * Layer template - LAYOUT
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

//  * Layer template - LAYOUT
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, ____.__, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

//  * Layer template - LAYOUT
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

// /*
//  * Layer template - LAYOUT
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

// /*
//  * Layer template - LAYOUT_myr
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  *
//  * ,-----------------------------.      ,------.                ,---------------------------.      ,------.
//  * |        |      |      |      |      |      |                |      |      |      |      |      |      |
//  * `-----------------------------'      `------'                `---------------------------'      '------'
//  */
//     [_LAYERINDEX] = LAYOUT_myr(
//       _A______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//
//       _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/elora/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

 // DELETE THIS LINE TO UNCOMMENT (1/2)
// #ifdef OLED_ENABLE
// bool oled_task_user(void) {
  // Your code goes here
// }
// #endif

// Rotate OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}
void plot_line (int x0, int y0, int x1, int y1)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = dx + dy, e2; /* error value e_xy */

  for (;;){  /* loop */
    oled_write_pixel(x0,y0,true);
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}

uint8_t lineHeight=25;

void printCmd(uint16_t posy)
{
    posy*=lineHeight;
    plot_line(12,2+posy ,10,0+posy);
plot_line(10,0+posy ,4,0+posy);
plot_line(4,0+posy ,0,3+posy);
plot_line(0,3+posy ,0,16+posy);
plot_line(0,16+posy ,3,20+posy);
plot_line(3,20+posy ,10,20+posy);
plot_line(10,20+posy ,12,17+posy);
plot_line(17,20+posy ,17,0+posy);
plot_line(17,0+posy ,20,0+posy);
plot_line(20,0+posy ,26,20+posy);
plot_line(26,20+posy ,28,20+posy);
plot_line(28,20+posy ,34,0+posy);
plot_line(34,0+posy ,37,0+posy);
plot_line(37,0+posy ,37,20+posy);
plot_line(37,0+posy ,37,20+posy);
plot_line(37,20+posy ,46,20+posy);
plot_line(46,20+posy ,49,17+posy);
plot_line(49,17+posy ,49,3+posy);
plot_line(49,3+posy ,46,0+posy);
plot_line(46,0+posy ,37,0+posy);

}
void printShift(uint16_t posy)
{
    posy*=lineHeight;
    plot_line(12,0+posy ,3,0+posy);
plot_line(3,0+posy ,0,3+posy);
plot_line(0,3+posy ,0,7+posy);
plot_line(0,7+posy ,11,13+posy);
plot_line(11,13+posy ,11,17+posy);
plot_line(11,17+posy ,8,20+posy);
plot_line(8,20+posy ,0,20+posy);
plot_line(17,0+posy ,17,20+posy);
plot_line(17,10+posy ,30,10+posy);
plot_line(30,0+posy ,30,20+posy);
plot_line(44,0+posy ,36,0+posy);
plot_line(36,0+posy ,34,2+posy);
plot_line(34,2+posy ,34,20+posy);
plot_line(42,11+posy ,34,11+posy);
plot_line(56,0+posy ,56,20+posy);
plot_line(62,0+posy ,50,0+posy);


}
void printCtrl(uint16_t posy)
{
    posy*=lineHeight;
    plot_line(12,2+posy ,10,0+posy);
plot_line(10,0+posy ,4,0+posy);
plot_line(4,0+posy ,0,3+posy);
plot_line(0,3+posy ,0,16+posy);
plot_line(0,16+posy ,3,20+posy);
plot_line(3,20+posy ,10,20+posy);
plot_line(10,20+posy ,12,17+posy);
plot_line(23,0+posy ,23,20+posy);
plot_line(29,0+posy ,17,0+posy);
plot_line(45,20+posy ,42,11+posy);
plot_line(34,20+posy ,34,0+posy);
plot_line(34,0+posy ,43,0+posy);
plot_line(43,0+posy ,45,2+posy);
plot_line(45,2+posy ,45,8+posy);
plot_line(45,8+posy ,43,11+posy);
plot_line(43,11+posy ,34,11+posy);
plot_line(50,0+posy ,50,20+posy);
plot_line(50,20+posy ,60,20+posy);

}

void printNav(uint16_t posy)
{
    posy*=lineHeight;
    plot_line(0,20+posy ,0,0+posy);
plot_line(0,0+posy ,3,0+posy);
plot_line(3,0+posy ,11,20+posy);
plot_line(11,20+posy ,13,20+posy);
plot_line(13,20+posy ,13,0+posy);
plot_line(31,13+posy ,20,13+posy);
plot_line(17,20+posy ,24,0+posy);
plot_line(24,0+posy ,26,0+posy);
plot_line(26,0+posy ,33,20+posy);
plot_line(35,0+posy ,41,20+posy);
plot_line(41,20+posy ,44,20+posy);
plot_line(44,20+posy ,50,0+posy);

}

void printAlt(uint16_t posy)
{
    posy*=lineHeight;
plot_line(13,13+posy ,2,13+posy);
plot_line(0,20+posy ,7,0+posy);
plot_line(7,0+posy ,9,0+posy);
plot_line(9,0+posy ,15,20+posy);
plot_line(18,0+posy ,18,20+posy);
plot_line(18,20+posy ,28,20+posy);
plot_line(40,0+posy ,40,20+posy);
plot_line(46,0+posy ,34,0+posy);

}


void printMouse(uint16_t posy)
{
    posy*=lineHeight;
    plot_line(0,16.38+posy ,0,0.38+posy);
plot_line(0,0.38+posy ,7,16.38+posy);
plot_line(7,16.38+posy ,7,16.38+posy);
plot_line(7,16.38+posy ,14,0.38+posy);
plot_line(14,0.38+posy ,14,16.38+posy);
plot_line(15,2.38+posy ,18,0.38+posy);
plot_line(18,0.38+posy ,24,0.38+posy);
plot_line(24,0.38+posy ,27,2.38+posy);
plot_line(27,2.38+posy ,27,13.38+posy);
plot_line(27,13.38+posy ,24,16.38+posy);
plot_line(24,16.38+posy ,18,16.38+posy);
plot_line(18,16.38+posy ,15,13.38+posy);
plot_line(15,13.38+posy ,15,2.38+posy);
plot_line(30,0.38+posy ,30,14.38+posy);
plot_line(30,14.38+posy ,32,16.38+posy);
plot_line(32,16.38+posy ,38,16.38+posy);
plot_line(38,16.38+posy ,40,14.38+posy);
plot_line(40,14.38+posy ,40,0.38+posy);
plot_line(53,0.38+posy ,46,0.38+posy);
plot_line(46,0.38+posy ,44,3.38+posy);
plot_line(44,3.38+posy ,44,5.38+posy);
plot_line(44,5.38+posy ,53,11.38+posy);
plot_line(53,11.38+posy ,53,14.38+posy);
plot_line(53,14.38+posy ,50,16.38+posy);
plot_line(50,16.38+posy ,44,16.38+posy);
plot_line(64,8.38+posy ,57,8.38+posy);
plot_line(66,0.38+posy ,59,0.38+posy);
plot_line(59,0.38+posy ,57,2.38+posy);
plot_line(57,2.38+posy ,57,14.38+posy);
plot_line(57,14.38+posy ,59,16.38+posy);
plot_line(59,16.38+posy ,66,16.38+posy);

}

bool doScroll=false;

uint16_t lastPosy=0;
#ifdef USE_I2C
bool oled_task_user(void) {
    oled_clear();

    uint8_t posy=0;
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_P(PSTR("\n"), false);
            break;
        case _MYSTUFF:
            //oled_write_P(PSTR("NAV\n"), false);
            printNav(posy++);
            break;
        case _OSM:
            oled_write_P(PSTR("OSM\n"), false);
            break;
        case _MOUSE:
            if(!doScroll)lastScroll=timer_read();
            doScroll=true;
            printMouse(posy++);
            break;
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        default:
            break;
    }

  if (get_highest_layer(layer_state)!=_MOUSE) doScroll=false;

    if(get_mods() & MOD_MASK_SHIFT) printShift(posy++); //oled_write_P(PSTR("SHIFT "), false);
    if(get_mods() & MOD_MASK_GUI) printCmd(posy++);//oled_write_P(PSTR("CMD "), true);
    if(get_mods() & MOD_MASK_ALT) printAlt(posy++);//oled_write_P(PSTR("ALT "), false);
    if(get_mods() & MOD_MASK_CTRL) printCtrl(posy++);//oled_write_P(PSTR("CTRL "), false);

    //oled_write_P(PSTR("\n"), false);

    if(get_oneshot_mods() & MOD_MASK_SHIFT) oled_write_P(PSTR("SHIFT... "), false);
    if(get_oneshot_mods() & MOD_MASK_GUI) oled_write_P(PSTR("CMD... "), false);
    if(get_oneshot_mods() & MOD_MASK_ALT) oled_write_P(PSTR("ALT... "), false);
    if(get_oneshot_mods() & MOD_MASK_CTRL) printCtrl(posy++);//oled_write_P(PSTR("CTRL... "), false);

   // oled_write_P(PSTR("\n"), false);
   // oled_write_P(PSTR("\n"), false);

//uint16_t t=(timer_read()/100)%15;
//for(int i=0;i<100;i++)
//plot_line(i+t,0,i,128-t);

    //plot_line(0,0,64,128);

    if(lastPosy!=posy)
        oled_render_dirty(true);

    lastPosy=posy;




    return true;
}
#endif

report_mouse_t pointing_device_task_combined_user(report_mouse_t r1,report_mouse_t mouse_report)
{
    if(doScroll)
    {
        if(timer_read()-lastScroll>30)
        {
            lastScroll=timer_read();

            if(mouse_report.y>2)mouse_report.v=-2;
            if(mouse_report.y<-2)mouse_report.v=2;
        }
        else
        {
        }
        mouse_report.x=0;
        mouse_report.y=0;
    }

    return mouse_report;
}
/*
void trackball_set_rgbw(uint8_t red, uint8_t green, uint8_t blue, uint8_t white) {
    uint8_t data[] = {0x00, red, green, blue, white};
    i2c_transmit(TRACKBALL_ADDRESS << 1, data, sizeof(data), 5000);
}
*/


uint8_t rgbR=0;
uint8_t rgbG=0;
uint8_t rgbB=0;

//layer_state_t layer_state_set_user(layer_state_t state)
bool rgb_matrix_indicators_kb(void)
{
    //pimoroni_trackball_set_rgbw(0,0,255,0);

    for (uint8_t i = led_min; i < led_max; i++)
    {
        rgb_matrix_set_color(i, rgbR,rgbG,rgbB);
    }
    //rgb_matrix_set_color_all(rgbR,rgbG,rgbB);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    switch (get_highest_layer(state)) {
        case 0:
            rgbR=0;
            rgbG=0;
            rgbB=0;
            rgb_matrix_sethsv_noeeprom(HSV_OFF);
            break;
        case 1:
            rgbR=0;
            rgbG=130;
            rgbB=250;
            break;
        case 2:
            rgbR=255;
            rgbG=0;
            rgbB=0;
            break;
        case 3:
            rgbR=255;
            rgbG=0;
            rgbB=255;
            break;
        default: // for any other layers, or the default layer
            break;
    }

    bool caps = host_keyboard_led_state().caps_lock;

    if(caps)
    {
        //rgblight_setrgb(RGB_GREEN);
    }

    return state;
}
bool process_record_user(uint16_t keycode, keyrecord_t* record)
{

    if (record->event.pressed)
    {
        switch (keycode)
        {
            case VIM_CMD:
                tap_code(KC_ESC);
                SEND_STRING(":");
                return false;
        }
    }
    return true;

}

/*
void keyboard_post_init_user(void) {
    //rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    //rgb_matrix_sethsv_noeeprom(HSV_OFF);
}
*/
bool encoder_update_user(uint8_t index, bool clockwise) {



//    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
  //  }
    return false;
}
//#endif
// DELETE THIS LINE TO UNCOMMENT (2/2)
// o

#ifdef USE_I2C
#ifdef SCAN_I2C
uint16_t scan_timer = 0;

void do_scan(void) {
    uint8_t nDevices = 0;

    dprintf("Scanning...\n");

    for (uint8_t address = 1; address < 127; address++) {
        // The i2c_scanner uses the return value of
        // i2c_ping_address to see if a device did acknowledge to the address.
        i2c_status_t error = i2c_ping_address(address << 1, 50);
        if (error == I2C_STATUS_SUCCESS) {
            dprintf("  I2C device found at address 0x%02X\n", address);
            nDevices++;
        } else {
            // dprintf("  Unknown error (%u) at address 0x%02X\n", error, address);
        }
    }

    if (nDevices == 0)
        dprintf("No I2C devices found\n");
    else
        dprintf("done\n");
}
void matrix_scan_user(void) {
    if (timer_elapsed(scan_timer) > 5000) {
        do_scan();
        scan_timer = timer_read();
    }
}
#endif
#endif

void keyboard_post_init_user(void) {
    debug_enable = true;

    debug_matrix = true;
    #ifdef USE_I2C
        #ifdef SCAN_I2C
    i2c_init();
             scan_timer = timer _read();
        #endif
    #endif

}
