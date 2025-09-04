#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "deferred_exec.h"


enum layers {
    DEFAULT,
    CTLBASED,
    LNAV,
    LSYM,
    LUI,
    LMOGO,
    LMOSFT,
    LCFG
};

const uint16_t PROGMEM combo_boot[] = {KC_Z, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_os_ctl[] = {KC_H, KC_COMM, COMBO_END};
// const uint16_t PROGMEM combo_os_ctl2[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM combo_os_alt[] = {KC_K, KC_H, COMBO_END};
// const uint16_t PROGMEM combo_os_gui[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM combo_os_sftgui[] = {KC_J ,KC_L, COMBO_END};
// const uint16_t PROGMEM combo_os_gui2[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_os_altgui[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM combo_pause[] = {KC_DOT, KC_SLSH, COMBO_END};

// const uint16_t PROGMEM combo_vimode[] = {KC_T, KC_V, COMBO_END};
const uint16_t PROGMEM combo_leaderkey[] = {KC_N, KC_K, COMBO_END};
const uint16_t PROGMEM combo_undo[] = {KC_L, KC_U, COMBO_END};
// const uint16_t PROGMEM combo_yank[] = {KC_U, KC_Y, COMBO_END};
// const uint16_t PROGMEM combo_paste[] = {KC_F, KC_P, COMBO_END};
// const uint16_t PROGMEM combo_sym[] = {KC_R, KC_T, COMBO_END};

combo_t key_combos[] = {
    // COMBO(combo_boot, QK_BOOT),
    COMBO(combo_os_ctl, OS_LCTL),
    // COMBO(combo_os_ctl2, OS_LCTL),
    COMBO(combo_os_alt, OS_LALT),
    // COMBO(combo_os_gui, OS_RGUI),
    // COMBO(combo_os_gui2, OS_LGUI),
    COMBO(combo_os_altgui,OS_LAG),
    COMBO(combo_os_sftgui,OS_LSG),
    COMBO(combo_leaderkey, KC_F13),
    COMBO(combo_tab, KC_TAB),
    // COMBO(combo_vimode, OSL(LVIM)),
    // COMBO(combo_undo, LGUI(KC_Z)),
    // COMBO(combo_yank, LGUI(KC_C)),
    // COMBO(combo_paste, LGUI(KC_V)),
    COMBO(combo_pause,KC_MPLY),
    // COMBO(combo_sym,OSL(LSYM)),
};

enum custom_keycodes {
    VIM_CMD = SAFE_RANGE,
    moWord,
    moBack,
    moOpenLine,
    moSelLine,
    moDelRight,
    moDel,
    moUndo,
    moRedo,
    moYank,
    moPaste,
    moGoStart,
    moGoTop,
    moGoEnd,
    moGoEndLine,
    linux,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     *      q w f p b   j l u y
     *      a s r t g   m n e i o
     *      z x c d v   k h , . /
     *
     */
    [DEFAULT] = LAYOUT_3thumb(
        LT(LUI,KC_Q),  KC_W,   KC_F, KC_P,   KC_B,  _______,   KC_J,  KC_L,  KC_U,    KC_Y,   KC_BSPC,
        KC_A,  KC_S,   KC_R, KC_T,   KC_G,                     KC_M,  KC_N,  KC_E,    KC_I,   KC_O,
        KC_Z,  KC_X,   KC_C, KC_D,  KC_V,                      KC_K,  KC_H, KC_COMM, KC_DOT, KC_SLSH,
        MT(MOD_LSFT,KC_ESC),MT(MOD_LSFT,KC_ESC),MT(MOD_LGUI,KC_ENTER),       LT(LNAV,KC_SPACE),LT(LSYM,KC_F13),LT(LSYM,KC_F13)
    ),

    [CTLBASED] = LAYOUT_3thumb(
        _______, _______, _______, _______, _______,_______,   _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
                          _______, _______, MT(MOD_LCTL,KC_ENTER),           _______, _______, _______
      ),
    // [LNAV] = LAYOUT_3thumb(
    //      KC_ESC, _______, _______, _______,    _______,   _______,   KC_PGUP,  KC_HOME,       KC_UP,    KC_END,   KC_DEL,
    //      KC_ESC,    OS_LSFT,  LSFT(KC_TAB),  KC_F13,_______,                         KC_PGDN,    KC_LEFT,       KC_DOWN,  KC_RIGHT, KC_ENTER,
    //      KC_INS,    XXXXXXX,  XXXXXXX,    KC_LCTL, KC_LALT,              KC_LALT, KC_LCTL, KC_LGUI,  KC_VOLD,  KC_VOLU,
    //                       _______,MO(LVIM),MO(LVIM),                                XXXXXXX, _______, _______
    // ),
    [LNAV] = LAYOUT_3thumb(
         KC_ESC, moWord, _______, moPaste,    moBack,   XXXXXXX,   KC_PGUP,  moUndo,       KC_UP,    moYank,   KC_DEL,
         KC_ESC,    OS_LSFT,  LSFT(KC_TAB),KC_TAB,  KC_F13,                         KC_PGDN,    KC_LEFT,       KC_DOWN,  KC_RIGHT, moOpenLine,
         _______,    moSelLine,  moDel,moDel, KC_LALT,              KC_F13, KC_LCTL, KC_LALT,  _______,  KC_ENTER,
                          _______,KC_LSFT,KC_F13,                                XXXXXXX, _______, _______
    ),
    /*
     *      1 2 3 4 5   6 7 8 9 0
     *      ~ [ { ( -   + ) } ] |
     *      \ ` ' " _   = : ; . /
     *
     *      !@#$%    ^&*()
     */
    [LSYM] = LAYOUT_3thumb(
         KC_1,    KC_2,    KC_3,    KC_4,       KC_5,      KC_MPLY,      KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
         KC_TILD, KC_LBRC, KC_LCBR, KC_LPRN,    KC_MINUS,                KC_PLUS,  KC_RPRN, KC_RCBR, KC_RBRC, KC_PIPE,
         XXXXXXX, KC_GRV,  KC_QUOT, S(KC_QUOT), S(KC_MINUS),             KC_EQUAL, KC_COLN, KC_SCLN, KC_DOT,  KC_BSLS,
                           _______, _______,   _______,                  MS_BTN2,  XXXXXXX, _______
    ),

    [LUI] = LAYOUT_3thumb(
        XXXXXXX, LCTL(LSFT(KC_TAB)), LALT(KC_UP), LCTL(KC_TAB), LGUI(KC_GRV), XXXXXXX,XXXXXXX, LGUI(KC_TAB),    HYPR(KC_SPACE) ,   LGUI(S(KC_TAB)),    _______,
        XXXXXXX, LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_RIGHT), XXXXXXX,           XXXXXXX, HYPR(KC_LEFT), HYPR(KC_DOWN), HYPR(KC_RIGHT), XXXXXXX,
        MO(LCFG), KC_VOLD, KC_VOLU, XXXXXXX, MS_BTN2,           XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
                           _______,MS_BTN3, MS_BTN1,                         XXXXXXX,  _______, _______
    ),

    // motion goto
    [LMOGO] = LAYOUT_3thumb(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,   XXXXXXX, moGoEndLine, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, moGoStart,XXXXXXX, XXXXXXX, moGoTop,           XXXXXXX, XXXXXXX, moGoEnd, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX
      ),
    // shift motions
    [LMOSFT] = LAYOUT_3thumb(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,   XXXXXXX, moRedo, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, moDelRight, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX
      ),
    // backspace - flash
    // m - mac mode
    // w - win mode
    [LCFG] = LAYOUT_3thumb(
        _______, QK_MAGIC_SWAP_CTL_GUI, _______, _______, _______,   _______,   _______, linux, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______,              QK_MAGIC_UNSWAP_CTL_GUI, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______,
                          _______, _______, _______,              _______, _______, _______
      )


};

