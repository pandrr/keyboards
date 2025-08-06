#include QMK_KEYBOARD_H



const uint16_t PROGMEM combo_boot[] = {KC_Z, KC_SLSH, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_boot, QK_BOOT),
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_eg(
        LT(3,KC_Q),  KC_W,   KC_F, KC_P,   KC_B,             KC_J,     KC_L,  KC_U,    KC_Y,   KC_BSPC,
        KC_A,  KC_S,   KC_R, KC_T,   KC_G,                     KC_M,     KC_N,  KC_E,    KC_I,   KC_O,
        KC_Z,  KC_X,   KC_C, MT(MOD_LCTL,KC_D),  MT(MOD_LALT,KC_V),         MT(MOD_LALT,KC_K), MT(MOD_LCTL,KC_H), KC_COMM, KC_DOT,  LT(4,KC_SLSH),
                _______,  MT(MOD_LSFT,KC_ESC),MT(MOD_LGUI,KC_ENTER),       LT(1,KC_SPACE),LT(2,KC_TAB), _______
    ),

    [1] = LAYOUT_eg(
         HYPR(KC_0), HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4),      HYPR(KC_5),  KC_HOME,       KC_UP,    KC_END,   KC_DEL,
         S(KC_TAB),KC_TAB,KC_ESC,KC_ENTER,     KC_ESC,                 KC_PGUP,    KC_LEFT,       KC_DOWN,  KC_RIGHT, KC_ENTER,
         XXXXXXX,    XXXXXXX,    XXXXXXX,    S(LGUI(KC_Z)),LGUI(KC_Z),                KC_PGDN, KC_MPLY, KC_VOLD,  KC_VOLU,  KC_MPLY,
 _______,                            _______,  _______,               XXXXXXX, MS_BTN1 , _______    ),
    /*
     *      1 2 3 4 5   6 7 8 9 0
     *      ~ [ { ( -   + ) } ] |
     *      \ ` ' " _   = : ; . /
     *
     *      !@#$%    ^&*()
     */
    [2] = LAYOUT_eg(
         KC_1,    KC_2,    KC_3,    KC_4,       KC_5,            KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
         KC_TILD, KC_LBRC, KC_LCBR, KC_LPRN,    KC_MINUS,                KC_PLUS,  KC_RPRN, KC_RCBR, KC_RBRC, KC_PIPE,
         KC_BSLS, KC_GRV,  KC_QUOT, S(KC_QUOT), S(KC_MINUS),             KC_EQUAL, KC_COLN, KC_SCLN, KC_DOT,  KC_BSLS,
           _______,                  _______, _______,                    MS_BTN2,  XXXXXXX , _______    ),

    [3] = LAYOUT_eg(
        XXXXXXX, _______, _______, _______, _______,      _______, _______, MS_UP, _______, QK_BOOT,
        _______, _______, _______, MS_BTN1, MS_BTN2,              _______, MS_LEFT, MS_DOWN, MS_RGHT, _______,
        _______, _______, _______, MS_BTN3, _______,              _______, _______, _______, _______, _______,
                         _______,  _______, QK_AUDIO_TOGGLE,               QK_MUSIC_TOGGLE, QK_AUDIO_CLICKY_TOGGLE	 ,_______      ),
    [4] = LAYOUT_eg(
        HYPR(KC_Q), HYPR(KC_W), HYPR(KC_F), HYPR(KC_R), HYPR(KC_T),   HYPR(KC_J), HYPR(KC_L),    HYPR(KC_SPACE) ,  HYPR(KC_Y),    _______,
        HYPR(KC_A), HYPR(KC_S), HYPR(KC_R), HYPR(KC_T), HYPR(KC_G),           HYPR(KC_M), HYPR(KC_LEFT), HYPR(KC_DOWN), HYPR(KC_RIGHT), HYPR(KC_O),
        QK_BOOT, HYPR(KC_X), HYPR(KC_C), HYPR(KC_D), HYPR(KC_V),           HYPR(KC_K), HYPR(KC_H) ,   HYPR(KC_COMM), HYPR(KC_DOT), HYPR(KC_ENTER),
                     _______,        _______,_______,                          HYPR(KC_SPACE),   _______,_______
    )};

const int            led_count =1;
int                  leds[]    = {0};


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_eg(
         '*', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
         'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
         'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',  '*', '*', '*'
    );
