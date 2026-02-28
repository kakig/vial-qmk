#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define RCAPS MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_RBRC, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
        KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_RSFT,
        KC_GRV , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                         KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_MINS,
                          KC_LALT, KC_TAB ,                                                             KC_EQL , KC_QUOT,
                                   KC_LCTL, KC_LWIN, MO(1)  ,                         MO(2)  , KC_ENT , KC_SPC
    ),

    [_LOWER] = LAYOUT_5x6(
        KC_F12  ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,                        KC_F6  ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 ,
        _______ , _______, _______, _______, _______, _______,                        _______, KC_7   , KC_8   , KC_9   , KC_MNXT, KC_VOLU,
        _______ , _______, _______, _______, _______, KC_PSCR,                        _______, KC_4   , KC_5   , KC_6   , KC_MPLY, KC_MUTE,
        _______ , _______, _______, _______, _______, _______,                        _______, KC_1   , KC_2   , KC_3   , KC_MPRV, KC_VOLD,
                           _______, _______,                                                            KC_0, _______,
                                    _______, _______, _______,                        _______, _______, _______
    ),

    [_RAISE] = LAYOUT_5x6(
        _______ , _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
        _______ , _______, KC_INS , KC_HOME, KC_PGUP, _______,                        _______, _______, KC_UP  , _______, _______, _______,
        _______ , _______, KC_DEL , KC_END , KC_PGDN, _______,                        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______ , _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            NK_ON  , NK_OFF ,
                                   _______, _______, _______,                        _______, _______, _______

    ),
};

enum combos {
  WB_BKSL,
  SS_CAPS,
  CS_RALT,
  GE_MENU,
};

const uint16_t PROGMEM combo_bksl[] = {KC_LWIN, KC_LBRC, COMBO_END};
const uint16_t PROGMEM combo_caps[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM combo_ralt[] = {KC_LCTL, KC_SPC , COMBO_END};
const uint16_t PROGMEM combo_menu[] = {KC_LGUI, KC_ENT , COMBO_END};

combo_t key_combos[] = {
    [WB_BKSL] = COMBO(combo_bksl, KC_BSLS),
    [SS_CAPS] = COMBO(combo_caps, KC_CAPS),
    [CS_RALT] = COMBO(combo_ralt, KC_RALT),
    [GE_MENU] = COMBO(combo_menu, KC_MENU),
};
