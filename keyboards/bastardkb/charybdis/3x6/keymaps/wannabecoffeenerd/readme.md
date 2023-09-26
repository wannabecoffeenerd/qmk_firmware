# Charybdis Mini (3x6) custom keymap

> :bulb: Have a look at the [`via` keymap](../via) for a more feature-rich layout.

The Charydbis Mini (3x6) default keymap is inspired from the original [Dactyl Manuform](../../../../../handwired/dactyl_manuform) default keymap.

This layout supports RGB matrix. However, due to space constraints on the MCU, only a limited number of effect can be enabled at once. Look at the `config.h` file and enable your favorite effect.

## wannabecoffeenerd notes

To enter bootloader, press the top left-most key while plugging in left side or top right most key while plugging in right side. Config can be cleared by pressing second from top left or second from top right, respecitvely.

```bash
# Compile the default map
qmk compile -kb  bastardkb/charybdis/3x6/kb2040 -km default

# compile with custom layout
qmk config user.keyboard=bastardkb/charybdis/3x6/kb2040
qmk config user.keymap=wannabecoffeenerd
qmk compile
```

To flash the keyboard, put the left side in bootloader mode as described above, then drag and drop the `.uf2` firmware file onto the keyboard that will show up as a storage volume. Repeat for the right side as well.
