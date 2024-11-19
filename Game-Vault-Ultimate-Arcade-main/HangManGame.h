#ifndef HANGMANGAME_H
#define HANGMANGAME_H
#include "Account.h"
#include <string>
#include <iostream>

using namespace std;

class HangManGame : public Account
{
public:
    HangManGame();
    string randomWord();
    void play();
    bool readingPlayerInput(char asking, string& word, string& guessed);
    virtual ~HangManGame() = default;

};

#endif // HANGMANGAME_H
