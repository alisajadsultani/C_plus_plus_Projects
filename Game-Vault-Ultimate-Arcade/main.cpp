#include <iostream>
#include "LoginAndRegister.h"
#include "Account.h"
#include "TicTacTo.h"
#include "HangManGame.h"
#include "RockPaperScissors.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    char options;
    char stop;
    int amount;
    
    Account money;
    LoginAndRegister create;
    TicTacTo ticGame;
    RockPaperScissors rockGame;
    HangManGame hangGame;
    
    cout << "=====Welcome to our Ultimate Project=====" << endl;
    
    cout << "Please create or login to your account to play the games" << endl;
    create.runCode();
    
    cout << "In order to play our video games you need to deposit the required amount coins" << endl;
    
    while(stop != 'q' && stop != 'Q')
    {
        cout << "To deposit coins enter - D" << endl;
        cout << "To play Rock Paper Scissors enter - R" << endl;
        cout << "To play Hang Man Game enter - H" << endl;
        cout << "To play Tic Tac Toe enter - T" << endl;
        cout << "To check the balance enter - C" << endl;
        cout << "To stop enter - S" << endl;
       
        cout << "> ";
        cin >> options;
        
        switch(options)
        {
            case 'd':
            case 'D':
            {
                cout << "Amount to deposit: ";
                cin >> amount;
                money.deposit(amount);
                cout << money << endl;
                break;
            }
            case 'R':
            case 'r':
            {
                if(money.balance >= 50)
                {
                    rockGame.play();
                    money.balance -= 50;
                }else{
                    cout << "don't have enough money" << endl;
                }
                break;
                
            }
            case 'h':
            case 'H':
            {
                if(money.balance >= 150)
                {
                    hangGame.play();
                    money.balance -= 150;
                }else{
                    cout << "Don't have enough money" << endl;
                }
                
                break;
            }
            case 'T':
            case 't':
            {
                if(money.balance >= 200)
                {
                    ticGame.play();
                    money.balance -= 200;
                }else{
                    cout << "Don't have enough money" << endl;
                }
                
                break;
            }
            case 'c':
            case 'C':
            {
                cout << money << endl;
                break;
            }
            case 's':
            case 'S':
            {
                stop = 'q';
                break;
            }
            default:
            {
                cout << "Wrong option" << endl;
            }
        }
    }
    
}