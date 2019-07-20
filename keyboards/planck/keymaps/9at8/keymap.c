/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _NAV,
  _NUM,
  _FN1,
  _ADJUST,

  _MAC,
  _MC_NAV,
  _MC_NUM,
  _MC_FN1
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,

  MC_NAV,
  WD_L,
  MC_WD_L,
  WD_R,
  MC_WD_R,

  MC_NUM,

  MC_FN1
};


#define MAC TG(_MAC)
#define NAV MO(_NAV)
#define NUM MO(_NUM)
#define FN1 MO(_FN1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn 1 | Ctrl | Alt  | GUI  |  NAV |    Space    |  NUM | Ctrl | Alt  | GUI  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    FN1,     KC_LCTL, KC_LALT, KC_LGUI, NAV,     KC_SPC,  KC_SPC,  NUM,     KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |MWH U | MS U |MWH D |      |      | WD L |  Up  | WD R |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |MWH L | MS L | MS D | MS R |MWH R | Pg U | Left | Down |Right | Pg D |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | MB 1 | MB 3 | MB 2 |      |      | Home |      | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    _______, XXXXXXX, KC_WH_U, KC_MS_U, KC_WH_D, XXXXXXX, XXXXXXX, WD_L,    KC_UP,   WD_R,    XXXXXXX, _______,
    _______, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_PGUP, KC_LEFT, KC_DOWN, KC_PGDN, XXXXXXX, _______,
    _______, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Num
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   ~  |      |      |      |   (  |   )  | 1  ! | 2  @ | 3  # | =  + | Ins  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      | Del  |      |   {  |   }  | 4  $ | 5  % | 6  ^ | -  _ | \  | |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Undo | Cut  | Copy |Paste |   [  |   ]  | 7  & | 8  * | 9  ( |   *  | PScr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | 0  ) |      |   /  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    KC_GRV,  KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_1,    KC_2,    KC_3,    KC_EQL,  KC_INS,
    _______, XXXXXXX, XXXXXXX, KC_DEL,  XXXXXXX, KC_LCBR, KC_RCBR, KC_4,    KC_5,    KC_6,    KC_MINS, KC_BSLS,
    _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, KC_LBRC, KC_RBRC, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_PSCR,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    XXXXXXX, KC_SLSH, XXXXXXX
),

/* Function 1
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |  V+  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  B-  |  V-  |  B+  |      |      |      |  Rev |Pause | Fwd  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN1] = LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, KC_BRID, KC_VOLD, KC_BRIU, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, _______
),

/* Adjust (Nav + Num)
 * ,-----------------------------------------------------------------------------------.
 * |      |Reset |Debug |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap| QWTY | MAC  |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  MAC,      _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Mac
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn 1 |      |      |      |MC_NAV|             |MC_NUM|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MAC] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    MC_FN1,  _______, _______, _______, MC_NAV,  _______, _______, MC_NUM,  _______, _______, _______, _______
),

/* Nav Mac
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | WD L |      | WD R |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MC_NAV] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, MC_WD_L, _______, MC_WD_R, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Num Mac
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MC_NUM] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Function 1 Mac
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Rev  |      | Fwd  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MC_FN1] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MRWD, _______, KC_MFFD, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _NAV, _NUM, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;

    case MC_NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
        layer_on(_MC_NAV);
      } else {
        layer_off(_NAV);
        layer_off(_MC_NAV);
      }
      return false;

    case MC_NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
        layer_on(_MC_NUM);
      } else {
        layer_off(_NUM);
        layer_off(_MC_NUM);
      }
      return false;

    case MC_FN1:
      if (record->event.pressed) {
        layer_on(_FN1);
        layer_on(_MC_FN1);
      } else {
        layer_off(_FN1);
        layer_off(_MC_FN1);
      }
      return false;

    /* Macros */
    /* Word left - Move one word left */
    case WD_L:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_LEFT) SS_UP(X_LCTRL));
      }
      return false;
    case MC_WD_L:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LALT));
      }
      return false;

    /* Word right - Move one word right */
    case WD_R:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_RIGHT) SS_UP(X_LCTRL));
      }
      return false;
    case MC_WD_R:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_UP(X_LALT));
      }
      return false;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_NUM)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case NUM:
    case NAV:
      return false;
    default:
      return true;
  }
}
