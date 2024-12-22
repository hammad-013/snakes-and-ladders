#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void gotoRowCol(int rpos, int cpos)
{
    int xpos = cpos, ypos = rpos;
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}
void sleep(int m)
{
    for (int j = 0; j < m * 21000; j++)
    {
    }
}

void numbersInsideBox(int rp, int cp)
{
    int num = 100;
    int stcol = cp;
    for (int j = 1; j <= 10; j++)
    {
        for (int i = 1; i <= 10; i++)
        {
            gotoRowCol(rp, cp);
            cout << num;
            num--;
            cp -= 10;
        }
        rp += 5;
        cp = stcol;
    }
}
void horiLines(int rp, int cp, char border_ch)
{
    int stcol = cp;
    rp += 5;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            gotoRowCol(rp, cp);
            if (i == 11 && j == 100)
            {
                cout << border_ch << border_ch << border_ch;
            }
            else
            {
                cout << border_ch;
            }
            cp = cp + 1;
        }
        cp = stcol;
        rp = rp + 5;
    }
}
void vertiLines(int rp, int cp, char border_ch)
{
    int strow = rp;
    cp += 10;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 50; j++)
        {
            gotoRowCol(rp, cp);
            cout << border_ch << border_ch;
            rp = rp + 1;
        }
        rp = strow;
        cp = cp + 10;
    }
}

