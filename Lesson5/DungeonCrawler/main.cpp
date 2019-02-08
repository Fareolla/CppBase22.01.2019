#include "dungeon.h"

int main()
{

    bool goahead = true;

    do
    {
        Dungeon::showMap();
        Dungeon::playerMovement();
        goahead = Dungeon::checkPlayer();
    } while (goahead);

    Dungeon::showMap();

    return 0;
}
