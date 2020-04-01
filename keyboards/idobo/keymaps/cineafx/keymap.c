/* Copyright 2018 MechMerlin
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

//PTTTGL: Push to talk toggle
enum ptt_states {
    OFF,
    ON
};
int ptt_state = OFF;

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  PTTTGL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT_ortho_5x15( \
     KC_F13, KC_F14, KC_F15, MI_C_4 , MI_Cs_4, MI_D_4 , MI_Ds_4, MI_E_4 , MI_F_4 , MI_Fs_4, MI_G_4 , MI_Gs_4, MI_A_4 , MI_As_4, MI_B_4 ,  \
     KC_F16, KC_F17, KC_F18, MI_C_3 , MI_Cs_3, MI_D_3 , MI_Ds_3, MI_E_3 , MI_F_3 , MI_Fs_3, MI_G_3 , MI_Gs_3, MI_A_3 , MI_As_3, MI_B_3 ,  \
     KC_F19, KC_F20, KC_F21, MI_C_2 , MI_Cs_2, MI_D_2 , MI_Ds_2, MI_E_2 , MI_F_2 , MI_Fs_2, MI_G_2 , MI_Gs_2, MI_A_2 , MI_As_2, MI_B_2 ,  \
     KC_F22, KC_F23, KC_F24, MI_C_1 , MI_Cs_1, MI_D_1 , MI_Ds_1, MI_E_1 , MI_F_1 , MI_Fs_1, MI_G_1 , MI_Gs_1, MI_A_1 , MI_As_1, MI_B_1 , \
    KC_BTN5, PTTTGL, KC_ESC, MI_C   , MI_Cs  , MI_D   , MI_Ds  , MI_E   , MI_F   , MI_Fs  , MI_G   , MI_Gs  , MI_A   , MI_As  , MI_B    \
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PTTTGL:
      if (record->event.pressed) {
        if (ptt_state == ON) {  // it is 1, so you were talking and want to switch it off
          ptt_state = OFF;       // set the new state to OFF
          unregister_code(KC_BTN5);  // toggle M5 off
        } else {  // it is not ON, so you want to talk
          ptt_state = ON;   // set the state to ON
          register_code(KC_BTN5);  // toggle M5 on
        }
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

/*
 [0] = LAYOUT_ortho_5x15( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,  \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,  KC_PGUP, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_RCTL, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),
*/
