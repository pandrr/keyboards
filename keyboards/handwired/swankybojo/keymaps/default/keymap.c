//
//  ALT
//  CMD
// CTRL

#include QMK_KEYBOARD_H


enum custom_keycodes {
    VIM_CMD = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_ESC,  KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,             KC_J,     KC_L,  KC_U,    KC_Y,   KC_SCLN, KC_BSPC,
        KC_TAB,  KC_A,   KC_S,   KC_R,   KC_T,   KC_G,             KC_M,     KC_N,  KC_E,    KC_I,   KC_O,    KC_ENTER,
        MO(5), MT(MOD_LALT,KC_Z),KC_X,LT(3,KC_C),KC_D,   MT(MOD_LCTL,KC_V),             MT(MOD_LCTL,KC_K),     KC_H,  LT(3,KC_COMM),KC_DOT,MT(MOD_LALT, KC_SLSH), MO(5),
                MT(MOD_LCTL,KC_ESC),KC_LSFT,MT(MOD_LGUI,KC_ESC),XXXXXXX,XXXXXXX,       LT(1,KC_SPACE),MO(2),LT(3,KC_TAB)
                     // XXXXXXX,KC_LSFT, KC_LGUI,KC_ESC,    KC_SPACE, MO(1), LT(2,KC_TAB),   XXXXXXX
    ),

    // KC_TAB, KC_A,   KC_S,   KC_R,   KC_T,   KC_G,             KC_M,     KC_N,  KC_E,    KC_I,   KC_O,    KC_ENTER,
     // MO(4),              KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,             KC_K,     KC_H,  KC_COMM, KC_DOT, KC_SLSH, MO(4),

    [1] = LAYOUT(
        XXXXXXX,XXXXXXX, HYPR(KC_F), HYPR(KC_C), HYPR(KC_T), HYPR(KC_D),               KC_SPACE,   KC_HOME,    KC_UP,   KC_END,   XXXXXXX, KC_DEL,
        XXXXXXX, XXXXXXX, KC_PGDN, S(KC_TAB),  KC_TAB, VIM_CMD,       KC_ESC,   KC_LEFT,      KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,   XXXXXXX,    LGUI(KC_Z), S(LGUI(KC_Z)),  KC_VOLD,       KC_VOLU,       KC_MPLY, _______,
                          _______, _______,    _______,MO(5),     _______, _______, _______,_______
    ),
    /*
     *      1 2 3 4 5   6 7 8 9 0
     *      ~ [ { ( -   + ) } ] |
     *        ` ' " _   = : ; . \
     *     !@#$%    ^&*()
     */
    [2] = LAYOUT(
        KC_0,    KC_1,    KC_2,        KC_3,    KC_4,       KC_5,            KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_TILD, KC_LBRC,     KC_LCBR, KC_LPRN,    KC_MINUS,        KC_PLUS,  KC_RPRN, KC_RCBR, KC_RBRC, KC_PIPE, _______,
        _______, KC_BSLS, KC_GRV,      KC_QUOT, S(KC_QUOT), S(KC_MINUS),     KC_EQUAL, KC_COLN, KC_SCLN, KC_DOT,  KC_BSLS, _______,
                              _______, MO(4), _______, _______,         _______, _______, _______, _______

    ),

    [3] = LAYOUT(
        _______,        LGUI(KC_Q), LGUI(KC_W), HYPR(KC_F), HYPR(KC_R), HYPR(KC_T),   HYPR(KC_J), HYPR(KC_L),    HYPR(KC_UP) ,  HYPR(KC_O),    HYPR(KC_P),  _______,
        LGUI(KC_TILDE), HYPR(KC_A), HYPR(KC_S), HYPR(KC_R), HYPR(KC_T), HYPR(KC_G),   HYPR(KC_M), HYPR(KC_LEFT), HYPR(KC_DOWN), HYPR(KC_RIGHT), _______, _______,
        _______,        HYPR(KC_Z), HYPR(KC_X), HYPR(KC_C), HYPR(KC_D), HYPR(KC_V),   HYPR(KC_K), HYPR(KC_H) ,   KC_VOLD,       KC_VOLU,       KC_MPLY, _______,
                          _______, _______, _______, _______,             HYPR(KC_SPACE), _______, _______, _______
    ),

    [4] = LAYOUT(
        _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),     S(KC_6),  S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    _______,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   _______,
                          _______, _______, _______, KC_F11,     KC_F12, _______, _______, _______
    ),

    [5] = LAYOUT(
        QK_BOOT, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
        QK_BOOT, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, QK_BOOT,
                          _______, _______, _______, _______,      _______, _______, _______, _______
    ),
};





bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    if (record->event.pressed)
    {
        switch (keycode)
        {
            case VIM_CMD:
                tap_code(KC_ESC);
                SEND_STRING(":w");
                tap_code(KC_ENTER);
                return false;
        }
    }
    return true;
}