void removePos(int row, int col)
{
    gotoRowCol(row, col);
    cout << " ";
}
int dice(int a, int b, char playerch)
{
    int diceNum;
    gotoRowCol(a, b);
    cout << "Player (" << playerch << ")";
    gotoRowCol(a + 1, b);
    cout << "press any key to roll dice: ";
    getch();
    int i = 1;
    while (i <= 6)
    {
        gotoRowCol(a + 2, b);
        cout << i;
        sleep(500);
        i++;
    }

    gotoRowCol(a + 2, b);
    srand(time(0));
    diceNum = (rand() % 6) + 1;
    cout << diceNum;
    return diceNum;
}
void border(int rp, int cp, char border_ch)
{
    for (int i = 1; i <= 100; i++)
    {
        gotoRowCol(rp, cp);
        cout << border_ch;
        cp += 1;
    }
    for (int i = 1; i <= 50; i++)
    {
        gotoRowCol(rp, cp);
        cout << border_ch << border_ch;
        rp += 1;
    }
    cp += 1;
    for (int i = 1; i <= 101; i++)
    {
        gotoRowCol(rp, cp);
        cout << border_ch;
        cp -= 1;
    }
    for (int i = 1; i <= 50; i++)
    {
        gotoRowCol(rp, cp);
        cout << border_ch << border_ch;
        rp -= 1;
    }
}
void board(int rp, int cp, char border_ch)
{
    border(rp, cp, border_ch);
    horiLines(rp, cp, border_ch);
    vertiLines(rp, cp, border_ch);
    numbersInsideBox(rp + 3, cp + 95);
}
void snakesRowColChange(int &row, int &col, int startCol, char &player)
{
    if ((row > 25 && row < 30) && (col > 80 && col < 90))
    {
        removePos(row, col);
        row = 47;
        col = startCol + 70;
        gotoRowCol(row, col);
        cout << player;
    }
    if ((row > 20 && row < 25) && (col > 40 && col < 50))
    {
        removePos(row, col);
        row = 47;
        col = startCol + 100;
        gotoRowCol(row, col);
        cout << player;
    }
    if ((row > 30 && row < 35) && (col > 110 && col < 120))
    {
        removePos(row, col);
        row = 42;
        col = startCol + 100;
        gotoRowCol(row, col);
        cout << player;
    }
    if ((row > 15 && row < 20) && (col > 80 && col < 90))
    {
        removePos(row, col);
        row = 22;
        col = startCol + 40;
        gotoRowCol(row, col);
        cout << player;
    }
    if ((row == 2) && (col > 120 && col < 130))
    {
        removePos(row, col);
        row = 47;
        col = startCol + 70;
        gotoRowCol(row, col);
        cout << player;
    }
}
void laddersRowColChange(int &row, int &col, int startCol, char &player)
{
    if ((row > 45 && row < 50) && (col > 80 && col < 90))
    {
        removePos(row, col);
        row = 22;
        col = startCol + 80;
        gotoRowCol(row, col);
        cout << player;
    }
    if ((row > 40 && row < 45) && (col > 70 && col < 80))
    {
        removePos(row, col);
        row = 27;
        col = startCol + 90;
        gotoRowCol(row, col);
        cout << player;
    }
    if ((row > 25 && row < 30) && (col > 50 && col < 60))
    {
        removePos(row, col);
        row = 22;
        col = startCol + 100;
        gotoRowCol(row, col);
        cout << player;
    }
    if ((row > 20 && row < 25) && (col > 60 && col < 70))
    {
        removePos(row, col);
        row = 7;
        col = startCol + 100;
        gotoRowCol(row, col);
        cout << player;
    }
}
void rowColChange(int &row, int &col, int &step, int endCol, char player)
{
    int nCol = col + step * 10;
    if (nCol > endCol)
    {
        while (nCol > endCol)
        {
            col = nCol - 100;
            nCol = col;
            row -= 5;
        }

        gotoRowCol(row, col);
        cout << player;
    }
    else
    {
        col += step * 10;
        gotoRowCol(row, col);
        cout << player;
    }
}
void After84(int &row, int &col, int &step, int endCol, int startCol, char player)
{
    if (row == 7)
    {
        // 81
        if ((col >= startCol + 10) && step > 19)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        }
        // 82
        if ((col >= startCol + 20) && step > 18)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        }
        // 83
        if ((col >= startCol + 30) && step > 17)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        }
        // 84
        if ((col >= startCol + 40) && step > 16)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        } // 85
        else if ((col >= startCol + 50) && step > 15)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        } // 86
        else if ((col >= startCol + 60) && step > 14)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        } // 87
        else if ((col >= startCol + 70) && step > 13)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        } // 88
        else if ((col >= startCol + 80) && step > 12)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        } // 89
        else if ((col >= startCol + 90) && step > 11)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        } // 90
        else if ((col >= startCol + 100) && step > 10)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        }
        else
        {
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        }
    }

    else if (row == 2)
    {
        // 91
        if ((col >= startCol + 10) && step > 9)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        } // 92
        else if ((col >= startCol + 20) && step > 8)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        } // 93
        else if ((col >= startCol + 30) && step > 7)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        }
        // 94
        else if ((col >= startCol + 40) && step > 5)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        } // 95
        else if ((col >= startCol + 50) && step > 5)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        } // 96
        else if ((col >= startCol + 60) && step > 4)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        }
        // 97
        else if ((col >= startCol + 70) && step > 3)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        } // 98
        else if ((col >= startCol + 80) && step > 2)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        } // 99
        else if ((col >= startCol + 90) && step > 1)
        {
            step = 0;
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        }

        else
        {
            removePos(row, col);
            rowColChange(row, col, step, endCol, player);
        }
    }
}
int diceCalc(int &totalSteps, int &counter, int &steps, char player, int rowFDice, bool &turnStart)
{
    totalSteps += steps;
    // if six roll dice again
    if (totalSteps == 6)
    {
        counter += 1;
        while (counter < 3)
        {
            steps = dice(rowFDice, 0, player);
            totalSteps += steps;
            if (steps != 6)
            {
                break;
            }
            else
            {
                counter += 1;
            }
        }
        // not moving first six as it starts the turn
        if (turnStart == 0)
        {
            totalSteps -= 6;
            turnStart = 1;

            //, if three consecutive 6s, skip the turn
            if (counter == 3)
            {
                turnStart = 0;
            }
        }
        else
        {

            //, if three consecutive 6s, skip the turn
            if (counter == 3)
            {
                totalSteps = 0;
            }
        }
    }
}
void updatePosition(char player1, char player2, int &p1PosRow, int &p1PosCol, int &p2PosRow, int &p2PosCol, bool &turnStartP1, bool &turnStartP2, int endColP1, int endColP2, int startColP1, int startColP2)
{

    gotoRowCol(p1PosRow, p1PosCol);
    cout << player1;
    gotoRowCol(p2PosRow, p2PosCol);
    cout << player2;
    int steps = dice(0, 0, player1);

    int counter = 0;
    int totalSteps = 0;

    diceCalc(totalSteps, counter, steps, player1, 0, turnStartP1);

    if (turnStartP1 == 1)
    {

        if (p1PosRow == 2 || p1PosRow == 7)
        {
            After84(p1PosRow, p1PosCol, totalSteps, endColP1, startColP1, player1);
        }
        else
        {
            removePos(p1PosRow, p1PosCol);
            rowColChange(p1PosRow, p1PosCol, totalSteps, endColP1, player1);
        }
        snakesRowColChange(p1PosRow, p1PosCol, startColP1, player1);
        laddersRowColChange(p1PosRow, p1PosCol, startColP1, player1);
    }

    counter = 0;
    steps = dice(10, 0, player2);

    totalSteps = 0;

    diceCalc(totalSteps, counter, steps, player2, 10, turnStartP2);

    if (turnStartP2 == 1)
    {
        if (p2PosRow == 2 || p2PosRow == 7)
        {
            After84(p2PosRow, p2PosCol, totalSteps, endColP2, startColP2, player2);
        }
        else
        {
            removePos(p2PosRow, p2PosCol);
            rowColChange(p2PosRow, p2PosCol, totalSteps, endColP2, player2);
        }
        snakesRowColChange(p2PosRow, p2PosCol, startColP2, player2);
        laddersRowColChange(p2PosRow, p2PosCol, startColP2, player2);
    }
}

