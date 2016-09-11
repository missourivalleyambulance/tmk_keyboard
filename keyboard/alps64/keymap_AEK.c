#include "keymap_common.h"

/*
 * Hasu
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 0: DEFAULT LAYER
 * ,-----------------------------------------------------------.
 * |Esc  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  #|Bsp|
 * |-----------------------------------------------------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|DEL  |
 * |-----------------------------------------------------------|
 * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
 * |-----------------------------------------------------------|
 * |Shft|  \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Esc|
 * |-----------------------------------------------------------'
 * |Ctrl|ALT |GUI |      Space/FN1        |FN2  |GUI |FN3/Ctrl |
 * `-----------------------------------------------------------'
 */
[0] =KEYMAP_AEK( \
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,DEL, \
    LCAP,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,  \
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT, \
    LCTL,LALT,LGUI,          FN1,                     FN2, LGUI,FN3),

  /* 0: MORGAN LAYER
  * ,-----------------------------------------------------------.
  * |GRV  |MUTE|VOLD|VOLU|MPRV|MPLY|MNXT| 7| 8| 9| 0| -| =/#|Bsp|
  * |-----------------------------------------------------------|
  * |Tab  |  Q| UP|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
  * |-----------------------------------------------------------|
  * |Caps  |LEFT|DOWN|RIGHT|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
  * |-----------------------------------------------------------|
  * |Shft|  \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Esc|
  * |-----------------------------------------------------------'
  * |Ctrl|Gui |Alt |         Space              |FN2 |GUI |Ctrl |
  * `-----------------------------------------------------------'
  */
 [1] =KEYMAP_AEK( \
     GRV,MUTE,VOLD,VOLU,MPRV,MPLY,MNXT,   7,   8,   9,   0,   MINS,PPLS, BSPC, \
     TAB, Q,  UP,   E,HOME,   T,   Y,   4,   5,   6,PAST,   LBRC,RBRC,BSLS, \
     TRNS,LEFT,DOWN,RIGHT, END,   G,   H,   1,   2,   3,  PSLS,  QUOT,  ENT,  \
     LSFT,Z,   X,   C,   V,   B,   N, F13,   COMM,DOT, SLSH,RSFT, \
     LCTL,TRNS,TRNS,          TRNS,                     TRNS,TRNS,TRNS),

  /* 0: DEFAULT LAYER
   * ,-----------------------------------------------------------.
   * |Esc  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  #|Bsp|
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|DEL  |
   * |-----------------------------------------------------------|
   * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
   * |-----------------------------------------------------------|
   * |Shft|  \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Esc|
   * |-----------------------------------------------------------'
   * |Ctrl|ALT |GUI |      Space/FN1         |FN2 |FN3/GUI |Ctrl |
   * `-----------------------------------------------------------'
   */
  [2] =KEYMAP_AEK( \
   ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
   TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,DEL, \
   TRNS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,  \
   LSFT,Z,   X,   FN4,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT, \
   LCTL,LALT,LGUI,          TRNS,                     TRNS,TRNS,TRNS),

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
    [2]  = ACTION_LAYER_MOMENTARY(1),
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
