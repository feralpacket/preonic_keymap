/* Copyright 2021 Jeffrey Denton
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

enum preonic_layers {
  _QWERTY,
  _GAME,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  NUMPAD,
  LOWER = LT(_LOWER, KC_SPC),
  RAISE = LT(_RAISE, KC_SPC),
  BACKLIT,
  SRS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Fn  |  OS  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_1x2uC(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  KC_LCTL, BACKLIT, KC_LGUI, KC_LALT, LOWER,       KC_SPC,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Game
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_preonic_1x2uC(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  KC_LCTL, KC_NO,   KC_NO,   KC_LALT, LOWER,       KC_SPC,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      | NUMLK|   /  |   *  |   -  |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tab |      |PRTSC |SCRLK |Pause |   7  |   8  |   9  |   +  |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Esc |      |  Ins | Home |PG UP |   4  |   5  |   6  |   +  |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |  Del |  End |PG DN |   1  |   2  |   3  |   =  |      |      |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |  Alt |Lower |      0      |Raise | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_1x2uC(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,   KC_NO,   KC_NO,   KC_DEL,
  KC_TAB,  KC_NO,   KC_PSCR, KC_SLCK, KC_PAUS, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,   KC_NO,   KC_BSPC,
  KC_ESC,  KC_NO,   KC_INS,  KC_HOME, KC_PGUP, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_NO,   KC_NO,   KC_NO,
  KC_LSFT, KC_NO,   KC_DEL,  KC_END,  KC_PGDN, KC_P1,   KC_P2,   KC_P3,   KC_EQL,  KC_NO,   KC_NO,   KC_SFTENT,
  KC_LCTL, KC_NO,   KC_NO,   KC_LALT, LOWER,        KC_P0,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |M BTN1| M UP |M BTN2|M BTN3|      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |M LEFT| M DN |M RGT |      |      |      | Prev |      |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_1x2uC(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  KC_NO,   KC_NO,   KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_NO,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  KC_NO,   KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   KC_NO,   KC_NO,   KC_MPRV, KC_MUTE, KC_NO,   KC_ENT,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,      KC_SPC,      KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

 /* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |PRTSC |SCRLK |Pause |      |      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Ins  | Home |PG UP |      |      |      |      | Prev |      |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Del  | End  |PG DN |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_1x2uC(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
  KC_NO,   KC_PSCR, KC_SLCK, KC_PAUS, KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  KC_NO,   KC_INS,  KC_HOME, KC_PGUP, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPRV, KC_MUTE, KC_NO,   KC_ENT,
  KC_NO,   KC_DEL,  KC_END,  KC_PGDN, KC_TRNS,     KC_SPC,       KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset| Debug|Aud on|AudOff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Qwerty|MusCyc|Mus on|MusOff|MidiOn|MidOff|TermOn|TerOff| aPscr| sPscr| Pscr |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |Voice-|Voice+|      |      | Game |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |LEADER|Numpad|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_1x2uC(
  KC_NO,   RESET,   DEBUG,   AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   
  KC_NO,   QWERTY,  MU_MOD,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF,LALT(KC_PSCR), LCTL(KC_PSCR), KC_PSCR,
  KC_CAPS, MUV_DE,  MUV_IN,  KC_NO,   KC_LEAD, GAME,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   RGB_TOG, RGB_MOD, SRS,     NUMPAD,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,      KC_SPC,      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case GAME:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_GAME);
          }
          return false;
          break;
        case NUMPAD:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_NUMPAD);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          // return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          // return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
        case SRS:
          if (record->event.pressed) {
            // when keycode SRS is pressed
            SEND_STRING("show running-config | section ");
          } else {
            // when keycode SRS is released
          }
		  return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
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
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
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
            }
    }
}

bool did_leader_succeed;
#ifdef AUDIO_ENABLE
//float leader_start_song[][2] = SONG(CHROMATIC_SOUND);
float leader_start_song[][2] = SONG(NO_SOUND);
float leader_succeed_song[][2] = SONG(STARTUP_SOUND);
//float leader_fail_song[][2] = SONG(GOODBYE_SOUND);
float leader_fail_song[][2] = SONG(NO_SOUND);
#endif

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    did_leader_succeed = leading = false;
    leading = false;
    leader_end();
/*
 *  configure aliases
 */
    SEQ_TWO_KEYS(KC_C, KC_T) {
      // alias exec ct configure terminal
      SEND_STRING("configure terminal ");
	  did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_R, KC_B) {
      // alias configure rb router bgp
	  // incomplete command by itself
      SEND_STRING("router ospf bgp ? ");
	  did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_R, KC_E) {
      // alias configure re router eigrp
	  // incomplete command by itself
      SEND_STRING("router eigrp ? ");
	  did_leader_succeed = true;
    }	
    SEQ_TWO_KEYS(KC_R, KC_O) {
      // alias configure ro router ospf
	  // incomplete command by itself
      SEND_STRING("router ospf ? ");
	  did_leader_succeed = true;
    }
      // looking for do show commands?  type "do <leader-key> alias"
