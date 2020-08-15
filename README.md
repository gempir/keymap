# Keymap

```
cd /home/gempir/qmk_firmware/keyboards/kbdfans/kbd75/keymaps
git clone git@github.com:gempir/keymap.git gempir

qmk config user.keyboard=kbdfans/kbd75/rev2
qmk config user.keymap=gempir
```

```
qmk compile
qmk flash # then press FN + Home to go into DFU mode
```
