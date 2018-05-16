# cpp-giraffelike
This is (mostly) a clone of _peaoat/giraffelike_, a roguelike written in Python.

You will need `libtcod` to compile this game.

On MacOS High Sierra,

\> git clone https://github.com/podiki/libtcod-mac.git  

\> cd libtcod-mac

[line 109 of _/libtcod-mac/include/libtcod.h_ should have `<SDL.h>` changed to `<SDL/SDL.h>`]

\> make -f makefiles/makefile-osx release

copy the following from your libtcod-mac folder into this project's root (e.g. _~/cpp-giraffelike/_:

include/\*.h
include/\*.hpp
terminal.png
libtcod.dylib
libtcodxx.dylib

build with `gcc src/*.cpp -o giraffelike -Iinclude -L. -ltcod -ltcodxx -lc++ -Wall`

run the game with `./giraffelike` and enjoy!