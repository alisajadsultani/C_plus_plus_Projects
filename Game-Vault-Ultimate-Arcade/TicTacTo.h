#ifndef TICTACTO_H
#define TICTACTO_H
#include "Account.h"
#include <iostream>
#include <string>
#include <vector>

class TicTacTo : public Account
{
public:
    TicTacTo();
    void drawboard(char board[][3]);
    bool checkWin(char board[][3], char player);
    void play();
    virtual ~TicTacTo() = default;

};

#endif // TICTACTO_H
