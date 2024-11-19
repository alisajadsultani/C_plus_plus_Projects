#include "HangManGame.h"
#include <iostream>

using namespace std;

HangManGame::HangManGame(){}

string HangManGame::randomWord()
    {
        string arr[8] {"hi", "game", "play", "mommy", "alone", "it", "boss", "computer"};
        return arr[rand() % 5];
    }
    
     void display(int incorrectGuessCount)
    {
        string hangman[] = {
            "   _____",
            "  |     |",
            "  |     O",
            "  |    /|\\",
            "  |    / \\",
            "  |",
            "__|_________"
        };
        
        for(int i = 0; i < incorrectGuessCount; ++i)
        {
            cout << hangman[i] << endl;
        }
        
    }
    
bool HangManGame::readingPlayerInput(char asking, string& word, string& guessed)
    {
            for(size_t i = 0; i < word.length(); ++i)
            {
                if(word[i] == asking)
                {
                    guessed[i] = asking;
                    return true;
                }
            }
        return false;
    }
    
void HangManGame::play()
{
        string word = randomWord();
    
        string guessed(word.length(), '_');
                
        cout << guessed << endl;
                
        int incorrect = 0;
        const int maxIncorrect = 6;
                
        while(incorrect < maxIncorrect)
        {
                            
            char asking;
            cout << "Guess the right letter: ";
            cin >> asking;
                    
            if(readingPlayerInput(asking, word, guessed))
            {
                cout << "CORRECT!" << endl; 
            }else{
                incorrect++;
                cout << "Wrong guess, # of incorrect guess: " << incorrect << endl;
            }
                    
            display(incorrect);
                    
            if(word == guessed)
            {
                cout << "You have won the game!" << endl;
                break;
            }
        }
        if(incorrect == 6)
        {
                cout << "Sorry, you couldn't guess the right word, the right word is: " << word << endl;
        }
    
}

