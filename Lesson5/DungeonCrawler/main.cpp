#include <iostream>
#include "dungeon.h"

int main()
{
    bool goahead = true;

    do
    {
        Dungeon::showMap();
        Dungeon::playerMovement();
        Dungeon::checkPlayer();
    } while (goahead);

    return 0;
}
