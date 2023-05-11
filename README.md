# CPTR 142: Project III

The goal for this project is to build a dive calculator that performs various calculations and looks up data for a commercial diver. This calculator will be able to calculate repet group, residual nitrogen, and decompression stops for multiple dives for one person in saltwater.

## Terminal Commands

Build and run the program.

Windows:
```sh
make windows && ./divecalculator-win
```
or
```sh
windres src/gui/icon.rc -O coff -o src/gui/icon.res
g++ -Wall -mwindows -o divecalculator-win.exe src/gui.cpp \
src/rnt_data_table.cpp src/RNT.cpp src/decomp.cpp \
src/gui/icon.res `pkg-config gtkmm-3.0 --cflags --libs`
./divecalculator-win
```

Others:
```sh
make others && ./divecalculator-all
```

Clean out build files.

```sh
make clean
```
## Build Dependencies
- gtkmm-3.0
- pkg-config