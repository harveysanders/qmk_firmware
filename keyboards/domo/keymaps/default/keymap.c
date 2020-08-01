#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: (Base Layer) Default Layer
     * ,-------------------.
     * |    |HOME|END |PGUP|
     * |    |----|----|----|
     * |    | TG | UP |PGDN|
     * |----|----|----|----|
     * | RO |LEFT|DOWN|RIGH|
     * `-------------------'
     *
     *  |                   | Home          | End  | Page Up   |
     *  |                   | Toggle: Layer | Up   | Page Down |
     *  | Rotary: Vol Dn/Up | Left          | Down | Right     |
     *    (Press: Mute)
     */
    [0] = LAYOUT(
        KC_MUTE, KC_HOME, KC_END, KC_PGUP,
        TG(1), KC_UP, KC_PGDOWN,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Keymap 1: Function Layer
     * ,-------------------.
     * |    |BACK|FORW|REFR|
     * |    |----|----|----|
     * |    | TG |CUT |COPY|
     * |----|----|----|----|
     * |TRNS|UNDO|REDO|PSTE|
     * `-------------------'
     *
     *  |             | Browser Back  | Browser Forward | Browser Refresh |
     *  |             | Toggle: Layer | Cut             | Copy            |
     *  | Transparent | Undo          | Redo            | Paste           |
     */
    [1] = LAYOUT(
        KC_TRNS, KC_WBAK, KC_WFWD, KC_WREF,
        TG(0), KC_CUT, KC_COPY,
        KC_UNDO, KC_AGAIN, KC_PASTE
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
