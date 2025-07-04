#include QMK_KEYBOARD_H

const uint16_t PROGMEM combo_boot[] = {KC_Z, KC_SLSH, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_boot, QK_BOOT),
};

enum custom_keycodes {
    VIM_CMD = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_3thumb(
        LT(3,KC_Q),  KC_W,   KC_F, KC_P,   KC_B,       KC_MPLY,      KC_J,     KC_L,  KC_U,    KC_Y,   KC_BSPC,
        KC_A,  KC_S,   KC_R, KC_T,   KC_G,                     KC_M,     KC_N,  KC_E,    KC_I,   KC_O,
        KC_Z,  KC_X,   KC_C, MT(MOD_LCTL,KC_D),  MT(MOD_LALT,KC_V),         MT(MOD_LALT,KC_K), MT(MOD_LCTL,KC_H), KC_COMM, KC_DOT,  LT(4,KC_SLSH),
                MT(MOD_LSFT,KC_ESC),MT(MOD_LSFT,KC_ESC),MT(MOD_LGUI,KC_ENTER),       LT(1,KC_SPACE),LT(2,KC_TAB),LT(2,KC_TAB)
    ),

    [1] = LAYOUT_3thumb(
         HYPR(KC_0), HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4),   KC_MPLY,   HYPR(KC_5),  KC_HOME,       KC_UP,    KC_END,   KC_DEL,
         S(KC_TAB),KC_TAB,KC_ESC,KC_ENTER,     VIM_CMD,                 KC_PGUP,    KC_LEFT,       KC_DOWN,  KC_RIGHT, KC_ENTER,
         XXXXXXX,    XXXXXXX,    XXXXXXX,    S(LGUI(KC_Z)),LGUI(KC_Z),                KC_PGDN, KC_MPLY, KC_VOLD,  KC_VOLU,  KC_MPLY,
                          _______, _______,  _______,               XXXXXXX, MS_BTN1, _______
    ),
    /*
     *      1 2 3 4 5   6 7 8 9 0
     *      ~ [ { ( -   + ) } ] |
     *      \ ` ' " _   = : ; . /
     *
     *      !@#$%    ^&*()
     */
    [2] = LAYOUT_3thumb(
         KC_1,    KC_2,    KC_3,    KC_4,       KC_5,      KC_MPLY,      KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
         KC_TILD, KC_LBRC, KC_LCBR, KC_LPRN,    KC_MINUS,                KC_PLUS,  KC_RPRN, KC_RCBR, KC_RBRC, KC_PIPE,
         KC_BSLS, KC_GRV,  KC_QUOT, S(KC_QUOT), S(KC_MINUS),             KC_EQUAL, KC_COLN, KC_SCLN, KC_DOT,  KC_BSLS,
                           _______, _______,   _______,                 MS_BTN2,  XXXXXXX, _______
    ),

    [3] = LAYOUT_3thumb(
        _______, _______, _______, _______, _______,   _______,   _______, _______, MS_UP, _______, QK_BOOT,
        _______, _______, _______, MS_BTN1, MS_BTN2,              _______, MS_LEFT, MS_DOWN, MS_RGHT, _______,
        _______, _______, _______, MS_BTN3, _______,              _______, _______, _______, _______, _______,
                          _______, _______, _______,              _______, _______, _______
      ),
    [4] = LAYOUT_3thumb(
        HYPR(KC_Q), HYPR(KC_W), HYPR(KC_F), HYPR(KC_R), HYPR(KC_T),   KC_MPLY,HYPR(KC_J), HYPR(KC_L),    HYPR(KC_SPACE) ,  HYPR(KC_Y),    _______,
        HYPR(KC_A), HYPR(KC_S), HYPR(KC_R), HYPR(KC_T), HYPR(KC_G),           HYPR(KC_M), HYPR(KC_LEFT), HYPR(KC_DOWN), HYPR(KC_RIGHT), HYPR(KC_O),
        QK_BOOT, HYPR(KC_X), HYPR(KC_C), HYPR(KC_D), HYPR(KC_V),           HYPR(KC_K), HYPR(KC_H) ,   HYPR(KC_COMM), HYPR(KC_DOT), HYPR(KC_ENTER),
                           _______,_______, _______,                         HYPR(KC_SPACE),  _______, _______
    ),

    // [4] = LAYOUT_3thumb(
    //      S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),    KC_MPLY,    S(KC_6),  S(KC_7), S(KC_8), S(KC_9), S(KC_0),
    //      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
    //      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    //                       _______, _______, _______,                  _______, _______, _______
    // ),

    // [5] = LAYOUT_3thumb(
    //     QK_BOOT, _______, _______, _______, _______,   KC_MPLY,   _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______,
    //                       _______, _______, _______,              _______, _______, _______
    //   ),
    // [6] = LAYOUT_3thumb(
    // KC_Q,  KC_W,   KC_F, KC_P,  KC_B,       KC_MPLY,      KC_J,   KC_L,    KC_U,    KC_Y,   KC_BSPC,
    // KC_A,  KC_S,   KC_R, KC_T,  KC_G,                     KC_M,   KC_N,    KC_E,    KC_I,   KC_O,
    // KC_Z,  KC_X,   KC_C, KC_D,  KC_V,         KC_K,       KC_H,   KC_COMM, KC_DOT,  KC_ENTER,
    //                       KC_LSFT, KC_LSFT, KC_ESC,              KC_SPACE, MO(1), MO(2)
    //   )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_3thumb(
         '*', 'L', 'L', 'L', 'L','*',  'R', 'R', 'R', 'R', 'R',
         'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
         'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',  '*', '*', '*'
    );

