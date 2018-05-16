#include "libtcod.hpp"
#include "Entity.hpp"

Entity::Entity(int x, int y, int ch, const TCODColor & col):
    x(x), y(y), ch(ch), col(col)
{

}

void Entity::render() const
{
    TCODConsole::root->setChar(x, y, ch);
    TCODConsole::root->setCharForeground(x, y, col);
}