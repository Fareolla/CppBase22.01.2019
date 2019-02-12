#include <ncurses.h>
#include <vector>
#include "dungeon.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace Dungeon {

static int ROW {Row()};
static int COL {Col ()};
static int Range {arrayLength(ROW, COL)};
static const char field {'.'};
static const char trap {'X'};
static const char wall {'#'};
static const char exit {'E'};
static std::vector< std::vector<char> > level (Range);

struct {
    unsigned char symbol {'@'};
    int X {1};
    int Y {1};
} Player{};

int Row(){
    printf("Please enter a Row number:  ");
    int result {};
    std::cin >> result;
    return result;
}
int Col(){
    printf("Please enter a Column number:  ");
    int result {};
    std::cin >> result;
    return result;
}

int arrayLength (int arg1, int arg2)
{
    int result {};

    if (arg1 > arg2)
    {
        result = arg1;
    }
    else {
        result = arg2;
    }
    return result;
}

void setDungeon()
{

    int lineX = COL - 2;
    int lineY = ROW - 2;

    srand (time (0));

    for (int i = 0; i < Range; i++) {
        level [i] = std::vector<char>(COL);
        for (int j = 0; j < level[i].size(); j++)
        {
            if (j== 0 || j == COL - 1 || i==0 || i== ROW - 1)
            {
                level [i][j] = wall;
            }
            else
            {
                level [i][j] = field;
            }
        }
    }

    for (int k = 0; k < Range; ++k)
    {
        level [rand() % lineX + 1][rand() % lineY + 1] = trap;
    }

    level [rand() % lineX + 1][rand() % lineY + 1] = exit;
}

void showMap ()
{
    initscr();
    clear();

    for (int i = 0; i < ROW ; ++i) {

        for (int j = 0; j < COL ; ++j)
        {
            if ((i == Player.Y ) && (j == Player.X))
            {
                printw("%c " , Player.symbol);
            }
            else
            {
                printw("%c ", level[i][j]);
            }
        }

        printw(" \n");
    }

    endwin();
    refresh();
}


void playerMovement ()
{

    switch (getch()) {
    case 'w':
        if (Player.Y == 1)
        {
            break;
        }
        --Player.Y;
        break;
    case 's':
        if (Player.Y == ROW - 2)
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
        if (Player.X == COL - 2)
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

    switch (level[Player.Y][Player.X]) {
    case trap :
        Player.symbol = '+';
        goahead = false;
        printf(" You step on trap! Game over! ");
        break;
    case exit:
        Player.symbol = '!';
        goahead = false;
        printf(" Congratulation! You found Exit! ");
        break;
    default:
        break;
    }

    return goahead;
}

} // namespace Dungeon
