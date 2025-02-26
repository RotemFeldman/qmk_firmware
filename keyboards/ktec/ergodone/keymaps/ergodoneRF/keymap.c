#include QMK_KEYBOARD_H
#include "version.h"


#define BASE 0
#define SYMB 1
#define MDIA 2
#define GAME 3


enum {
    TD_1,
    TD_2,
    TD_3,
    TD_4,
    TD_5,
    TD_6,
    TD_7,
    TD_8,
    TD_9,
    TD_0,
    //TD_E,
    //TD_R,
    //TD_D,
    //TD_F,
    //TD_C,
    //TD_V,
	TD_ESC,
};
// Custom keycodes
enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_EXLM),
    [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_AT),
    [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_HASH),
    [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_DLR),
    [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_PERC),
    [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_CIRC),
    [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_AMPR),
    [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_ASTR),
    [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LPRN),
    [TD_0] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RPRN),
    //[TD_E] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_LCBR),
    //[TD_R] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_RCBR),
    //[TD_D] = ACTION_TAP_DANCE_DOUBLE(KC_D, KC_LPRN),
    //[TD_F] = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_RPRN),
    //[TD_C] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_LBRC),
    //[TD_V] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_RBRC),
	[TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC,KC_CAPS),
};



// Keymap definition
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * Layer 0: Default Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  ESC   |  1/3  |  2/3  |  3/3  |  4/3  |  5/3  | Ctrl+Z |           | Right |  6/3  |  7/3  |  8/3  |  9/3  |  0/3  | L1  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  Del   |   Q   |   W   |  E/3  |  R/3  |   T    | Left  |           | L1   |   Y   |   U   |   I   |   O   |   P   |  \   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  TAB   |   A   |   S   |  D/3  |  F/3  |   G    |------|           |------|   H   |   J   |   K   |   L   |; / L2|' / Cmd |
     * |--------+------+------+------+------+------| LSFT |           | LSFT |------+------+------+------+------+--------|
     * | LShift |Z/Ctrl |   X   |  C/3  |  V/3  |   B    |------|           |------|   N   |   M   |   ,   |   .   | /Ctrl| RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |Grv/L1| GUI/L2|AltShf | Left  | Right |                                       |  Up  | Down |   [   |   ]   | L1  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                      | Ctrl  | LALT |       | Alt  | Ctrl  |
     *                                 ,------|------|------|       |------+--------+------.
     *                                 | Home |      |      |       |      |        |      |
     *                                 | Space| LSFT |------|       |------|  Tab   |Enter |
     *                                 |      |      | End  |       | PgDn |        |      |
     *                                 `--------------------'       `----------------------'
     */
    [BASE] = LAYOUT_ergodox(
        TD(TD_ESC),  TD(TD_1),  TD(TD_2),  TD(TD_3),    TD(TD_4),    TD(TD_5),         TG(1),
        KC_DEL,  KC_Q,        KC_W,        KC_E,    KC_R,    KC_T,        ALL_T(KC_EQL),
        KC_TAB,  LGUI_T(KC_A),        LALT_T(KC_S),        LSFT_T(KC_D),    LCTL_T(KC_F),    KC_G,
        KC_LSFT, LCTL_T(KC_Z), KC_X,       KC_C,    KC_V,    KC_B,        KC_LEFT,
        LT(1, KC_GRV), LT(2, KC_LGUI), LALT(KC_LSFT), KC_LEFT, KC_RGHT,

											KC_LCTL, KC_LALT,
													 KC_HOME,
									KC_SPC, KC_LSFT, KC_END,

        TG(1),      TD(TD_6),         TD(TD_7),         TD(TD_8),         TD(TD_9),         TD(TD_0),         TG(3),
        MEH_T(KC_MINS),      KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_BSLS,
                      KC_H,        RCTL_T(KC_J),        RSFT_T(KC_K),        RALT_T(KC_L),        LT(2, KC_SCLN), LGUI_T(KC_QUOT),
        KC_RGHT,       KC_N,        KC_M,        KC_COMM,     KC_DOT,      RCTL_T(KC_SLSH),      KC_RSFT,
                                    KC_UP,       KC_DOWN,     KC_LBRC,     KC_RBRC,      TT(1),

        KC_TAB,   MO(1),
        KC_PGUP,
        KC_PGDN,  KC_BSPC,  KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  | TO(3)  |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EE_CLR  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |LCRL  |LSFT  |      |       |      |Hue-  |Hue+  |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EE_CLR,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_LCTL,KC_LSFT,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
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
/* Keymap 3: Gaming Layer
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
       KC_NO,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TG(BASE),
       KC_NO,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
                       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_NO,
       KC_DEL,         KC_N,           KC_M,           KC_UP,          KC_DOT,         KC_SLSH,        KC_NO,
                                      KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_NO,          KC_NO,
       KC_NO,          KC_NO,
       KC_NO,
       KC_LGUI,        KC_BSPC,        KC_ENT
)
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
    case VRSN:
        if (record->event.pressed) {
            SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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


