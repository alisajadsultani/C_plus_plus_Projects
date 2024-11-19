#include "RockPaperScissors.h"

using namespace std;

RockPaperScissors::RockPaperScissors(){}

char RockPaperScissors::getTheComputerMove()
    {    
        srand(time(NULL));
        int randNum = rand() % 3;
        
        if(randNum == 0)
        {
            return 'r';
        }
        else if(randNum == 1)
        {
            return 'p';
        }
        else{
            return 's';
        }
    }
    
void RockPaperScissors::getResult(char player)
    {
        
        if(player == getTheComputerMove())
        {
            cout << "It's a tie!" << endl;
            cout << "Your move: " << player << endl;
            cout << "Computers move: " << getTheComputerMove() << endl;
        }
        else if(player == 'r' && getTheComputerMove() == 's')
        {
            cout << "Player wins!" << endl;
            cout << "Your move: " << player << endl;
            cout << "Computers move: " << getTheComputerMove() << endl;
        }
        else if(player == 'p' && getTheComputerMove() == 'r')
        {
            cout << "Player wins!" << endl;
            cout << "Your move: " << player << endl;
            cout << "Computers move: " << getTheComputerMove() << endl;
        }
        else if(player == 's' && getTheComputerMove() == 'p')
        {
            cout << "Player wins!" << endl;
            cout << "Your move: " << player << endl;
            cout << "Computers move: " << getTheComputerMove() << endl;
        }
        else{
            cout << "Computer wins!" << endl;
            cout << "Your move: " << player << endl;
            cout << "Computers move: " << getTheComputerMove() << endl;
        }
        
    }
    
void RockPaperScissors::play()
{
        char player;
    
        while(true)
        {
            cout <<"\nPlease choose between 'r'(rock), 's'(scissor), and 'p'(paper): ";
            cin >> player;
            if(player == 's' || player == 'r' || player == 'p')
            {
                break;
            }
            else{
                cout << "Invalid input, try again!" << endl;
            }
        }
               
        getResult(player);
}
