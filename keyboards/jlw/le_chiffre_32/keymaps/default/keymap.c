#include "features/achordion.h"
#include "print.h"

// Copyright 2023 jlw
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define HM_A	LGUI_T(KC_A)
#define HM_R	LALT_T(KC_R)
#define HM_S	LCTL_T(KC_S)

#define HM_E	RCTL_T(KC_E)
#define HM_I	LALT_T(KC_I)
#define HM_O	LGUI_T(KC_O)


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

void housekeeping_task_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
    if (tap_hold_record->event.key.row  >= 2) { return true; }
//    uprintf("%i jojo\n",tap_hold_record->event.key.row);


  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}


#define HO_Z MT(MOD_LSFT,KC_Z)
#define HO_SLSH MT(MOD_RSFT,KC_SLSH)

#define HO_A MT(MOD_LCTL,KC_A)
#define HO_S MT(MOD_LALT,KC_S)
#define HO_R HYPR_T(KC_R)
#define HO_T MT(MOD_LGUI,KC_T)

#define HO_N MT(MOD_RGUI,KC_N)
#define HO_E HYPR_T(KC_E)
#define HO_I MT(MOD_RALT,KC_I)
#define HO_O MT(MOD_RCTL,KC_O)


#define ESCMD MT(MOD_LGUI,KC_ESC)
#define ENTCTL MT(MOD_LCTL,KC_ENTER)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *
     * HOLD:
     * ┌────┬────┬────┬────┬────┐          ┌────┬────┬────┬────┬────┐
     * │    │    │    │    │    │          │    │    │    │    │    │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │CTRL│ALT │HYPR│GUI │    │          │    │GUI │HYPR│ALT │CTRL│
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │SHFT│    │    │    │    │          │    │    │    │    │SHFT│
     * └────┴────┴────┼────┼────┼────┐┌────┼────┼────┼────┴────┴────┘
     *                │NAV │CMD │    ││    │BRAC│NUMS│
     *                └────┴────┴────┘└────┴────┴────┘
     *
     */
    [0] = LAYOUT_3thumb(
    //  #######  #######  #######  #######  #######            #######  #######  #######  #######  #######
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_MPLY,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSPC,
        HO_A,    HO_S,    HO_R,    HO_T,    KC_G,              KC_M,    HO_N,    HO_E,    HO_I,    HO_O,
        HO_Z,    KC_X,    KC_C,    KC_D,    KC_V,              KC_K,    KC_H,    KC_COMM, KC_DOT,  HO_SLSH,
                          MO(3), ESCMD,   KC_BSPC,             KC_SPACE,LT(5,KC_ENTER),  MO(2)
    //  #######  #######  #######  #######  #######     #######  #######  #######  #######  #######
    ),
    [1] = LAYOUT_3thumb(
    //  #######  #######  #######  #######  #######           #######  #######  #######  #######  #######
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   _______,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        KC_A,    KC_S,    KC_R,    KC_T,    KC_G,             KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,             KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                          _______, _______, _______,          _______, _______, _______
    //  #######  #######  #######  #######  #######           #######  #######  #######  #######  #######
    ),
    /*
     * NAV
     *
     * ┌────┬────┬───┬────┬────┐          ┌────┬────┬────┬────┬────┐
     * │ESC │ (  │ ) │SC  │SC  │          │    │    │    │    │    │
     * │    │    │   │TAB │TAB │          │    │    │ UP │    │DEL │
     * ├────┼────┼───┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │TAB │ [  │ ] │STAB│TAB │          │UP  │ <- │DOWN│ -> │ENTR│
     * ├────┼────┼───┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │    │    │   │SCMD│CMD │          │    │    │    │    │    │
     * │SHFT│ {  │ } │TAB │TAB │          │DN  │ M1 │ M2 │ M3 │SHFT│
     * └────┴────┴───┼────┼────┼────┐┌────┼────┼────┼────┴────┴────┘
     *               │HYPR│    │    ││    │    │XXXX│
     *               └────┴────┴────┘└────┴────┴────┘
     *
     */
    [2] = LAYOUT_3thumb(
    //  #######  #######        #######        #######             #######         ######    ########  #######   ########  ########
        KC_ESC,  LSFT(KC_9),    LSFT(KC_0),     LCTL(LSFT(KC_TAB)), LCTL(KC_TAB),  _______,   _______,  _______,  KC_UP,    _______,  KC_DEL,
        KC_TAB,  KC_LBRC,       KC_RBRC,       LSFT(KC_TAB),       KC_TAB,                    KC_WH_U,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_ENTER,
      MOD_LSFT, LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(LGUI(KC_TAB)), LGUI(KC_TAB),               KC_WH_D,  KC_BTN1,  KC_BTN2,  KC_BTN3, MOD_RSFT,
                        KC_HYPR, _______,       _______ ,                          _______,  _______,  _______
    //  #######  #######        #######        #######                             #######   #######   #######   #######  #######  #######
    ),

    /*
     * NUMS
     *
     * ┌────┬────┬────┬────┬────┐          ┌────┬────┬────┬────┬────┐
     * │ 1  │ 2  │ 3  │ 4  │ 5  │          │ 6  │ 7  │ 8  │ 9  │ 0  │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │ !  │ @  │ #  │ $  │ %  │          │ ^  │ &  │ *  │ :  │ ;  │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │ \  │ |  │ "  │ '  │ `  │          │ ~  │ -  │ +  │ =  │ _  │
     * └────┴────┴────┼────┼────┼────┐┌────┼────┼────┼────┴────┴────┘
     *                │XXXX│    │    ││    │VIM │BRAC│
     *                └────┴────┴────┘└────┴────┴────┘
     */
    [3] = LAYOUT_3thumb(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     _______,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5), LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),KC_SCLN,LSFT(KC_SCLN),
        KC_BACKSLASH, LSFT(KC_BACKSLASH), LSFT(KC_QUOTE), KC_QUOTE, KC_GRAVE,    LSFT(KC_GRAVE), KC_MINUS, LSFT(KC_EQUAL), KC_EQUAL, LSFT(KC_MINUS),
                          _______, _______, _______,    _______,MO(4), MO(5)
    ),

    //
    //  VIM SHORTCUTS
    //
    [4] = LAYOUT_3thumb(
    //  #######  #######  #######    #######  #######     #######  #######  #######  #######  #######
        _______, _______, _______,  _______, _______,   QK_BOOT, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______,  _______, _______,    _______, _______, _______, _______, _______,
        _______, _______, _______,  _______, _______,    _______, _______, _______, _______, _______,
                          _______,   _______, _______,    _______, _______, _______
    //  #######  #######  #######  #######  #######     #######  #######  #######  #######  #######
    ),



    /*
     * BRACKETS
     *
     * ┌────┬────┬────┬────┬────┐          ┌────┬────┬────┬────┬────┐
     * │F1  │F2  │F3  │F4  │F5  │          │F6  │F7  │F8  │F9  │F10 │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │ (  │ [  │ {  │ =  │ -  │          │ +  │ :  │ }  │ ]  │ )  │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │ |  │`   │ '  │ "  │ _  │          │    │ =  │ ~  │    │ \  │
     * └────┴────┴────┼────┼────┼────┐┌────┼────┼────┼────┴────┴────┘
     *                │XXXX│    │F11 ││F12 │    │XXXX│
     *                └────┴────┴────┘└────┴────┴────┘
     */
    [5] = LAYOUT_3thumb(
    //  #######       #######  #######  #######  #######   #######        #######          #######  #######  #######
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        LSFT(KC_9),   KC_LBRC, LSFT(KC_LBRC), KC_EQUAL,  KC_MINUS,        LSFT(KC_EQUAL),  LSFT(KC_SCLN),    LSFT(KC_RBRC),  KC_RBRC,LSFT(KC_0),
        KC_BACKSLASH, KC_GRAVE,LSFT(KC_QUOTE), KC_QUOTE, LSFT(KC_MINUS),  _______ ,        KC_EQUAL,         LSFT(KC_GRAVE), _______, KC_BACKSLASH,
                          _______, _______, KC_F11,    KC_F12, _______, _______
    //  #######  #######  #######  #######  #######     #######  #######  #######  #######  #######
    ),
    /*
     * F KEYS
     *
     * ┌────┬────┬────┬────┬────┐          ┌────┬────┬────┬────┬────┐
     * │F1  │F2  │F3  │F4  │F5  │          │    │    │    │    │    │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │F6  │F7  │F8  │F9  │F10 │          │    │    │    │    │    │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │F11 │F12 │    │    │    │          │    │    │    │    │    │
     * └────┴────┴────┼────┼────┼────┐┌────┼────┼────┼────┴────┴────┘
     *                │XXXX│    │    ││    │    │XXXX│
     *                └────┴────┴────┘└────┴────┴────┘
     */
    [6] = LAYOUT_3thumb(
    //  #######  #######  #######  #######  #######     #######  #######  #######  #######  #######
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    _______,  _______, _______, _______, _______, _______,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,     _______, _______, _______, _______, _______,
        KC_F11,  KC_F12,  _______, _______, _______,    _______, _______, _______, _______, _______,
                          _______, _______, _______,    _______, _______, _______
    //  #######  #######  #######  #######  #######     #######  #######  #######  #######  #######
    ),
};




















bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_BSPC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// Encoder Map
#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [1] =   { ENCODER_CCW_CW(_______, _______) },
        [2] =   { ENCODER_CCW_CW(_______, _______) },
        [3] =   { ENCODER_CCW_CW(_______, _______) },
        [4] =   { ENCODER_CCW_CW(_______, _______) },
        [5] =   { ENCODER_CCW_CW(_______, _______) },
        [6] =   { ENCODER_CCW_CW(_______, _______) }
    };
#endif

// Combos disabled for Vial
#ifdef COMBO_ENABLE
    const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W,    COMBO_END};
    const uint16_t PROGMEM combo_del[] = {KC_Y, KC_QUOT, COMBO_END};
    combo_t key_combos[] = {
        COMBO(combo_esc, KC_ESC),
        COMBO(combo_del, KC_DEL),
    };
#endif

// RGB settings for indicator lights
// Layer and Mods indicator
#define LED_CENTER_TOP 1
#define LED_CENTER_BOTTOM 0

#define LAYER_R layer_colors[layer][0] *  RGB_INDICATOR_BRIGHTNESS / 255
#define LAYER_G layer_colors[layer][1] *  RGB_INDICATOR_BRIGHTNESS / 255
#define LAYER_B layer_colors[layer][2] *  RGB_INDICATOR_BRIGHTNESS / 255