void snakesLaddersList(int a, int b, char p1, char p2)
{
    gotoRowCol(a, b);
    cout << "Snakes: ";
    a += 1;
    gotoRowCol(a, b);
    cout << "45 -----> 7";
    a += 1;
    gotoRowCol(a, b);
    cout << "99 -----> 7";
    a += 1;
    gotoRowCol(a, b);
    cout << "51 -----> 10";
    a += 1;
    gotoRowCol(a, b);
    cout << "38 -----> 20";
    a += 1;
    gotoRowCol(a, b);
    cout << "65 -----> 54";
    a += 2;
    gotoRowCol(a, b);
    cout << "Ladders: ";
    a += 1;
    gotoRowCol(a, b);
    cout << "5  -----> 58";
    a += 1;
    gotoRowCol(a, b);
    cout << "14 -----> 49";
    a += 1;
    gotoRowCol(a, b);
    cout << "42 -----> 60";
    a += 1;
    gotoRowCol(a, b);
    cout << "53 -----> 90";
    a += 2;
    gotoRowCol(a, b);

    cout << "Player 1: " << p1;
    a += 1;
    gotoRowCol(a, b);
    cout << "Player 2: " << p2;
    a += 1;
}
int main()
{

    char player1 = 143;
    char player2 = 153;
    char border_ch = 219;
    int starting_row = 0, starting_col = 40;
    int p1PosRow = starting_row + 47, p1PosCol = starting_col - 3, p2PosRow = starting_row + 47, p2PosCol = starting_col - 7;
    int startColP1 = starting_col - 3, startColP2 = starting_col - 7;
    int endColP1 = startColP1 + 100, endColP2 = p2PosCol + 100;
    bool turnStartP1 = 0, turnStartP2 = 0;

    board(starting_row, starting_col, border_ch);
    snakesLaddersList(starting_row + 3, starting_col + 115, player1, player2);

    while (true)
    {
        updatePosition(player1, player2, p1PosRow, p1PosCol, p2PosRow, p2PosCol, turnStartP1, turnStartP2, endColP1, endColP2, startColP1, startColP2);
        if (p1PosCol == endColP1 && p1PosRow == 2)
        {
            system("CLS");
            gotoRowCol(15, 50);
            cout << player1 << " is the winner.";

            gotoRowCol(17, 50);
            cout << "Press Any Key To Play Again.";

            getch();
            system("CLS");
            board(starting_row, starting_col, border_ch);
            snakesLaddersList(starting_row + 3, starting_col + 115, player1, player2);
            p1PosRow = starting_row + 47, p1PosCol = starting_col - 3, p2PosRow = starting_row + 47, p2PosCol = starting_col - 7;
            turnStartP1 = 0, turnStartP2 = 0;
        }
        else if (p2PosCol == endColP2 && p2PosRow == 2)
        {
            system("CLS");
            gotoRowCol(15, 50);
            cout << player2 << " is the winner.";
            gotoRowCol(17, 50);
            cout << "Press Any Key To Play Again.";

            getch();
            system("CLS");
            board(starting_row, starting_col, border_ch);
            snakesLaddersList(starting_row + 3, starting_col + 115, player1, player2);
            p1PosRow = starting_row + 47, p1PosCol = starting_col - 3, p2PosRow = starting_row + 47, p2PosCol = starting_col - 7;
            turnStartP1 = 0, turnStartP2 = 0;
        }
    }
    return 0;
}
