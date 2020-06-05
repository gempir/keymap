#include QMK_KEYBOARD_H

enum custom_keycodes {
    M_AE = SAFE_RANGE,
    M_OE,
    M_UE,
    M_ESZ,
    M_MU,
    M_EUR,
    M_DAC,
    M_DGRA,
    M_DCIR,
    M_PND,
    M_YEN,
    M_DEG
};

// setxkbmap -option compose:ralt

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case M_AE:
                SEND_STRING(SS_RALT(SS_LSFT("'"))"a");
                return false;
            case M_OE:
                SEND_STRING(SS_RALT(SS_RSFT("'"))"o");
                return false;
            case M_UE:
                SEND_STRING(SS_RALT(SS_RSFT("'"))"u");
                return false;
            case M_ESZ:
                SEND_STRING(SS_RALT("ss"));
                return false;
            case M_MU:
                SEND_STRING(SS_RALT("/u"));
                return false;
            case M_EUR:
                SEND_STRING(SS_RALT("c="));
                return false;
            case M_DAC:
                SEND_STRING(SS_RALT("'"));
                return false;
            case M_DGRA:
                SEND_STRING(SS_RALT("`"));
                return false;
            case M_DCIR:
                SEND_STRING(SS_RALT("^"));
                return false;
            case M_PND:
                SEND_STRING(SS_RALT("l-"));
                return false;
            case M_YEN:
                SEND_STRING(SS_RALT("y="));
                return false;
            case M_DEG:
                SEND_STRING(SS_RALT("0*"));
                return false;
        }
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ansi(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_DEL, KC_HOME,
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_PGUP, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN, 
		LT(1,KC_NO), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_END, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MPLY, KC_UP, LT(1,KC_NO), 
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_MPRV, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT
		),
	[1] = LAYOUT_ansi(
		RGB_TOG, RGB_RMOD, RGB_MOD, RGB_VAD, RGB_VAI, RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI, RGB_SPD, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_NO, RESET, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, DEBUG, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, M_UE , KC_NO, KC_NO, KC_NO, 
		LT(1,KC_NO), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, M_OE, M_AE, LCTL(KC_ENT), KC_NO, 
		KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_VOLU, LT(1,KC_NO),
		KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MNXT, KC_MPRV, KC_VOLD, KC_MNXT
		)
};