# build
qmk clean; qmk compile -kb iandactyl -km default

# flash
qmk flash -kb iandactyl -km default



`cp /Users/ian/git/qmk_firmware/.build/iandactyl_default.uf2 /Volumes/RPI-RP2/iandactyl_default.uf2`



# `qmk console` to debug


# iandox
qmk compile -kb iandox -km default
cp ~/qmk_firmware/iandox_default.uf2 ~/qmk_firmware/keyboards/iandox_default.uf2
````