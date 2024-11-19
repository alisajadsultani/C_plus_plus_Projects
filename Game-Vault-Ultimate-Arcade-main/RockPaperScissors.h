#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H
#include "Account.h"
#include <iostream>
#include <string>


class RockPaperScissors : public Account
{
public:
    RockPaperScissors();
    char getTheComputerMove();
    void getResult(char player);
    void play();
    virtual ~RockPaperScissors() = default;

};

#endif // ROCKPAPERSCISSORS_H
