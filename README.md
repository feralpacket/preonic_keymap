# preonic_keymap
Keymap for the Preonic keyboard using the 1x2U layout

- Kept the planck number and symbol row.
- Changed Enter to KC_SFTENT, tap for Enter and hold for Shift.
- Swapped the Backspace and Delete key locations.
- Swapped the Alt and GUI key locations.
- Moved Ctrl to the corner of the keyboard.
- Move the F keys to the top row.
- Added a number pad layer.
- Added a game layer to remove the GUI key.
- Added basic mouse functions.
- Changed the layer songs in config.h.
- Created the user_song_list.h file.
- Removed the DVORAK and COLEMAK layers.
- Added a leader key modifier and configured sequences to mimic the Cisco alias commands.


### Helpful links
- https://github.com/qmk/qmk_firmware/tree/master/keyboards/preonic 
- https://github.com/qmk/qmk_firmware/blob/master/keyboards/preonic/keymaps/default/keymap.c 
- https://docs.qmk.fm/#/keycodes 
- https://config.qmk.fm/#/preonic/rev3/LAYOUT_preonic_1x2uC 
- https://docs.qmk.fm/#/newbs 



After QMK MSYS is installed and running:
```
$ qmk setup
y

$ qmk new-keymap
Keyboard Name: preonic
Keymap Name: feralpacket
Ψ feralpacket keymap directory created in: C:/Users/feralpacket/qmk_firmware/keyboards/preonic/keymaps/feralpacket
Ψ Compile a firmware with your new keymap by typing:

qmk compile -kb preonic -km feralpacket
```

Edit keymap.c, located in %USERPROFILE\qmk_firmware\keyboards\preonic\keymaps\feralpacket.

This should work, but doesn't at the moment.  See below.
```
qmk compile -kb preonic/rev3 -kb feralpacket
```


Ran into this problem while compiling. The workaround works.

https://www.reddit.com/r/olkb/comments/n7bj77/qmk_not_compiling_property/
```
which gmake
which make
pwd
cd qmk_firmware
make preonic/rev3:feralpacket
```