/*
 *  show running-config aliases
 */
    SEQ_TWO_KEYS(KC_S, KC_R) {
      // alias exec sr show running-config
      SEND_STRING("show running-config ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_R, KC_B) {
      // alias exec srb show running-config | begin
	  // % Incomplete command
      SEND_STRING("show running-config | begin ? ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_R, KC_I) {
      // alias exec sri show running-config | include
	  // % Incomplete command
      SEND_STRING("show running-config | include ? ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_R, KC_S) {
      // alias exec srs show running-config | section
	  // % Incomplete command
      SEND_STRING("show running-config | section ? ");
	  did_leader_succeed = true;
    }	
    SEQ_FIVE_KEYS(KC_S, KC_R, KC_I,KC_N,KC_T) {
      // alias exec srint show running-config interface
	  // % Incomplete command
	  // doesn't follow the one letter for each word convention
	  // conflicted with the key sequence used for show running-config | include
      SEND_STRING("show running-config interface ? ");
	  did_leader_succeed = true;
    }	
    SEQ_FIVE_KEYS(KC_S, KC_R, KC_A, KC_A, KC_A) {
      // alias exec sraaa show running-config | include aaa|auth|radius|tacacs
      SEND_STRING("show running-config | include aaa|auth|radius|tacacs ");
	  did_leader_succeed = true;
    }
/*
 *  general troubleshooting aliases
 */
    SEQ_TWO_KEYS(KC_S, KC_V) {
      // alias exec sv show version
      SEND_STRING("show version ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_V, KC_R) {
      // alias exec svr show version | include reason|uptime
	  // doesn't follow the one letter for each word convention
      SEND_STRING("show version | include reason|uptime ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_I, KC_S) {
      // alias exec sis show interface status
      SEND_STRING("show interface status ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_I, KC_T) {
      // alias exec sit show interface trunk
      SEND_STRING("show interface trunk ");
	  did_leader_succeed = true;
	}
    SEQ_TWO_KEYS(KC_S, KC_E) {
      // alias exec se show etherchannel 
      SEND_STRING("show etherchannel ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_E, KC_S) {
      // alias exec ses show etherchannel summary
      SEND_STRING("show etherchannel summary ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_I, KC_I, KC_B) {
      // alias exec siib show ip interface brief
      SEND_STRING("show ip interface brief ");
	  did_leader_succeed = true;
	}
    SEQ_TWO_KEYS(KC_S, KC_C) {
      // alias exec sc show clock
      SEND_STRING("show clock ");
	  did_leader_succeed = true;
	}
    SEQ_TWO_KEYS(KC_S, KC_L) {
      // alias exec sl show logging
      SEND_STRING("show logging ");
	  did_leader_succeed = true;
	}
    SEQ_THREE_KEYS(KC_S, KC_I, KC_A) {
      // alias exec sia show ip arp
      SEND_STRING("show ip arp ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_M, KC_A) {
      // alias exec sma show mac address-table
      SEND_STRING("show mac address-table ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_I, KC_D, KC_S, KC_B) {
      // alias exec sidsb show ip dhcp snooping binding
      SEND_STRING("show ip dhcp snooping binding ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_P, KC_I) {
      // alias exec spi show power inline
      SEND_STRING("show power inline ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_C, KC_N) {
      // alias exec scn show cdp neighbor
      SEND_STRING("show cdp neighbor ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_D, KC_I, KC_F, KC_F) {
      // alias exec diff show archive config differences nvram:startup-config system:running-config
	  // doesn't follow the one letter for each word convention
      SEND_STRING("show archive config differences nvram:startup-config system:running-config ");
	  did_leader_succeed = true;
	}
/*
 *  routing aliases
 */
    SEQ_THREE_KEYS(KC_S, KC_I, KC_P) {
      // alias exec sip show ip protocol
      SEND_STRING("show ip protocol ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_I, KC_R) {
      // alias exec sir show ip route
      SEND_STRING("show ip route ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_I, KC_B) {
      // alias exec sib show ip bgp
      SEND_STRING("show ip bgp ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_I, KC_B, KC_N) {
      // alias exec sibn show ip bgp neighbors
      SEND_STRING("show ip bgp neighbors ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_I, KC_B, KC_S) {
      // alias exec sibs show ip bgp summary
      SEND_STRING("show ip bgp summary ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_B, KC_V, KC_U, KC_A) {
      // alias exec sbvua show bgp vpnv4 unicast all
      SEND_STRING("show bgp vpnv4 unicast all ");
	  did_leader_succeed = true;
	}
    SEQ_FIVE_KEYS(KC_S, KC_B, KC_V, KC_U, KC_V) {
      // alias exec sbvua show bgp vpnv4 unicast vrf
	  // % Incomplete command
      SEND_STRING("show bgp vpnv4 unicast vrf ? ");
	  did_leader_succeed = true;
	}
    SEQ_THREE_KEYS(KC_S, KC_I, KC_E) {
      // alias exec sie show ip eigrp
	  // % Incomplete command
      SEND_STRING("show ip eigrp ? ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_I, KC_E, KC_I) {
      // alias exec siei show ip eigrp interface
      SEND_STRING("show ip eigrp interface ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_I, KC_E, KC_N) {
      // alias exec sien show ip eigrp neighbors
      SEND_STRING("show ip eigrp neighbors ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_I, KC_E, KC_T) {
      // alias exec siet show ip eigrp topology
      SEND_STRING("show ip eigrp topology ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_I, KC_O) {
      // alias exec sio show ip ospf
      SEND_STRING("show ip ospf ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_I, KC_O, KC_D) {
      // alias exec siod show ip ospf database
      SEND_STRING("show ip ospf database ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_I, KC_O, KC_I) {
      // alias exec sioi show ip ospf interface
      SEND_STRING("show ip ospf interface ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_I, KC_O, KC_N) {
      // alias exec sion show ip ospf neighbor
      SEND_STRING("show ip ospf neighbor ");
	  did_leader_succeed = true;
    }
/*
 *  mpls aliases
 */
    SEQ_TWO_KEYS(KC_S, KC_M) {
      // alias exec sm show mpls
	  // % Incomplete command
      SEND_STRING("show mpls ? ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_M, KC_I) {
      // alias exec smi show mpls interface
      SEND_STRING("show mpls interface ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_M, KC_L) {
      // alias exec sml show mpls ldp
	  // % Incomplete command
      SEND_STRING("show mpls ldp ? ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_M, KC_L, KC_N) {
      // alias exec smln show mpls ldp neighbor
      SEND_STRING("show mpls ldp neighbor ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_M, KC_F) {
      // alias exec smf show mpls forwarding-table
      SEND_STRING("show mpls forwarding-table ");
	  did_leader_succeed = true;
    }
/*
 *  multicast aliases
 */
    SEQ_FOUR_KEYS(KC_S, KC_I, KC_P, KC_I) {
      // alias exec sipi show ip pim interface
      SEND_STRING("show ip pim interface ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_I, KC_P, KC_N) {
      // alias exec sipn show ip pim neighbor
      SEND_STRING("show ip pim neighbor ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_I, KC_P, KC_R) {
      // alias exec sipr show ip pim rp
      SEND_STRING("show ip pim rp ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_I, KC_M) {
      // alias exec sim show ip mroute
      SEND_STRING("show ip mroute ");
	  did_leader_succeed = true;
    }
/*
 *  device-tracking aliases
 */
    SEQ_THREE_KEYS(KC_S, KC_D, KC_D) {
      // alias exec sdd show device-tracking database
      SEND_STRING("show device-tracking database ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_D, KC_D, KC_I) {
      // alias exec sddi show device-tracking database interface
      SEND_STRING("show device-tracking database interface ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_D, KC_D, KC_M) {
      // alias exec sddm show device-tracking database mac
      SEND_STRING("show device-tracking database mac ");
	  did_leader_succeed = true;
    }
/*
 *  lisp aliases
 */
    SEQ_THREE_KEYS(KC_S, KC_L, KC_I) {
      // alias exec sli show lisp interface-id
	  // % Incomplete command
      SEND_STRING("show lisp instance-id ? ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_L, KC_I, KC_I) {
      // alias exec slii show lisp interface-id * ipv4
      SEND_STRING("show lisp instance-id * ipv4 ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_L, KC_I, KC_I, KC_D) {
      // alias exec sliid show lisp interface-id * ipv4 database
      SEND_STRING("show lisp instance-id * ipv4 database ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_L, KC_I, KC_I, KC_M) {
      // alias exec sliim show lisp interface-id * ipv4 map-cache
      SEND_STRING("show lisp instance-id * ipv4 map-cache ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_L, KC_I, KC_I, KC_S) {
      // alias exec sliis show lisp interface-id * ipv4 server
      SEND_STRING("show lisp instance-id * ipv4 server ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_L, KC_I, KC_E) {
      // alias exec slie show lisp interface-id * ethernet
      SEND_STRING("show lisp instance-id * ethernet ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_L, KC_I, KC_E, KC_D) {
      // alias exec slied show lisp interface-id * ethernet database
      SEND_STRING("show lisp instance-id * ethernet database ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_L, KC_I, KC_E, KC_M) {
      // alias exec sliem show lisp interface-id * ethernet map-cache
      SEND_STRING("show lisp instance-id * ethernet map-cache ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_L, KC_I, KC_E, KC_A) {
      // alias exec sliea show lisp interface-id * ethernet address-resolution
      SEND_STRING("show lisp instance-id * ethernet address-resolution ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_L, KC_I, KC_E, KC_R) {
      // alias exec slier show lisp interface-id * ethernet address-resolution registration-history
	  // doesn't follow the one letter for each word convention
      SEND_STRING("show lisp instance-id * ethernet address-resolution registration-history ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_L, KC_S, KC_R) {
      // alias exec slsr show lisp server registration-history
      SEND_STRING("show lisp server registration-history ");
	  did_leader_succeed = true;
    }
/*
 *  sd-wan aliases
 */
    SEQ_TWO_KEYS(KC_S, KC_S) {
      // alias exec ss show sdwan ?
	  // % Incomplete command
      SEND_STRING("show sdwan ? ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_S, KC_C, KC_C) {
      // alias exec sscc show sdwan control connections
      SEND_STRING("show sdwan control connections ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_S, KC_C, KC_C, KC_H) {
      // alias exec sscch show sdwan control connection-history
      SEND_STRING("show sdwan control connection-history ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_S, KC_B, KC_H) {
      // alias exec ssbh show sdwan bfd history
      SEND_STRING("show sdwan bfd history ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_S, KC_B, KC_S) {
      // alias exec ssbs show sdwan bfd session
      SEND_STRING("show sdwan bfd session ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_S, KC_O, KC_P) {
      // alias exec ssop show sdwan omp peers
      SEND_STRING("show sdwan bfd session ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_S, KC_O, KC_R) {
      // alias exec ssor show sdwan omp routes
      SEND_STRING("show sdwan bfd session ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_S, KC_P, KC_A, KC_A) {
      // alias exec sspaa show sdwan policy access-list-associations
      SEND_STRING("show sdwan policy access-list-associations ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_S, KC_P, KC_A, KC_C) {
      // alias exec sspac show sdwan policy access-list-counters
      SEND_STRING("show sdwan policy access-list-counters ");
	  did_leader_succeed = true;
    }
    SEQ_FIVE_KEYS(KC_S, KC_S, KC_P, KC_F, KC_V) {
      // alias exec sspfv show sdwan policy from-vsmart
      SEND_STRING("show sdwan policy from-vsmart ");
	  did_leader_succeed = true;
    }
    SEQ_FOUR_KEYS(KC_S, KC_S, KC_S, KC_S) {
      // alias exec ssss show sdwan system status
      SEND_STRING("show sdwan system status ");
	  did_leader_succeed = true;
    }
    SEQ_THREE_KEYS(KC_S, KC_S, KC_R) {
      // alias exec ssr show sdwan running-config
      SEND_STRING("show sdwan running-config ");
	  did_leader_succeed = true;
    }
  }
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
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

void leader_start(void) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_start_song);
#endif
}

void leader_end(void) {
  if (did_leader_succeed) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_succeed_song);
#endif
  } else {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_fail_song);
#endif
  }
}
