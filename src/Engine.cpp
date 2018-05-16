#include "libtcod.hpp"
#include "Entity.hpp"
#include "Map.hpp"
#include "Engine.hpp"

Engine::Engine()
{
    TCODConsole::initRoot(80, 50, "giraffelike", false);
    player = new Entity(40, 25, '@', TCODColor::white);
    entities.push(player);
    map = new Map(80, 45);
}

Engine::~Engine()
{
    entities.clearAndDelete();
    delete map;
}

void Engine::update()
{
    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
    switch(key.vk)
    {
        case TCODK_UP:
            if (! map->isWall(player->x, player->y-1))
            {
                player->y--;
            }
        break;
        case TCODK_DOWN:
            if (! map->isWall(player->x, player->y+1))
            {
                player->y++;
            }
        break;
        case TCODK_LEFT:
            if (! map->isWall(player->x-1, player->y))
            {
                player->x--;
            }
        break;
        case TCODK_RIGHT:
            if (! map->isWall(player->x+1, player->y))
            {
                player->x++;
            }
        break;
        default: break;
    }
}

void Engine::render()
{
    TCODConsole::root->clear();
    map->render();

    for (Entity **iterator=entities.begin();
        iterator != entities.end();
        iterator++)
    {
        (*iterator)->render();
    }
}