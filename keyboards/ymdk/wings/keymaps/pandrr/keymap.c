/* Copyright 2021 alittlepeace
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

// pandur keymap

#include QMK_KEYBOARD_H
//#include "pointing_device.h"


void keyboard_post_init_user(void)
{
rgblight_disable_noeeprom();
}

bool led_update_user(led_t led_state)
{
    bool caps = host_keyboard_led_state().caps_lock;

    if(caps)
        {
            rgblight_enable_noeeprom();
            rgblight_setrgb(RGB_GREEN);
        }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t * record)
{

    if(keycode==KC_CAPS)
    {
        bool caps = host_keyboard_led_state().caps_lock;

        if (caps && !record->event.pressed)
        {
            // tap_code(KC_CAPS);

            rgblight_enable_noeeprom();
            rgblight_setrgb(RGB_PURPLE);
        }

        else if(caps)
        {
            rgblight_enable_noeeprom();
            rgblight_setrgb(RGB_GREEN);

        }
    }


    return true;
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    switch (get_highest_layer(state)) {
        case 1:
            rgblight_enable_noeeprom();
            rgblight_setrgb(RGB_RED);
            break;
        case 2:
            rgblight_enable_noeeprom();
            rgblight_setrgb(RGB_BLUE);
            break;
        case 3:
            rgblight_enable_noeeprom();
            rgblight_setrgb(RGB_PURPLE);
            break;
        case 4:
            rgblight_enable_noeeprom();
            rgblight_setrgb(RGB_GREEN);
            break;
        default: // for any other layers, or the default layer
            rgblight_disable_noeeprom();
            break;
    }

    bool caps = host_keyboard_led_state().caps_lock;

    if(caps)
    {
        rgblight_setrgb(RGB_GREEN);
    }


    return state;
}


#define HORO_G HYPR_T(KC_G)
#define HORO_S MT(MOD_LCTL,KC_S)
#define HORO_D MT(MOD_LALT,KC_D)
#define HORO_F MT(MOD_LGUI,KC_F)
#define HORO_A MT(MOD_LSFT,KC_A)


#define HORO_H HYPR_T(KC_H)
#define HORO_J MT(MOD_RGUI,KC_J)
#define HORO_K MT(MOD_RALT,KC_K)
#define HORO_L MT(MOD_RCTL,KC_L)
#define HORO_C MT(MOD_RSFT,KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ansi_split_bs(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_TILDE,     KC_BSPC,    TG(2),
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BACKSLASH,             TG(1),
    KC_LALT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                            KC_DELETE,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                    KC_UP,
    KC_LCTL,          KC_LGUI,          MO(4),  MO(3),          KC_SPC,           KC_HYPR,                           KC_LEFT, KC_DOWN, KC_RGHT
  ),

  // RED - QWERTY 
  [1] = LAYOUT_ansi_split_bs(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_TILDE,     KC_BSPC,    TG(2),
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BACKSLASH,             TG(1),
    KC_LALT, KC_A,    KC_S,    KC_R,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,                            KC_DELETE,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                    KC_UP,
    _______, _______,         _______, _______,          _______,          _______,                                          _______, _______, _______
  ),

  // BLUE GAMING QWERTY
  [2] = LAYOUT_ansi_split_bs(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F1,   KC_F7,  KC_F12,     KC_BSPC,       TG(2),
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BACKSLASH,             TG(1),
    KC_LALT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                            KC_DELETE,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                    KC_UP,
        _______,          MS_BTN1,          KC_SPACE,  MS_BTN2,         _______,          MS_BTN3,                             _______, _______, _______
  ),

  // MOUSE BUTTONS - purple
  [3] = LAYOUT_ansi_split_bs(
         _______,   KC_F1,   KC_F2,   KC_F3,        KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______, _______, QK_BOOT,
    LGUI(KC_TAB), _______, _______, _______,      _______, _______, _______, _______, KC_UP, _______, _______, _______, _______, _______,          _______,
         _______, _______, _______, _______,      _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______,                  _______,
         _______, _______, _______, _______,      _______,  KC_ESC, KC_COLN, _______, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP,  _______, _______,     KC_PGDN,
         _______,          _______,               _______, _______,          _______,          _______,                                 KC_HOME, KC_PGUP , KC_END
  ),


  // curor home row - green
  [4] = LAYOUT_ansi_split_bs(
         _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
         _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
         _______, _______, _______, _______,      _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,                   _______,
         _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______,                           _______,
         _______,          _______,               _______, _______,          _______,          _______,                                 KC_HOME, KC_PGUP , KC_END
  )


};
