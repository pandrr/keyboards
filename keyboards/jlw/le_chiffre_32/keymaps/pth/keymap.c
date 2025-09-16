#include QMK_KEYBOARD_H


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
const uint16_t PROGMEM combo_tab2[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_os_ctl[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_os_alt[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM combo_os_sftgui[] = {KC_J ,KC_L, COMBO_END};
const uint16_t PROGMEM combo_os_altgui[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM combo_pause[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_leaderkey[] = {KC_N, KC_K, COMBO_END};
const uint16_t PROGMEM combo_undo[] = {KC_L, KC_U, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_os_ctl, OS_LCTL),
    COMBO(combo_os_alt, OS_LALT),
    COMBO(combo_os_altgui,OS_LAG),
    COMBO(combo_os_sftgui,OS_LSG),
    COMBO(combo_leaderkey, KC_F13),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_tab2, KC_TAB),
    COMBO(combo_pause,KC_MPLY),
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


const uint8_t pth_side_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_3thumb(
     PTH_OL, PTH_L, PTH_L, PTH_L, PTH_L,  PTH_S,   PTH_R, PTH_R,  PTH_R, PTH_R, PTH_R,
     PTH_L, PTH_L, PTH_L, PTH_L, PTH_L,           PTH_R, PTH_R, PTH_R,  PTH_R, PTH_R,
     PTH_L, PTH_L, PTH_L, PTH_L, PTH_L,          PTH_R, PTH_R, PTH_R,  PTH_R, PTH_R,

                 PTH_O, PTH_O, PTH_O,     PTH_O, PTH_O, PTH_O);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     *      q w f p b   j l u y
     *      a s r t g   m n e i o
     *      z x c d v   k h , . /
     *
     */
    [DEFAULT] = LAYOUT_3thumb(
        LT(LUI,KC_Q),  KC_W,   KC_F, KC_P,   KC_B,  _______,               KC_J,  KC_L,  KC_U,    KC_Y,   KC_BSPC,
        KC_A,  MT(MOD_LALT,KC_S),   MT(MOD_LGUI,KC_R), MT(MOD_LCTL,KC_T), KC_G,         KC_M,  MT(MOD_LCTL,KC_N),  MT(MOD_LGUI,KC_E),    MT(MOD_RALT,KC_I),   KC_O,
        KC_Z,  KC_X,   KC_C, KC_D,  KC_V,                                  KC_K,  KC_H, KC_COMM, KC_DOT, LT(LMOUSE,KC_SLSH),
        MT(MOD_LSFT,KC_ESC),MT(MOD_LSFT,KC_ESC),MT(MOD_LGUI,KC_ENTER),       LT(LNAV,KC_SPACE),LT(LSYM,KC_F13),LT(LSYM,KC_F13)
    ),

    [CTLBASED] = LAYOUT_3thumb(
        _______, _______, _______, _______, _______,_______,   _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
                          _______, _______, MT(MOD_LCTL,KC_ENTER),           _______, _______, _______
      ),

    [LNAV] = LAYOUT_3thumb(
         KC_ESC, moWord, _______, moPaste,    moBack,   XXXXXXX,   KC_PGUP,  moUndo,    KC_UP,    moYank,   KC_DEL,
         KC_ESC,    OS_LSFT,  LSFT(KC_TAB),KC_TAB,  KC_F13,        KC_PGDN,  KC_LEFT,   KC_DOWN,  KC_RIGHT, moOpenLine,
         _______,    moSelLine,  moDel,moDel, KC_LALT,             KC_F13,   KC_LCTL,   KC_LALT,  _______,  KC_ENTER,
                          _______,KC_LSFT,KC_F13,                            XXXXXXX, _______, _______
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
    [LMOUSE] = LAYOUTCONV(
        POS_00, POS_01,  POS_02, POS_03, POS_04,      XXXXXXX, moRedo, XXXXXXX, XXXXXXX, XXXXXXX,
        POS_10, POS_11,  POS_12, POS_13, POS_14,      XXXXXXX, MS_BTN1, MS_BTN3, MS_BTN2, XXXXXXX,
        POS_20, POS_21,  POS_22, POS_23, POS_24,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
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
                register_code(cmdKey);
                tap_code(KC_LEFT);
                unregister_code(cmdKey);
                return false;
            case moGoEndLine:
                register_code(cmdKey);
                tap_code(KC_RIGHT);
                unregister_code(cmdKey);
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
        [6] =   { ENCODER_CCW_CW(_______, _______) },
        [7] =   { ENCODER_CCW_CW(_______, _______) },
        // [5] =   { ENCODER_CCW_CW(_______, _______) },
        // [6] =   { ENCODER_CCW_CW(_______, _______) }
   };
#endif
















// switch ctrl/cmd automatically
// uint32_t os_swap_ctrl_gui(uint32_t trigger_time, void *cb_arg) {
//     os_variant_t os = detected_host_os();

//     if (os == OS_MACOS) {
//         keymap_config.swap_lctl_lgui = true;  // Swap CTRL and GUI on Mac
//         keymap_config.swap_rctl_rgui = true;
//     } else {
//         keymap_config.swap_lctl_lgui = false; // Normal for Windows/Linux
//         keymap_config.swap_rctl_rgui = false;
//     }

//     return 0; // End the deferred execution
// }
// void keyboard_post_init_user(void) {
//     defer_exec(100, os_swap_ctrl_gui, NULL); // Wait 100ms for OS detection
// }


