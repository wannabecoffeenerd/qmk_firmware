# Charybdis Mini (3x6) default keymap

> :bulb: Have a look at the [`via` keymap](../via) for a more feature-rich layout.

The Charydbis Mini (3x6) default keymap is inspired from the original [Dactyl Manuform](../../../../../handwired/dactyl_manuform) default keymap.

This layout supports RGB matrix. However, due to space constraints on the MCU, only a limited number of effect can be enabled at once. Look at the `config.h` file and enable your favorite effect.

# hyjkim notes
To enter bootloader, press the top left-most key while plugging in left side or top right most key while plugging in right side. Config can be cleared by pressing second from top left or second from top right, respecitvely.
```
# Compile the default map
qmk compile -kb  bastardkb/charybdis/3x6/kb2040 -km default
# Flash split with default maps (this was only tested with trrs unplugged)
qmk flash -kb  bastardkb/charybdis/3x6/kb2040 -km default -bl uf2-split-left
qmk flash -kb  bastardkb/charybdis/3x6/kb2040 -km default -bl uf2-split-right

# flash with custom layout
# I only needed to flash the left in order to program the whole board
qmk flash -kb  bastardkb/charybdis/3x6/kb2040 -km hyjkim  -bl uf2-split-right
#qmk flash -kb  bastardkb/charybdis/3x6/kb2040 -km hyjkim  -bl uf2-split-left

```