#define MODS_ACTIVE(mods) \
    ((get_mods()|get_oneshot_mods()) & MOD_MASK_##mods ? RGB_INDICATOR_BRIGHTNESS:0)
#define SHIFT_ACTIVE (get_mods() & MOD_MASK_SHIFT ? RGB_INDICATOR_BRIGHTNESS/4:0)
#define MODS_R MODS_ACTIVE(CTRL) + SHIFT_ACTIVE
#define MODS_G MODS_ACTIVE(GUI) + SHIFT_ACTIVE
#define MODS_B MODS_ACTIVE(ALT) + SHIFT_ACTIVE

const uint8_t PROGMEM layer_colors[][3] = {
    {RGB_OFF},
    {RGB_RED},
    {RGB_GREEN},
    {RGB_BLUE},
    {RGB_YELLOW},
    {RGB_PURPLE},
    {RGB_PINK},
    {RGB_TEAL}
};

void set_rgb_matrix_indicators(uint8_t led_min, uint8_t led_max) {
    #if defined(RGB_LAYER_INDICATOR_ENABLE)
    int layer = get_highest_layer(layer_state|default_layer_state);
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_TOP, LAYER_R, LAYER_G, LAYER_B);
    /* uprintf("layer RGB: (%u, %u, %u)\n", LAYER_R, LAYER_G, LAYER_B); */
    #else
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_TOP, 0, 0, 0);
    #endif

    #if defined(RGB_MODS_INDICATOR_ENABLE)
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, MODS_R, MODS_G, MODS_B);
    /* uprintf("mod RGB: (%u, %u, %u)\n", MODS_R, MODS_G, MODS_B); */
    #else
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, 0, 0, 0);
    #endif
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    set_rgb_matrix_indicators(led_min, led_max);
    return false;
}