uint8_t myOs=0;// 0 mac \ 1 linux


bool process_record_user(uint16_t keycode, keyrecord_t* record)
{

    uint16_t cmdKey=KC_LGUI;
    if(keymap_config.swap_lctl_lgui ) cmdKey=KC_LCTL;

    if (record->event.pressed)
    {
        switch (keycode)
        {
            case linux:
                if(myOs==0 )
                {
                     myOs=1;
                    layer_on(CTLBASED);
                }
                else{
                    layer_off(CTLBASED);
                    myOs=0;
                }
                return false;
            case VIM_CMD:
                tap_code(KC_ESC);
                SEND_STRING(":");
                return false;
            case moWord:
                register_code(KC_LSFT);
                if(myOs==0) register_code(KC_LALT);
                else register_code(KC_LCTL);

                tap_code(KC_RIGHT);
                if(myOs==0) unregister_code(KC_LALT);
                else unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                return false;
            case moBack:
                if(myOs==0) register_code(KC_LALT);
                else register_code(KC_LCTL);
                tap_code(KC_LEFT);
                if(myOs==0) unregister_code(KC_LALT);
                else unregister_code(KC_LCTL);
                return false;

            case moPaste:
                if(myOs==1)
                {
                    register_code(KC_LSFT);
                    tap_code(KC_INS);
                    unregister_code(KC_LSFT);
                }
                else
                {
                    register_code(KC_LGUI);
                    tap_code(KC_V);
                    unregister_code(KC_LGUI);
                }
                return false;
            case moYank:
                if(myOs==1)
                {
                    register_code(KC_LCTL);
                    tap_code(KC_INS);
                    unregister_code(KC_LCTL);
                }
                else
                {
                    register_code(KC_LGUI);
                    tap_code(KC_C);
                    unregister_code(KC_LGUI);
                }
                return false;

            case moUndo:
                register_code(cmdKey);
                tap_code(KC_Z);
                unregister_code(cmdKey);
                return false;
            case moRedo:
                register_code(cmdKey);
                register_code(KC_LSFT);
                tap_code(KC_Z);
                unregister_code(KC_LSFT);
                unregister_code(cmdKey);
                return false;

            case moOpenLine:
                register_code(cmdKey);
                tap_code(KC_RIGHT);
                unregister_code(cmdKey);
                tap_code(KC_ENTER);
                return false;

            case moSelLine:
                register_code(cmdKey);
                tap_code(KC_LEFT);
                unregister_code(cmdKey);
                register_code(cmdKey);
                register_code(KC_LSFT);
                tap_code(KC_RIGHT);
                unregister_code(cmdKey);
                unregister_code(KC_LSFT);
                return false;

            case moDelRight:
                register_code(KC_LSFT);
                register_code(cmdKey);
                tap_code(KC_RIGHT);
                unregister_code(cmdKey);
                unregister_code(KC_LSFT);
                tap_code(KC_DEL);
                return false;

            case moDel:
                tap_code(KC_DEL);
                return false;
            case moGoTop:
                register_code(cmdKey);
                tap_code(KC_UP);
                unregister_code(cmdKey);
                return false;
            case moGoEnd:
                register_code(cmdKey);
                tap_code(KC_DOWN);
                unregister_code(cmdKey);
                return false;
            case moGoStart:
                register_code(cmdKey);
                tap_code(KC_LEFT);
                unregister_code(cmdKey);
                return false;
            case moGoEndLine:
                register_code(cmdKey);
                tap_code(KC_RIGHT);
                unregister_code(cmdKey);
                return false;


        }
    }
    return true;
}const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
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
        [5] =   { ENCODER_CCW_CW(_______, _______) },
        [6] =   { ENCODER_CCW_CW(_______, _______) },
        [7] =   { ENCODER_CCW_CW(_______, _______) },
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

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record)
{
    // if(last_input_activity_elapsed() < QUICK_TAP_TERM) return false;

    switch (keycode) {
        case LT(LNAV, KC_SPACE):
                if(last_input_activity_elapsed() > QUICK_TAP_TERM) return true;
                return false;
        case MT(MOD_LGUI, KC_ENTER): return true;
        case MT(MOD_LSFT, KC_ESC): return true;
        case LT(LSYM, KC_TAB): return true;
        default: return false;
    }
}


// switch ctrl/cmd automatically
uint32_t os_swap_ctrl_gui(uint32_t trigger_time, void *cb_arg) {
    os_variant_t os = detected_host_os();

    if (os == OS_MACOS) {
        keymap_config.swap_lctl_lgui = true;  // Swap CTRL and GUI on Mac
        keymap_config.swap_rctl_rgui = true;
    } else {
        keymap_config.swap_lctl_lgui = false; // Normal for Windows/Linux
        keymap_config.swap_rctl_rgui = false;
    }

    return 0; // End the deferred execution
}
void keyboard_post_init_user(void) {
    defer_exec(100, os_swap_ctrl_gui, NULL); // Wait 100ms for OS detection
}