#define IS_HOMEROW_MOD_TAP(kc) (              \
    IS_QK_MOD_TAP(kc)                      && \
    QK_MOD_TAP_GET_TAP_KEYCODE(kc) >= KC_A && \
    QK_MOD_TAP_GET_TAP_KEYCODE(kc) <= KC_Z    )

// Decision macro for preceding trigger key and typing interval
#define IS_TYPING(k) ( \
    ((uint8_t)(k) <= KC_Z ||(uint8_t)(k) == KC_SPC) && \
    (last_input_activity_elapsed() < QUICK_TAP_TERM)    )

#define MY_SONG  W__NOTE(_D4)

float my_song[][2] = SONG(MY_SONG);
uint8_t oldlayer=0;


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
        // case LT(3, KC_Q): return true; // Immediately select the hold action when another key is pressed.
        case MT(MOD_LGUI, KC_ENTER): return true; // Immediately select the hold action when another key is pressed.
        case MT(MOD_LSFT, KC_ESC): return true; // Immediately select the hold action when another key is pressed.
        default: return false; // Do not select the hold action when another key is pressed.
    }
}

#define COL_BLACK          0,   0,   0
#define COL_AZURE        132, 102,150
#define COL_BLUE         170, 255,150
#define COL_CHARTREUSE    64, 255,150
#define COL_CORAL         11, 176,150
#define COL_CYAN         128, 255,150
#define COL_GOLD          36, 255,150
#define COL_GOLDENROD     30, 218,150
#define COL_GREEN         85, 255,150
#define COL_MAGENTA      213, 255,150
#define COL_ORANGE        21, 255,150
#define COL_PINK         234, 128,150
#define COL_PURPLE       191, 255,150
#define COL_RED            0, 255,150
#define COL_SPRINGGREEN  106, 255,150
#define COL_TEAL         128, 255,150
#define COL_TURQUOISE    123,  90,150
#define COL_WHITE          0,   0,150
#define COL_YELLOW        43, 255,150
#define COL_OFF          HSV_BLACK

void set_rgblight_by_layer(uint32_t layer) {
    for (int i = 0; i < led_count; i++) {
        switch (layer) {
            case 1:
                rgb_matrix_sethsv(COL_PURPLE);
                break;
            case 2:
                rgb_matrix_sethsv(COL_RED);
                break;
            case 3:
            case 4:
            case 5:
                rgb_matrix_sethsv(COL_BLUE);
                break;
            default:
                rgb_matrix_sethsv(COL_OFF);
                break;
        }
    }
}

void set_current_layer_rgb(void) {
    set_rgblight_by_layer(get_highest_layer(layer_state | default_layer_state));
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_rgblight_by_layer(biton32(state));
    return state;
}


bool rgb_matrix_indicators_user(void) {
    uint8_t mods                = get_mods();
    uint8_t oneshot_mods        = get_oneshot_mods();
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();

    bool isShift = mods & MOD_MASK_SHIFT || oneshot_mods & MOD_MASK_SHIFT || oneshot_locked_mods & MOD_MASK_SHIFT;
    bool isCtrl  = mods & MOD_MASK_CTRL || oneshot_mods & MOD_MASK_CTRL || oneshot_locked_mods & MOD_MASK_CTRL;
    bool isAlt   = mods & MOD_MASK_ALT || oneshot_mods & MOD_MASK_ALT || oneshot_locked_mods & MOD_MASK_ALT;
    bool isGui   = mods & MOD_MASK_GUI || oneshot_mods & MOD_MASK_GUI || oneshot_locked_mods & MOD_MASK_GUI;

    for (int i = 0; i < led_count; i++) {
        // if (swapper.state != NONE || leader.isLeading || select_word.state != STATE_NONE) {
            // rgb_matrix_set_color(leds[i], RGB_GREEN);
        // } else if (has_any_smart_case()) {
            // rgb_matrix_set_color(leds[i], RGB_YELLOW);
        // } else
         if (isShift) {
            rgb_matrix_sethsv( COL_TEAL);
        } else if (isCtrl || isAlt || isGui) {
            rgb_matrix_sethsv( COL_WHITE);
        } else {
            set_current_layer_rgb();
        }
    }

    // uint8_t layer = biton32(layer_state);
    // if(layer!=oldlayer&&layer!=0)
    // {
    //     audio_set_tempo(255);
    //     PLAY_SONG(my_song);
    // }
    // oldlayer=layer;

    return true;
}
