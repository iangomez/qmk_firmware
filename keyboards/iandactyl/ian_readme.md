qmk clean
qmk compile -kb dactyl_manuform -km default
cp ~/qmk_firmware/dactyl_manuform_default.uf2 ~/qmk_firmware/keyboards/dactyl_manuform_default.uf2
cp ~/git/qmk_firmware/dactyl_manuform_default.uf2 ~/git/qmk_firmware/keyboards/dactyl_manuform_default.uf2


`qmk console` to debug


# iandox
qmk compile -kb iandox -km default
cp ~/qmk_firmware/iandox_default.uf2 ~/qmk_firmware/keyboards/iandox_default.uf2
