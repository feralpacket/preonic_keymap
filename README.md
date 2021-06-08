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

### Cisco Aliases Emulated with Leader Key
Used the Leader Key feature to emulate the alias commands available in Cisco IOS.  The LEADER_TIMEOUT is set to 2000 ms.  Meaning, you have up to 2 seconds between key presses.  After the key sequence is pressed, wait 2 seconds and the alias will be sent as a string of text.  Change as necessary.

To use this feature, press the leader_key and then press the key sequence in order.  Wait 2 seconds.  Look at the keymap.c file to see which key KC_LEAD is associated with.  Change as necessary.   

I've used the mneumonic convention of using one character for each command word.  There are a few that deviate.  The big one is the "show archive" command using the alias "diff".  I didn't create key sequences for do commands while in configuration mode.  When in configuration mode, type "do " (include a space after "do"), then the leader_key, then the key sequence.

- https://thomasbaart.nl/2018/12/20/qmk-basics-leader-key/

The aliases that I've configured:

```
    alias configure re router eigrp
    alias configure ro router ospf
    alias configure rb router bgp
    alias exec ct configure terminal
    !
    alias exec sr show run
    alias exec srb show run | be
    alias exec sri show run | in
    alias exec sraaa show runnning-config | section aaa|auth|radius|tacacs
    !
    alias exec sip show ip protocol
    alias exec sir show ip route
    !
    alias exec sie show ip eigrp
    alias exec siei show ip eigrp interface
    alias exec sien show ip eigrp neighbor
    alias exec siet show ip eigrp topology
    !
    alias exec sib show ip bgp
    alias exec sibn show ip bgp neighbor
    alias exec sibs show ip bgp summary
    alias exec sbvua show bgp vpnv4 unicast all
    alias exec sbvuv show bgp vpvnr unicast vrf
    !
    alias exec sio show ip ospf
    alias exec siod show ip ospf database
    alias exec sioi show ip ospf interface
    alias exec sion show ip ospf neighbor
    !
    alias exec sdd show device-tracking database
    alias exec sddi show device-tracking database interface
    alias exec sddm show device-tracking database mac
    !
    alias exec sli show lisp instance-id
    alias exec slii show lisp instance-id * ipv4
    alias exec sliid show lisp instance-id * ipv4 database
    alias exec sliim show lisp instance-id * ipv4 map-cache
    alias exec sliis show lisp instance-id * ipv4 server
    alias exec slie show lisp instance-id * ethernet
    alias exec slied show lisp instance-id * ethernet database
    alias exec sliem show lisp instance-id * ethernet map-cache
    alias exec sliea show lisp instance-id * ethernet address-resolution
    alias exec alieh show lisp instance-id * ethernet address-resolution registration-history
    alias exec slsr show lisp server registration-history
    !
    alias exec sis show interface status
    alias exec siib show ip interface brief
    alias exec sit show interface trunk
    alias exec se show etherchannel
    alias exec sec show etherchannel summary
    alias exec sv show version
    alias exec svr show version | include reason|uptime
    alias exec sl show logging
    alias exec sia show ip arp
    alias exec smt show mac address-table
    alias exec sidsb show ip dhcp snooping binding
    alias exec spi show power inline
    alias exec scn show cdp neighbor
    alias exec diff show archive config differences nvram:startup-config system:running-config
    !
    alias exec ss show sdwan
    alias exec ssc show sdwan control
    alias exec sscc show sdwan control connections
    alias exec sscch show sdwan control connection-history
    alias exec ssbh show sdwan bfd history
    alias exec ssds show sdwan bfd session
    alias exec ssop show sdwan omp peers
    alias exec ssor show sdwan omp routes
    alias exec sspaa show sdwan policy access-list-associations
    alias exec sspac show sdwan policy access-list-counters
    alias exec sspfv show sdwan policy from-vsmart
    alias exec ssss show sdwan system status
    alias exec ssr show sdwan running-config
    !
    alias exec scrbc show cts role-based counters
    alias exec scrbp show cts role-based permissions
    alias exec scrbs show cts role-based sgt-map
    !
    !alias exec sciks show crypto isakmp sa
    !alias exec scips show crypto ipsec sa
    !
    alias exec sm show mpls
    alias exec smi show mpls interfaces
    alias exec sml show mpls ldp
    alias exec smln show mpls ldp neighbor
    alias exec smf show mpls forwarding-table
    !
    alias exec sipi show ip pim interface
    alias exec sipn show ip pim neighbor
    alias exec sipr show ip pim rp
    alias exec sim show ip mroute
```
