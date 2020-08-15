#include QMK_KEYBOARD_H

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define LAYER_QWERTY 0
#define LAYER_FUNCTION 5

enum custom_keycodes {
	KX_UMLAUT_A = SAFE_RANGE,
	KX_UMLAUT_O,
	KX_UMLAUT_U,
	KX_UMLAUT_S,
	KX_EURO,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	static uint8_t shift_mask;
	shift_mask = get_mods()&MODS_SHIFT_MASK;
    set_unicode_input_mode(UC_LNX);

	if (record->event.pressed) {
		switch(keycode) {
		case KX_UMLAUT_A:
			if (shift_mask) { // We want a capital version of the German A Umlaut 'cause shift is pressed
                send_unicode_string("Ä");
			} else {
				send_unicode_string("ä");
			}
			return false;
		case KX_UMLAUT_O:
			if (shift_mask) {
				send_unicode_string("Ö");
			} else {
                send_unicode_string("ö");
			}
			return false;
		case KX_UMLAUT_U:
			if (shift_mask) {
                send_unicode_string("Ü");
			} else {
				send_unicode_string("ü");
            }
			return false;
		case KX_UMLAUT_S:
			send_unicode_string("ß");
			return false;
		case KX_EURO:
			send_unicode_string("€");
			return false;
        }
	}

	return true;
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_QWERTY] = LAYOUT(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_DEL, KC_HOME,
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, _______, KC_BSPC, KC_PGUP,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN,
		LT(LAYER_FUNCTION,KC_NO), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_END,
		KC_LSFT, _______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, LT(LAYER_FUNCTION,KC_NO),
		KC_LCTL, KC_LGUI, KC_LALT, _______, KC_SPC, _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_LEFT, KC_DOWN, KC_RGHT
	),
	[LAYER_FUNCTION] = LAYOUT(
		RGB_TOG, RGB_RMOD, RGB_MOD, RGB_VAD, RGB_VAI, RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI, RGB_SPD, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_NO, RESET,
		KC_NO, KC_NO, KC_NO, KC_NO, KX_UMLAUT_S, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______, KC_DEL, DEBUG,
		KC_NO, KC_NO, KC_UP, KX_EURO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KX_UMLAUT_U, KC_NO, KC_NO, KC_NO,
		LT(LAYER_FUNCTION,KC_NO), KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KX_UMLAUT_O, KX_UMLAUT_A, LCTL(KC_ENT), KC_NO,
		KC_LSFT, _______, KC_NO, KC_NO, KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT, KC_VOLU, LT(LAYER_FUNCTION,KC_NO),
		KC_NO, KC_NO, KC_NO, _______, KC_ENT, _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_MPRV, KC_VOLD, KC_MNXT
	),
};
