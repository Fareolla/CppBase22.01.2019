#include <ncurses.h>
#include "dungeon.h"

namespace Dungeon {

enum class Fields : unsigned char
{
    Field = '.',
    Trap = 'X',
    Wall = '#',
    Exit = '$',
};

static const int ROW {10};
static const int COL {10};

static Fields map [ROW][COL]{
    {Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall},
    {Fields::Wall,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Trap,Fields::Field,Fields::Field,Fields::Wall},
    {Fields::Wall,Fields::Trap,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Wall},
    {Fields::Wall,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Wall},
    {Fields::Wall,Fields::Field,Fields::Field,Fields::Field,Fields::Trap,Fields::Field,Fields::Field,Fields::Field,Fields::Trap,Fields::Wall},
    {Fields::Wall,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Wall},
    {Fields::Wall,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Wall},
    {Fields::Wall,Fields::Field,Fields::Trap,Fields::Field,Fields::Field,Fields::Field,Fields::Trap,Fields::Field,Fields::Field,Fields::Wall},
    {Fields::Wall,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Field,Fields::Exit,Fields::Wall},
    {Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall,Fields::Wall},

};

struct {
    unsigned char symbol {'@'};
    int X {1};
    int Y {1};
} Player{};




void showMap ()
{
    initscr();
    clear();

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            if ((i == Player.Y ) && (j == Player.X))
            {
                printw("%c " , Player.symbol);
            }
            else
            {
                printw("%c ", static_cast<char>(map[i][j]));
            }
        printw(" \n");
    }

    endwin();
    refresh();
}

void playerMovement ()
{
    //int move;
    //std::cin >> move;

    switch (getch()) {
    case 'w':
        if (Player.Y == 1)
        {
            break;
        }
        --Player.Y;
        break;
    case 's':
        if (Player.Y == 8)
        {
            break;
        }
        ++Player.Y;
        break;
    case 'a':
        if (Player.X == 1)
        {
            break;
        }
        --Player.X;
        break;
    case 'd':
        if (Player.X == 8)
        {
            break;
        }
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
    case Fields::Trap:
        Player.symbol = '+';
        goahead = false;
        printf(" You step on trap! Game over!");
        break;
    case Fields::Exit:
        Player.symbol = '!';
        goahead = false;
        printf(" Congratulation! You found Exit!");
        break;
    default:
        break;
    }

    return goahead;
}

} // namespace Dungeon
