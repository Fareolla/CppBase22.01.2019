#include <iostream>
#include "dungeon.h"

namespace Dungeon {

const int ROW {5};
const int COL {5};



struct {
    char symbol {'G'};
    int X {0};
    int Y {0};
} Player{};

enum class Fields : char
{
    Field = '.',
    Tree = 'T',
    Exit = 'X',
};

//static char Field {'.'};
//static char Tree {'T'};
//static char Exit {'X'};


static Fields map [ROW][COL]{
    {Fields::Field,Fields::Field,Fields::Field,Fields::Tree,Fields::Field},
    {Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field},
    {Fields::Field,Fields::Field,Fields::Field,Fields::Tree,Fields::Field},
    {Fields::Field,Fields::Field,Fields::Tree,Fields::Field,Fields::Field},
    {Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Exit},
};


void showMap ()
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            if ((i == Player.Y ) && (j == Player.X))
            {
                std::cout << Player.symbol << ' ';
            }
            else
            {
                std::cout << static_cast<char>(map[i][j]) << ' ';
            }
        std::cout << std::endl;
    }



}

void playerMovement ()
{

    char command;
    std::cin >> command;

    switch (command) {
    case 'w':
        if (Player.Y == 0)
        {
            std::cout << "You can move there!" << std::endl;
            break;
        }
        --Player.Y;
        break;
    case 's':
        ++Player.Y;
        break;
    case 'a':
        --Player.X;
        break;
    case 'd':
        ++Player.X;
        break;
    default:
        break;

    }

}

bool checkPlayer()
{
    bool goahead = true;

    switch (map[Player.Y][Player.X]) {
    case Fields::Tree:
        Player.symbol = '=';
        goahead = false;
        break;
    default:
        break;
    }

    return goahead;
}

} // namespace Dungeon
