//
//  ALT
//  CMD
// CTRL

#include QMK_KEYBOARD_H


const uint16_t PROGMEM combo_boot[] = {KC_Z, KC_SLSH, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_boot, QK_BOOT),
};

enum custom_keycodes {
    VIM_CMD = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        XXXXXXX,KC_Q,  KC_W,   KC_F, KC_P,   KC_B,      KC_J,     KC_L,  KC_U,    KC_Y,   KC_BSPC, XXXXXXX,
        XXXXXXX,KC_A,  KC_S,   KC_R, KC_T,   KC_G,                     KC_M,     KC_N,  KC_E,    KC_I,   KC_O, XXXXXXX,
        XXXXXXX,KC_Z,  KC_X,   KC_C, MT(MOD_LCTL,KC_D),  MT(MOD_LALT,KC_V),         MT(MOD_LALT,KC_K), MT(MOD_LCTL,KC_H), KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                MT(MOD_LSFT,KC_ESC),MT(MOD_LSFT,KC_ESC),MT(MOD_LGUI,KC_ENTER),XXXXXXX, XXXXXXX,      LT(1,KC_SPACE),LT(2,KC_TAB),LT(2,KC_TAB)
    ),

    [1] = LAYOUT(
        XXXXXXX, HYPR(KC_0), HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4),      HYPR(KC_5),  KC_HOME,       KC_UP,    KC_END,   KC_DEL, XXXXXXX,
        XXXXXXX, XXXXXXX,    HYPR(KC_LEFT),HYPR(KC_SPACE),HYPR(KC_RIGHT),     VIM_CMD,                 KC_ESC,    KC_LEFT,       KC_DOWN,  KC_RIGHT, KC_ENTER, XXXXXXX,
        XXXXXXX, QK_BOOT,    XXXXXXX,    XXXXXXX,    LGUI(KC_Z),S(LGUI(KC_Z)),                KC_SPACE, KC_MPLY, KC_VOLD,  KC_VOLU,  KC_MPLY, XXXXXXX,
                          _______, _______,  _______,               _______, _______,_______, _______,_______
    ),
    /*
     *      1 2 3 4 5   6 7 8 9 0
     *      ~ [ { ( -   + ) } ] |
     *      \ ` ' " _   = : ; . /
     *
     *      !@#$%    ^&*()
     */
    [2] = LAYOUT(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,       KC_5,            KC_6,     KC_7,    KC_8,    KC_9,    KC_0,XXXXXXX,
        XXXXXXX, KC_TILD, KC_LBRC, KC_LCBR, KC_LPRN,    KC_MINUS,                KC_PLUS,  KC_RPRN, KC_RCBR, KC_RBRC, KC_PIPE,XXXXXXX,
        XXXXXXX, KC_BSLS, KC_GRV,  KC_QUOT, S(KC_QUOT), S(KC_MINUS),             KC_EQUAL, KC_COLN, KC_SCLN, KC_DOT,  KC_BSLS,XXXXXXX,
                           _______, _______,   _______,                 _______,  _______, _______ , _______,_______    ),
    // [0] = LAYOUT(
    //     KC_ESC,  KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,             KC_J,     KC_L,  KC_U,    KC_Y,   KC_SCLN, KC_BSPC,
    //     KC_TAB,  KC_A,   KC_S,   KC_R,   KC_T,   KC_G,             KC_M,     KC_N,  KC_E,    KC_I,   KC_O,    KC_ENTER,
    //     MO(5), MT(MOD_LALT,KC_Z),KC_X,LT(3,KC_C),KC_D,   MT(MOD_LCTL,KC_V),             MT(MOD_LCTL,KC_K),     KC_H,  LT(3,KC_COMM),KC_DOT,MT(MOD_LALT, KC_SLSH), MO(5),
    //             MT(MOD_LCTL,KC_ESC),KC_LSFT,MT(MOD_LGUI,KC_ESC),XXXXXXX,XXXXXXX,       LT(1,KC_SPACE),MO(2),LT(3,KC_TAB)
    //                  // XXXXXXX,KC_LSFT, KC_LGUI,KC_ESC,    KC_SPACE, MO(1), LT(2,KC_TAB),   XXXXXXX
    // ),

    // // KC_TAB, KC_A,   KC_S,   KC_R,   KC_T,   KC_G,             KC_M,     KC_N,  KC_E,    KC_I,   KC_O,    KC_ENTER,
    //  // MO(4),              KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,             KC_K,     KC_H,  KC_COMM, KC_DOT, KC_SLSH, MO(4),

    // [1] = LAYOUT(
    //     XXXXXXX,XXXXXXX, HYPR(KC_F), HYPR(KC_C), HYPR(KC_T), HYPR(KC_D),               KC_SPACE,   KC_HOME,    KC_UP,   KC_END,   XXXXXXX, KC_DEL,
    //     XXXXXXX, XXXXXXX, KC_PGDN, S(KC_TAB),  KC_TAB, VIM_CMD,       KC_ESC,   KC_LEFT,      KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
    //     _______, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,   XXXXXXX,    LGUI(KC_Z), S(LGUI(KC_Z)),  KC_VOLD,       KC_VOLU,       KC_MPLY, _______,
    //                       _______, _______,    _______,MO(5),     _______, _______, _______,_______
    // ),
    // [2] = LAYOUT(
    //     KC_0,    KC_1,    KC_2,        KC_3,    KC_4,       KC_5,            KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    _______,
    //     _______, KC_TILD, KC_LBRC,     KC_LCBR, KC_LPRN,    KC_MINUS,        KC_PLUS,  KC_RPRN, KC_RCBR, KC_RBRC, KC_PIPE, _______,
    //     _______, KC_BSLS, KC_GRV,      KC_QUOT, S(KC_QUOT), S(KC_MINUS),     KC_EQUAL, KC_COLN, KC_SCLN, KC_DOT,  KC_BSLS, _______,
    //                           _______, MO(4), _______, _______,         _______, _______, _______, _______

    // ),

    // [3] = LAYOUT(
    //     _______,        LGUI(KC_Q), LGUI(KC_W), HYPR(KC_F), HYPR(KC_R), HYPR(KC_T),   HYPR(KC_J), HYPR(KC_L),    HYPR(KC_UP) ,  HYPR(KC_O),    HYPR(KC_P),  _______,
    //     LGUI(KC_TILDE), HYPR(KC_A), HYPR(KC_S), HYPR(KC_R), HYPR(KC_T), HYPR(KC_G),   HYPR(KC_M), HYPR(KC_LEFT), HYPR(KC_DOWN), HYPR(KC_RIGHT), _______, _______,
    //     _______,        HYPR(KC_Z), HYPR(KC_X), HYPR(KC_C), HYPR(KC_D), HYPR(KC_V),   HYPR(KC_K), HYPR(KC_H) ,   KC_VOLD,       KC_VOLU,       KC_MPLY, _______,
    //                       _______, _______, _______, _______,             HYPR(KC_SPACE), _______, _______, _______
    // ),

    // [4] = LAYOUT(
    //     _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),     S(KC_6),  S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
    //     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    _______,
    //     XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   _______,
    //                       _______, _______, _______, KC_F11,     KC_F12, _______, _______, _______
    // ),

    // [5] = LAYOUT(
    //     QK_BOOT, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
    //     QK_BOOT, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, QK_BOOT,
    //                       _______, _______, _______, _______,      _______, _______, _______, _______
    // ),
};




const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
         'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R','R', 'R',
         'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R','R', 'R',
         'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R','R', 'R',
                       '*', '*', '*',  '*','*', '*', '*', '*'
    );

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

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LGUI, KC_ENTER): return true; // Immediately select the hold action when another key is pressed.
        case MT(MOD_LSFT, KC_ESC): return true; // Immediately select the hold action when another key is pressed.
        default: return false; // Do not select the hold action when another key is pressed.
    }
}
