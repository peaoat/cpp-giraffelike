#include "libtcod.hpp"
#include "Entity.hpp"
#include "Map.hpp"
#include "Engine.hpp"

Engine engine;

int main(void) {
   while (! TCODConsole::isWindowClosed() )
   {
       engine.update();
       engine.render();
       TCODConsole::flush();
   }
   return 0;
}