// Encoder Map
#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [1] =   { ENCODER_CCW_CW(_______, _______) },
        [2] =   { ENCODER_CCW_CW(_______, _______) },
        [3] =   { ENCODER_CCW_CW(_______, _______) },
        [4] =   { ENCODER_CCW_CW(_______, _______) },
        // [5] =   { ENCODER_CCW_CW(_______, _______) },
        // [6] =   { ENCODER_CCW_CW(_______, _______) }
   };
#endif

// led_config_t g_led_config = {
//     // Key Matrix to LED Index
//     {
//          {9,     9,    9,   9,    9,            3, 3, 3,    3,     3 },
//          {10,    10,   10,  10,   10,           2, 2, 2,    2,     2 },
//          {8,     8,    8,   8,    8,            4, 4, 4,    4,     4 },
//          {NO_LED, NO_LED, 7, NO_LED,      6,    6, 6, 5, NO_LED, NO_LED, }
//     },
//     // LED Index to Physical Positon
//     {
//         { 128, 40 },
//         { 128, 30 },
//         { 166, 0 },
//         { 255, 0 },
//         { 255, 48 },
//         { 178, 64 },
//         { 128, 64 },
//         { 77, 64 },
//         { 0, 48 },
//         { 0, 0 },
//         { 115, 0 }
//     },
//     //  LED Index to Flag
//     //  https://docs.qmk.fm/#/feature_rgb_matrix?id=flags
//     { 8, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2 }
// };
// RGB settings for indicator lights
// Layer and Mods indicator
// #define LED_CENTER_TOP 1
// #define LED_CENTER_BOTTOM 0


// #define LAYER_R layer_colors[layer][0] *  RGB_INDICATOR_BRIGHTNESS / 255
// #define LAYER_G layer_colors[layer][1] *  RGB_INDICATOR_BRIGHTNESS / 255
// #define LAYER_B layer_colors[layer][2] *  RGB_INDICATOR_BRIGHTNESS / 255

