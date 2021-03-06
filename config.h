#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(IMPERIAL_MARCH)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(IMPERIAL_MARCH), \
				SONG(ZELDA_TREASURE), \
				SONG(CLOSE_ENCOUNTERS_5_NOTE) \
				}
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 2000
#define LEADER_KEY_STRICT_KEY_PROCESSING
