#include "keymap_common.h"

/*
 * HHKB
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 0: DEFAULT LAYER
 * ,-----------------------------------------------------------.
 * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -| =|BSLS|DEL|
 * |-----------------------------------------------------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|DEL  |
 * |-----------------------------------------------------------|
 * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
 * |-----------------------------------------------------------|
 * |Shft|  \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |FN2|
 * |-----------------------------------------------------------'
 * |    |GUI |ALT |      Space/FN1    |ALT  |GUI |    |        |
 * `-----------------------------------------------------------'
 */
[0] =KEYMAP( \
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS, DEL, \
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC, \
    LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,  \
    LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN2, \
    NO,LGUI,LALT,          FN1,                     LALT, LGUI,NO,NO),

  /* 0: MORGAN LAYER
  * ,-----------------------------------------------------------.
  * |GRV  |MUTE|VOLD|VOLU|MPRV|MPLY|MNXT| 7| 8| 9| 0| -|BSLS|DEL|
  * |-----------------------------------------------------------|
  * |Tab  |  Q| UP|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|DEL  |
  * |-----------------------------------------------------------|
  * |Caps|LEFT|DOWN|RIGHT|  F|  G|  H|  J|  K|  L|  ;|  '|Enter |
  * |-----------------------------------------------------------|
  * |Shft| \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |TRNS|
  * |-----------------------------------------------------------'
  * |    |TRNS |TRNS |         Space         |TRNS |TRNS|  |    |
  * `-----------------------------------------------------------'
  */
 [1] =KEYMAP( \
     GRV,MUTE,VOLD,VOLU,MPRV,MPLY,MNXT,   7,   8,   9,   0,   MINS,PPLS, TRNS, TRNS, \
     TAB, Q,  UP,   E,HOME,   T,   Y,   4,   5,   6,PAST,   LBRC,RBRC,TRNS, \
     CAPS,LEFT,DOWN,RIGHT, END,   G,   H,   1,   2,   3,  PSLS,  QUOT,  ENT,  \
     LSFT,NUBS,Z,   X,   C,   V,   B,   N, F13,   COMM,DOT, SLSH,RSFT,TRNS, \
     NO,TRNS,TRNS,          TRNS,                     TRNS, RALT,NO,NO),

  /* 0: DEFAULT LAYER
   * ,-----------------------------------------------------------.
   * |Esc  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  #|Bsp|
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|DEL  |
   * |-----------------------------------------------------------|
   * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
   * |-----------------------------------------------------------|
   * |Shft|\|  Z|  X|  FN4|  V|  B|  N|  M|  ,|  .|  /|Shift |FN2|
   * |-----------------------------------------------------------'
   * |    |TRNS /GUI |      Space/FN1    |TRNS |TRNS |        |     |
   * `-----------------------------------------------------------'
   */
  [2] =KEYMAP( \
   ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, TRNS, TRNS, \
   TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,TRNS, \
   CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,  \
   LSFT,NUBS,Z,   X,   FN4,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,TRNS, \
   NO,TRNS,TRNS,          TRNS,                     TRNS, TRNS,NO,NO),

};


/* id for user defined function/macro */
enum function_id {
    NONE,
};

enum macro_id {
    COPY_TAB_PASTE,
};


/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_MOMENTARY(1),                  // Default
    [1]  = ACTION_LAYER_TAP_KEY(1, KC_SPC),            // MORGAN LAYER
    [2]  = ACTION_LAYER_TOGGLE(1),
    [3]  = ACTION_LAYER_MOMENTARY(2),                  // CMD Layer
    [4]  = ACTION_MACRO(COPY_TAB_PASTE),               // Copy tab paste in browser
};


/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case COPY_TAB_PASTE:
            return (record->event.pressed ?
                    MACRO( D(LGUI), T(C), T(T), T(V), U(LGUI), T(ENT), END ) :
                    MACRO( END ) );
    }
    return MACRO_NONE;
}