// #define MODS_ACTIVE(mods)  ((get_mods()|get_oneshot_mods()) & MOD_MASK_##mods ? RGB_INDICATOR_BRIGHTNESS:0)
// #define SHIFT_ACTIVE (get_mods() & MOD_MASK_SHIFT ? RGB_INDICATOR_BRIGHTNESS/4:0)
// #define MODS_R MODS_ACTIVE(CTRL) + SHIFT_ACTIVE
// #define MODS_G MODS_ACTIVE(GUI) + SHIFT_ACTIVE
// #define MODS_B MODS_ACTIVE(ALT) + SHIFT_ACTIVE

// const uint8_t PROGMEM layer_colors[][3] = {
//     {RGB_OFF},
//     {RGB_RED},
//     {RGB_GREEN},
//     {RGB_BLUE},
//     {RGB_YELLOW},
//     {RGB_PURPLE},
//     {RGB_PINK},
//     {RGB_TEAL},
//     {RGB_TEAL}
// };

// void set_rgb_matrix_indicators(uint8_t led_min, uint8_t led_max) {
//     #if defined(RGB_LAYER_INDICATOR_ENABLE)
//     int layer = get_highest_layer(layer_state|default_layer_state);
//     RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_TOP, LAYER_R, LAYER_G, LAYER_B);
//     /* uprintf("layer RGB: (%u, %u, %u)\n", LAYER_R, LAYER_G, LAYER_B); */
//     #else
//     RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_TOP, 255, 0, 0);
//     #endif

//     #if defined(RGB_MODS_INDICATOR_ENABLE)
//     RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, MODS_R, MODS_G, MODS_B);
//     /* uprintf("mod RGB: (%u, %u, %u)\n", MODS_R, MODS_G, MODS_B); */
//     #else
//     RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, 0, 0, 0);
//     #endif
//     RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_TOP, 255, 0, 0);
//     RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, 255, 0, 0);
// }

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     set_rgb_matrix_indicators(led_min, led_max);
//     return false;
// }

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{

    if (record->event.pressed)
    {
        switch (keycode)
        {
            case VIM_CMD:
                tap_code(KC_ESC);
                SEND_STRING(":");
                // tap_code(KC_ENTER);
                return false;
        }
    }
    return true;
}

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LT(1, KC_SPACE):
//             return 100;


//         default:
//             return 499;
//     }
// }

#define IS_HOMEROW_MOD_TAP(kc) (              \
    IS_QK_MOD_TAP(kc)                      && \
    QK_MOD_TAP_GET_TAP_KEYCODE(kc) >= KC_A && \
    QK_MOD_TAP_GET_TAP_KEYCODE(kc) <= KC_Z    )

// Decision macro for preceding trigger key and typing interval
#define IS_TYPING(k) ( \
    ((uint8_t)(k) <= KC_Z ||(uint8_t)(k) == KC_SPC) && \
    (last_input_activity_elapsed() < QUICK_TAP_TERM)    )

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool     is_pressed[UINT8_MAX];
    static uint16_t prev_keycode;
    const  uint16_t tap_keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    if (record->event.pressed) {
        // Press the tap keycode if the tap-hold key follows the previous key swiftly
        if (IS_HOMEROW_MOD_TAP(keycode) && IS_TYPING(prev_keycode)) {
            is_pressed[tap_keycode] = true;
            record->keycode         = tap_keycode;
        }
        prev_keycode = keycode;
    }

    // Release the tap keycode if pressed
    else if (is_pressed[tap_keycode]) {
        is_pressed[tap_keycode] = false;
        record->keycode         = tap_keycode;
    }

    return true;
}



// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case MT(MOD_LGUI, KC_ENTER):
//             return 100;
//         default:
//             return TAPPING_TERM;
//     }
// }

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case LT(3, KC_Q): return true; // Immediately select the hold action when another key is pressed.
        case MT(MOD_LGUI, KC_ENTER): return true; // Immediately select the hold action when another key is pressed.
        case MT(MOD_LSFT, KC_ESC): return true; // Immediately select the hold action when another key is pressed.
        default: return false; // Do not select the hold action when another key is pressed.
    }
}


// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { switch(keycode) { case LT(1, KC_SPACE): return true; default: return false; } }

