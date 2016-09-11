#include "keymap_common.h"

/*
 * Morgan
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default Layer
     * ,-----------------------------------------------------------.
     * |GRV|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  Bspc |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|\    |
     * |-----------------------------------------------------------|
     * |CAPS  |  A|  S|  D|  F|  G|  H|  J|  K|  L|SCLN|  '|ENT    |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|SLSH|Shift    |
     * |-----------------------------------------------------------|
     * |Ctrl |Alt |GUI  |       Space            |FN1   |Alt |Gui  |
     * `-----------------------------------------------------------'
     */
    [0] = KEYMAP_AEK( \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        KC_LOCKING_CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN, QUOT,ENT, \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH, RSFT, \
        LCTL,LALT,LGUI,          FN4,                          FN1,RALT, RGUI),

    /* Apple FN + Others Layer [RGui]
     * ,-----------------------------------------------------------.
     * |Esc|Mut|VolD|VolU|MPRV|MPLY|MNXT|  7|  8|  9|  0|  -|  +|  Bspc |
     * |-----------------------------------------------------------|
     * |Tab  |   | Up|   |Hom|   |   |  4|  5|  6|  *|Up |   |Del  |
     * |-----------------------------------------------------------|
     * |CAPS |Lef|Dow|Rig|End|   |   |  1|  2|   3|  /|   |Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |   |   |   |   |   |   |F16|   |   |   |Shift     |
     * |-----------------------------------------------------------|
     * |Ctrl |Alt |Gui  |       Space            |FN1   |Alt |Gui  |
     * `-----------------------------------------------------------'
     */
    [1] = KEYMAP_AEK( \
        GRV,MUTE,VOLD,VOLU,MPRV,MPLY,MNXT,   7,   8,   9,    0,MINS,PPLS, BSPC, \
        TAB,NO,  UP,  NO,HOME,  NO,  NO,   4,     5,   6,PAST,UP,  NO,  DEL, \
        TRNS,LEFT,DOWN,RGHT,END,  NO,    NO,   1,   2,   3,PSLS,  NO,TRNS, \
        LSFT,NO,  NO,  NO,  NO,  NO,    NO, F16,  NO,   NO,  NO,RSFT, \
        LCTL,LALT,LGUI,          TRNS,                         FN1,RALT,RGUI),
};


/* id for user defined function/macro */
enum function_id {
    NONE,
};

enum macro_id {
    ALT_TAB,
};


/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),                  // Default Layer
    [1] = ACTION_LAYER_TOGGLE(1, FN1),          // Apple FN + Others Layer
};


/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case ALT_TAB:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(TAB), END ) :
                    MACRO( U(TAB), END ));
    }
    return MACRO_NONE;
}
