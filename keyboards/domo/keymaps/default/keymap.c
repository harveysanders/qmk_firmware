#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Keymap 0: (Base Layer) Default Layer
    [0] = LAYOUT(
        KC_HOME, KC_END, KC_PGUP,
        KC_DEL, KC_UP, KC_PGDOWN,
        KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
