#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols layer
#define MDIA 2 // media keys layer
#define BRKT 3 // brackets layer
#define GAME 4 // gaming layer

enum custom_keycodes {
  VRSN = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1   |   2   |   3   |   4   |   5   | Ctrl+Z|           |Ctrl+Y |   6   |   7   |   8   |   9   |   0   |  TG(1) |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E   |   R   |   T  | Left |           | Right|   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D   |   F   |   G  |------|           |------|   H  |   J  |   K  |   L  |;/L2  |'/LGui  |
 * |--------+------+------+------+------+------| Minus|           | Equal|------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C   |   V   |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|Gui/L2|AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | TT(1) |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LCtrl| LAlt |       | Tab  | L1   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|LShift|------|       |------|BackSpc | Enter|
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_ESC,         MT(MOD_LSFT, KC_1),  MT(MOD_LSFT, KC_2),  MT(MOD_LSFT, KC_3),  MT(MOD_LSFT, KC_4),  MT(MOD_LSFT, KC_5),  LCTL(KC_Z),
        KC_DEL,         KC_Q,                 KC_W,                 LT(BRKT,KC_E),      LT(BRKT,KC_R),      KC_T,                KC_LEFT,
        KC_TAB,         KC_A,                 KC_S,                 LT(BRKT,KC_D),      LT(BRKT,KC_F),      KC_G,
        KC_LSFT,        LCTL_T(KC_Z),         KC_X,                 LT(BRKT,KC_C),      LT(BRKT,KC_V),      KC_B,                KC_MINS,
        LT(SYMB,KC_GRV),LT(MDIA,KC_LGUI),     LALT(KC_LSFT),        KC_LEFT,            KC_RGHT,
                                                                                         KC_LCTL,            KC_LALT,
                                                                                                             KC_HOME,
                                                                        KC_SPC,          KC_LSFT,            KC_END,
        // right hand
             LCTL(KC_Y),    MT(MOD_LSFT, KC_6),  MT(MOD_LSFT, KC_7),  MT(MOD_LSFT, KC_8),  MT(MOD_LSFT, KC_9),  MT(MOD_LSFT, KC_0),  TG(SYMB),
             KC_RGHT,       KC_Y,                 KC_U,                 KC_I,                 KC_O,                 KC_P,                 KC_BSLS,
                            KC_H,                 KC_J,                 KC_K,                 KC_L,                 LT(MDIA,KC_SCLN),     LGUI_T(KC_QUOT),
             KC_EQL,        KC_N,                 KC_M,                 KC_COMM,              KC_DOT,               KC_SLSH,              KC_RSFT,
                                                  KC_UP,                KC_DOWN,              KC_LBRC,              KC_RBRC,              TT(SYMB),
             KC_TAB,        MO(SYMB),
             KC_PGUP,
             KC_PGDN,       KC_BSPC,              KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  TO(4)  |  F1  |  F2  |  F3  |  F4  |  F5  | Trns |           | Trns |  F6  |  F7  |  F8  |  F9  |  F10 |  Trns  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |   Trns  |   !  |   @  |   {  |   }  |   |  | Trns |           | Trns |  Up  |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Trns  |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |  Trns  |
 * |---------+------+------+------+------+------| Trns |           | Trns |------+------+------+------+------+--------|
 * |   Trns  |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   /  |  Trns  |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EE_CLR |  Trns|  Trns|  Trns|  Trns|                                       | Trns |  .   |   0  |   =  |  Trns |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Trns | LAlt |       | Trns | Trns |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Trns |       | Trns |      |      |
 *                                 |GUI+S | LSft |------|       |------|Trns  | Trns |
 *                                 |      |      | Trns |       | Trns |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
       // left hand
       TO(GAME),      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRNS,
       KC_TRNS,       KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRNS,
       KC_TRNS,       KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRV,
       KC_TRNS,       KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,        KC_TRNS,
          EE_CLR,     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                       KC_TRNS,        KC_LALT,
                                                                                                       KC_TRNS,
                                                               SGUI(KC_S),             KC_LSFT,        KC_TRNS,
       // right hand
       KC_TRNS,       KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRNS,
       KC_TRNS,       KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
                      KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRNS,
       KC_TRNS,       KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_SLSH,        KC_TRNS,
                                      KC_TRNS,        KC_DOT,         KC_0,           KC_EQL,         KC_TRNS,
       KC_TRNS,       KC_TRNS,
       KC_TRNS,
       KC_TRNS,       KC_TRNS,        KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Trns  |Accel0|Accel1|Accel2| Trns | Trns | Trns |           | Trns | Trns | Trns | Trns |Shift+| F3   |  Trns  |
 * |---------+------+------+------+------+-------+-----|           |------+------+------+------+------+------+--------|
 * |   Trns  | Trns | Trns |MS_UP | Trns |WhUp  | Trns |           |Shift+| Trns | Trns | Trns | Trns | Trns |  Trns  |
 * |---------+------+------+------+------+-------|     |           | Del  |------+------+------+------+------+--------|
 * |   Trns  | Trns |MS_LFT|MS_DWN|MS_RGT|WhDown|-----|           |------|      |      |      |      |      |  Play  |
 * |---------+------+------+------+------+-------|Trns |           |C+S+/ |------+------+------+------+------+--------|
 * |   LSft  | Trns | Trns | Trns | Trns |      |     |           |      | Trns | Trns | Trns | Prev | Next |  Trns  |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Trns |  Trns| Trns |MsBtn1|MsBtn2|                                       | Vol+ | Vol- | Mute | Trns |  Trns |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Trns | Trns |       | Trns | Trns |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Trns |       | Trns |      |      |
 *                                 |MsBtn1|MsBtn2|------|       |------|WebFwd|WebBck|
 *                                 |      |      | Trns |       | Trns |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,        KC_ACL0,        KC_ACL1,        KC_ACL2,        KC_TRNS,        KC_TRNS,        KC_TRNS,
       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_MS_U,        KC_TRNS,        KC_WH_U,        KC_TRNS,
       KC_TRNS,        KC_TRNS,        KC_MS_L,        KC_MS_D,        KC_MS_R,        KC_WH_D,
       KC_LSFT,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_BTN1,        KC_BTN2,
                                                                                         KC_TRNS,       KC_TRNS,
                                                                                                        KC_TRNS,
                                                                         KC_BTN1,        KC_BTN2,       KC_TRNS,
       // right hand
       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        LSFT(KC_F3),    KC_F3,          KC_TRNS,
       LSFT(KC_DEL),   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_MPLY,
       RCS(KC_SLSH),   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_MPRV,        KC_MNXT,        KC_TRNS,
                                       KC_VOLU,        KC_VOLD,        KC_MUTE,        KC_TRNS,        KC_TRNS,
       KC_TRNS,        KC_TRNS,
       KC_TRNS,
       KC_TRNS,        KC_WFWD,        KC_WBAK
),
/* Keymap 3: Brackets Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   NO    |Shift+1|Shift+2|Shift+3|Shift+4|Shift+5|  NO  |           |  NO  |Shift+6|Shift+7|Shift+8|Shift+9|Shift+0|  NO   |
 * |---------+-------+-------+-------+-------+-------+------|           |------+-------+-------+-------+-------+-------+-------|
 * |   NO    |  NO   |  NO   |Shift+[|   ]   |  NO   |  NO  |           |  NO  |  NO   |  NO   |  NO   |  NO   |  NO   |  NO   |
 * |---------+-------+-------+-------+-------+-------|      |           |      |-------+-------+-------+-------+-------+-------|
 * |   NO    |  NO   |  NO   |Shift+9|Shift+0|  NO   |------|           |------|  NO   |  NO   |  NO   |  NO   |  NO   |  NO   |
 * |---------+-------+-------+-------+-------+-------|  NO  |           |  NO  |-------+-------+-------+-------+-------+-------|
 * |   NO    |  NO   |  NO   |   [   |   ]   |  NO   |      |           |      |  NO   |  NO   |  NO   |  NO   |  NO   |  NO   |
 * `---------+-------+-------+-------+-------+---------------'           `---------------+-------+-------+-------+-------+-------'
 *   |  NO   |  NO   |  NO   |  NO   |  NO   |                                           |  NO   |  NO   |  NO   |  NO   |  NO   |
 *   `-------------------------------------'                                             `-------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  NO  |  NO  |       |  NO  |  NO  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  NO  |       |  NO  |      |      |
 *                                 |  NO  |  NO  |------|       |------|  NO  |  NO  |
 *                                 |      |      |  NO  |       |  NO  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BRKT] = LAYOUT_ergodox(
       // left hand
       KC_NO,          LSFT(KC_1),     LSFT(KC_2),     LSFT(KC_3),     LSFT(KC_4),     LSFT(KC_5),     KC_NO,
       KC_NO,          KC_NO,          KC_NO,          LSFT(KC_LBRC),  LSFT(KC_RBRC),        KC_NO,          KC_NO,
       KC_NO,          KC_NO,          KC_NO,          LSFT(KC_9),     LSFT(KC_0),     KC_NO,
       KC_NO,          KC_NO,          KC_NO,          KC_LBRC,        KC_RBRC,        KC_NO,          KC_NO,
       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                        KC_NO,          KC_NO,
                                                                                                        KC_NO,
                                                                        KC_NO,          KC_NO,          KC_NO,
       // right hand
       KC_NO,          LSFT(KC_6),     LSFT(KC_7),     LSFT(KC_8),     LSFT(KC_9),     LSFT(KC_0),     KC_NO,
       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                      KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,
       KC_NO,          KC_NO,
       KC_NO,
       KC_NO,          KC_NO,          KC_NO
),
/* Keymap 4: Gaming Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC   |   1  |   2  |   3  |   4  |   5  |   6  |           |  NO  |   6  |   7  |   8  |   9  |   0  | TO(0)  |
 * |---------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab   |   T  |   Q  |   W  |   E  |   R  |  .   |           |  NO  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LShift |   G  |   A  |   S  |   D  |   F  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   NO   |
 * |---------+------+------+------+------+------|  ,   |           | Del  |------+------+------+------+------+--------|
 * |  LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  Up  |   .  |   /  |   NO   |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl |  NO  | LAlt | Left | Right|                                       | Left | Down | Right|  NO  |  NO   |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  NO  |  NO  |       |  NO  |  NO  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  NO  |       |  NO  |      |      |
 *                                 | Space|LShift|------|       |------|LGUI  |Enter |
 *                                 |      |      |  NO  |       |  NO  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[GAME] = LAYOUT_ergodox(
       // left hand
       KC_ESC,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,
       KC_TAB,         KC_T,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_DOT,
       KC_LSFT,        KC_G,           KC_A,           KC_S,           KC_D,           KC_F,
       KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_COMM,
       KC_LCTL,        KC_NO,          KC_LALT,        KC_LEFT,        KC_RGHT,
                                                                                         KC_NO,         KC_NO,
                                                                                                        KC_NO,
                                                                         KC_SPC,         KC_LSFT,       KC_NO,
       // right hand
       KC_NO,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TO(BASE),
       KC_NO,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
                       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_NO,
       KC_DEL,         KC_N,           KC_M,           KC_UP,          KC_DOT,         KC_SLSH,        KC_NO,
                                      KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_NO,          KC_NO,
       KC_NO,          KC_NO,
       KC_NO,
       KC_LGUI,        KC_BSPC,        KC_ENT
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};