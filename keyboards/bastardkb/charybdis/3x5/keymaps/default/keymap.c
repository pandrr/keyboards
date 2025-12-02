
#define LAYOUTCONV( \
  k00, k01, k02, k03, k04, k05, k06, k07, k08, k09,  \
  k10, k11, k12, k13, k14, k15, k16, k17, k18, k19,  \
  k20, k21, k22, k23, k24, k25, k26, k27, k28, k29,  \
  k30, k31, k32, k33, k34, k35   \
) \
  LAYOUT( \
  k00, k01, k02, k03, k04, k05, k06, k07, k08, k09,  \
  k10, k11, k12, k13, k14, k15, k16, k17, k18, k19,  \
  k20, k21, k22, k23, k24, k25, k26, k27, k28, k29,  \
  k30, k31, k32, k33, k34 \
  )

///////////////////////////////////////////////


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
    LCFG,
    LMOUSE
};

const uint16_t PROGMEM combo_boot[] =        {KC_Z, KC_SLSH, COMBO_END};

const uint16_t PROGMEM combo_os_ctl[] =      {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_os_gui[] =      {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM combo_os_alt[] =      {KC_DOT, KC_COMM, COMBO_END};

const uint16_t PROGMEM combo_os_gui_l[] =    {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM combo_os_ctl_l[] =    {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM combo_os_alt_l[] =    {KC_X, KC_C, COMBO_END};

const uint16_t PROGMEM combo_os_guialt_l[] = {KC_T, KC_V, COMBO_END};
const uint16_t PROGMEM combo_os_guialt[] =   {KC_K, KC_N, COMBO_END};

const uint16_t PROGMEM combo_os_guisft_l[] = {KC_G, KC_P, COMBO_END};
const uint16_t PROGMEM combo_os_guisft[] =   {KC_L, KC_M, COMBO_END};

const uint16_t PROGMEM combo_os_hypr[] =     {KC_Z, KC_X, COMBO_END};

 const uint16_t PROGMEM combo_mouse[] =       {KC_T, KC_G, COMBO_END};

const uint16_t PROGMEM combo_esc[] =         {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_tab[] =         {KC_W, KC_P, COMBO_END};
// const uint16_t PROGMEM combo_esc1[] =         {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM combo_esc2[] =         {KC_Q, KC_W, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_os_gui_l,OS_LGUI),
    COMBO(combo_os_ctl_l, OS_LCTL),
    COMBO(combo_os_alt_l, OS_LALT),
    COMBO(combo_os_gui, OS_LGUI),
    COMBO(combo_os_ctl, OS_LCTL),
    COMBO(combo_os_alt, OS_LALT),

    COMBO(combo_mouse, MS_BTN1),

    COMBO(combo_os_guialt_l,OS_LAG),
    COMBO(combo_os_guialt,OS_LAG),

    COMBO(combo_os_guisft_l,OS_LSG),
    COMBO(combo_os_guisft,OS_LSG),

    // COMBO(combo_os_hypr,OS_HYPR),

    COMBO(combo_tab, KC_TAB),
    COMBO(combo_esc, KC_ESC),
    // COMBO(combo_esc1, KC_ESC),
    COMBO(combo_esc2, KC_ESC)
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
    POS_00, POS_01,  POS_02, POS_03, POS_04,
    POS_10, POS_11,  POS_12, POS_13, POS_14,
    POS_20, POS_21,  POS_22, POS_23, POS_24
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     *      q w f p b   j l u y
     *      a s r t g   m n e i o
     *      z x c d v   k h , . /
     *
     */
    [DEFAULT] = LAYOUTCONV(
        LT(LUI,KC_Q),  KC_W,   KC_F, KC_P, KC_B,      KC_J,  KC_L,  KC_U,    KC_Y,   KC_BSPC,
                KC_A,  KC_S,   KC_R, KC_T, KC_G,      KC_M,  KC_N,  KC_E,    KC_I,   KC_O,
                KC_Z,  KC_X,   KC_C, KC_D, KC_V,      KC_K,  KC_H, KC_COMM, KC_DOT, KC_SLSH,
            MO(LMOUSE),KC_LSFT,MT(MOD_LGUI,KC_ENTER),       LT(LNAV,KC_SPACE),LT(LSYM,KC_F13),LT(LSYM,KC_F13)
    ),

    [CTLBASED] = LAYOUTCONV(
        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
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
    [LNAV] = LAYOUTCONV(
         KC_ESC, moWord, _______, moPaste,    moBack,              KC_PGUP,  moUndo,       KC_UP,    moYank,   KC_DEL,
         KC_ESC,    KC_ENTER,  LSFT(KC_TAB),KC_TAB,  OSL(LMOGO),    KC_PGDN,    KC_LEFT,       KC_DOWN,  KC_RIGHT, moOpenLine,
         _______,    moSelLine,  moDel,moDel, KC_LALT,              KC_LGUI,KC_LCTL, KC_LALT,  _______,  KC_ENTER,
                          _______,KC_LSFT,MT(MOD_LCTL,KC_ENTER),                                XXXXXXX, _______, _______
    ),
    /*
     *      1 2 3 4 5   6 7 8 9 0
     *      ~ [ { ( -   + ) } ] |
     *      \ ` ' " _   = : ; . /
     *
     *      !@#$%    ^&*()
     */
    [LSYM] =LAYOUTCONV(
         KC_1,    KC_2,    KC_3,    KC_4,       KC_5,            KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
         KC_TILD, KC_LBRC, KC_LCBR, KC_LPRN,    KC_MINUS,        KC_PLUS,  KC_RPRN, KC_RCBR, KC_RBRC, KC_PIPE,
         XXXXXXX, KC_GRV,  KC_QUOT, S(KC_QUOT), S(KC_MINUS),     KC_EQUAL, KC_COLN, KC_SCLN, KC_DOT,  KC_BSLS,
                           _______, _______,   _______,          MS_BTN2,  XXXXXXX, _______
    ),

    [LUI] = LAYOUTCONV(
        XXXXXXX, LCTL(LSFT(KC_TAB)), LALT(KC_UP), LCTL(KC_TAB), LGUI(KC_GRV), XXXXXXX, LGUI(KC_TAB),    HYPR(KC_SPACE) ,   LGUI(S(KC_TAB)),    _______,
        XXXXXXX, LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_RIGHT), XXXXXXX,           XXXXXXX, HYPR(KC_LEFT), HYPR(KC_DOWN), HYPR(KC_RIGHT), XXXXXXX,
        MO(LCFG), KC_VOLD, KC_VOLU, XXXXXXX, MS_BTN2,           XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
                           _______,MS_BTN3, MS_BTN1,                         XXXXXXX,  _______, _______
    ),

    // motion goto
    [LMOGO] = LAYOUTCONV(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, moGoEndLine, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, moGoStart,XXXXXXX, XXXXXXX, moGoTop,  XXXXXXX, XXXXXXX, moGoEnd, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
      ),
    // shift motions
    [LMOSFT] = LAYOUTCONV(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, moRedo, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, moDelRight, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
      ),

    [LMOUSE] = LAYOUTCONV(
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, moRedo, XXXXXXX, XXXXXXX, KC_MPLY,
        XXXXXXX, XXXXXXX,  MS_BTN2, MS_BTN1, XXXXXXX,      XXXXXXX, MS_BTN1, MS_BTN3, MS_BTN2, XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX, MS_BTN3, XXXXXXX,      XXXXXXX, MS_BTN1, KC_VOLD, KC_VOLU, XXXXXXX,
                          XXXXXXX, XXXXXXX, MS_BTN1,      MS_BTN1, MS_BTN2, XXXXXXX
      ),

    // backspace - flash
    // m - mac mode
    // w - win mode
    [LCFG] = LAYOUTCONV(
        _______, QK_MAGIC_SWAP_CTL_GUI, _______, _______,   _______,   _______, linux, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______,              QK_MAGIC_UNSWAP_CTL_GUI, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______,
                          _______, _______, _______,              _______, _______, _______
      )
};


#define OS_MAC 0
#define OS_LINUX 1

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
                if(myOs==OS_MAC )
                {
                     myOs=1;
                    layer_on(CTLBASED);
                    cmdKey=KC_LCTL;
                }
                else{
                    layer_off(CTLBASED);
                    myOs=OS_MAC;
                    cmdKey=KC_LCTL;
                }
                return false;
            case VIM_CMD:
                tap_code(KC_ESC);
                SEND_STRING(":");
                return false;
            case moWord:
                register_code(KC_LSFT);
                if(myOs==OS_MAC) register_code(KC_LALT);
                else register_code(KC_LCTL);

                tap_code(KC_RIGHT);
                if(myOs==OS_MAC) unregister_code(KC_LALT);
                else unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                return false;
            case moBack:
                if(myOs==OS_MAC) register_code(KC_LALT);
                else register_code(KC_LCTL);
                tap_code(KC_LEFT);
                if(myOs==OS_MAC) unregister_code(KC_LALT);
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
                if(myOs==1)
                {
                    tap_code(KC_END);
                }
                else
                {
                    register_code(cmdKey);
                    tap_code(KC_RIGHT);
                    unregister_code(cmdKey);
                }
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
                if(myOs==OS_MAC){
                    register_code(cmdKey);
                    tap_code(KC_LEFT);
                    unregister_code(cmdKey);
                }else{
                    tap_code(KC_HOME);
                }
                return false;
            case moGoEndLine:
                if(myOs==OS_MAC){
                    register_code(cmdKey);
                    tap_code(KC_RIGHT);
                    unregister_code(cmdKey);
                }else{
                    tap_code(KC_END);
                }
                return false;


            case POS_00: digitizer_in_range_on();digitizer_set_position(0.1 , 0.2);  return false;
            case POS_01: digitizer_in_range_on();digitizer_set_position(0.30, 0.2);  return false;
            case POS_02: digitizer_in_range_on();digitizer_set_position(0.50, 0.2);  return false;
            case POS_03: digitizer_in_range_on();digitizer_set_position(0.70, 0.2);  return false;
            case POS_04: digitizer_in_range_on();digitizer_set_position(0.90, 0.2);  return false;
            case POS_10: digitizer_in_range_on();digitizer_set_position(0.1 , 0.5);  return false;
            case POS_11: digitizer_in_range_on();digitizer_set_position(0.30, 0.5);  return false;
            case POS_12: digitizer_in_range_on();digitizer_set_position(0.50, 0.5);  return false;
            case POS_13: digitizer_in_range_on();digitizer_set_position(0.70, 0.5);  return false;
            case POS_14: digitizer_in_range_on();digitizer_set_position(0.90, 0.5);  return false;
            case POS_20: digitizer_in_range_on();digitizer_set_position(0.1 , 0.8);  return false;
            case POS_21: digitizer_in_range_on();digitizer_set_position(0.30, 0.8);  return false;
            case POS_22: digitizer_in_range_on();digitizer_set_position(0.50, 0.8);  return false;
            case POS_23: digitizer_in_range_on();digitizer_set_position(0.70, 0.8);  return false;
            case POS_24: digitizer_in_range_on();digitizer_set_position(0.90, 0.8);  return false;

        }
    }
    return true;
}const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUTCONV(
         '*', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
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
        [8] =   { ENCODER_CCW_CW(_______, _______) }
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
    ( ((uint8_t)(k) <= KC_Z && ((uint8_t)(k) >= KC_A)) ||(uint8_t)(k) == KC_SPC) && \
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

#define SCROLL_DIVISOR_H 20.0
#define SCROLL_DIVISOR_V 20.0

static bool scrolling_mode = false;
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;


// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case LMOUSE:  // Replace _SCROLL with the layer number or name you use
//             scrolling_mode = true;
//             pointing_device_set_cpi(50);  // Lower CPI for better scroll control (optional)
//             break;

//         // case LUI:  // Replace _SCROLL with the layer number or name you use
//         //     scrolling_mode = false ;
//         //     pointing_device_set_cpi(2400);  // Lower CPI for better scroll control (optional)
//         //     break;
//         default:
//             if (scrolling_mode)  scrolling_mode = false;
//                 pointing_device_set_cpi(900);  // Restore normal CPI (optional)
//             break;
//     }
//     return state;
// }
// current keyboard modifiers
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

    uint8_t mods = get_mods();

    if (mods & (MOD_BIT(KC_LGUI) ))
    {
        scrolling_mode=true;
        pointing_device_set_cpi(50);
    }
    else
    {
        scrolling_mode = false;
        pointing_device_set_cpi(900);
    }

    if (scrolling_mode) {
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = 0;//(int8_t)scroll_accumulated_v;
        mouse_report.v =-(int8_t)dscroll_accumulated_h;
        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;


    }
    return mouse_report;
}

// void pointing_device_init_user(void) {
// set_auto_mouse_layer(LMOUSE);
//     set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
// }
