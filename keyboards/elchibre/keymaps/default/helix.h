enum vmode {
    NORMAL,
    INSERT,
    VISUAL
};

enum helixKeyCodes {
    toggleHelix= SAFE_RANGE
    };

static enum vmode mode = INSERT;

#define OS_MAC 0
#define OS_LINUX 1

uint8_t hxOs=OS_MAC;// 0 mac \ 1 linux


void wordB(void)
{
    if(hxOs==OS_MAC) register_code(KC_LALT);
    else register_code(KC_LCTL);
    tap_code(KC_LEFT);
    if(hxOs==OS_MAC) unregister_code(KC_LALT);
    else unregister_code(KC_LCTL);
}
void wordF(void)
{
    if(hxOs==OS_MAC) register_code(KC_LALT);
    else register_code(KC_LCTL);

    tap_code(KC_RIGHT);
    if(hxOs==OS_MAC) unregister_code(KC_LALT);
    else unregister_code(KC_LCTL);
}

static bool handle_normal(uint16_t keycode, keyrecord_t* record){

    uint16_t cmdKey=KC_LGUI;
    if(hxOs!=OS_MAC ) cmdKey=KC_LCTL;

     uint8_t mods = get_mods();
        // const bool keydown = record->event.pressed;

        bool shift=false;
        if(mods & MOD_MASK_SHIFT) shift=true;

    switch (keycode) {

        case KC_C:
        case KC_D:
            tap_code(KC_DEL);
            return false;
        case KC_B:
            wordB();
            return false;
        case KC_E:
            register_code(KC_LSFT);
            wordF();
            unregister_code(KC_LSFT);
            return false;

        case KC_W:
            wordF();
            return false;

        case KC_P:
            if(hxOs==1)
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

        case KC_Y:

            if(hxOs==1)
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

        case KC_U:
            register_code(cmdKey);
            tap_code(KC_Z);
            unregister_code(cmdKey);
            return false;

        case KC_A:
            if(shift)
            {
                del_mods(MOD_MASK_SHIFT);
                if(hxOs==OS_MAC)
                {
                    register_code(cmdKey);
                    tap_code(KC_RIGHT);
                    unregister_code(cmdKey);
                }else{
                    tap_code(KC_END);
                }
            }
            mode=INSERT;
            return false;

        case KC_I:
            mode=INSERT;

            if(shift)
            {
                del_mods(MOD_MASK_SHIFT);
                if(hxOs==OS_MAC)
                {
                    register_code(cmdKey);
                    tap_code(KC_LEFT);
                    unregister_code(cmdKey);
                }else{
                    tap_code(KC_END);
                }
            }
            return false;

        case KC_O:
            mode=INSERT;
            if(shift) tap_code(KC_UP);
            if(hxOs==OS_LINUX)
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

    }
    return true;
}

bool process_record_helix(uint16_t keycode, keyrecord_t* record)
{
    const bool keydown = record->event.pressed;

    if(keycode==toggleHelix)
    {
        if(!keydown)
        {
            if(mode==NORMAL)
            {
                mode=INSERT;
            }
            else
            {
                mode=NORMAL;
            }
        }
        return false;
    }
    if(mode==INSERT)return true;

    if(keydown)
        switch (mode)
        {
            case INSERT:
                return true;

            case NORMAL:
                return handle_normal(keycode, record);

            case VISUAL:
                break;
        }


    return false;
}

