#include "TicTacTo.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

TicTacTo::TicTacTo(){}

void TicTacTo::drawboard(char board[][3])
    {
        cout << "______________\n";
        for (int i = 0; i < 3; i++)
        {
            cout << " | ";
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j] << " | ";
            }
            cout << "\n______________\n";
        }
    }
    

bool TicTacTo::checkWin(char board[][3], char player) 
{ 
    for (int i = 0; i < 3; i++) { 
        if (board[i][0] == player && board[i][1] == player 
            && board[i][2] == player) 
            return true; 
        if (board[0][i] == player && board[1][i] == player 
            && board[2][i] == player) 
            return true; 
    } 
    if (board[0][0] == player && board[1][1] == player 
        && board[2][2] == player) 
        return true; 
    if (board[0][2] == player && board[1][1] == player 
        && board[2][0] == player) 
        return true; 
    return false; 
}

void TicTacTo::play()
{

    cout << "\nWelcome to Tic-Tac Toe!" << endl;
    
    const int ROW = 3;
    const int COL = 3;
    
    char board[ROW][COL] = {{' ',' ', ' '}, 
                            {' ',' ', ' '}, 
                            {' ',' ', ' '}};
    
    int row, col;
    char player = 'X';
    int round;
    
    for(round = 0; round < 9; round++)
    {
        drawboard(board);
       while(true)
       {
            cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
            cin >> row >> col;
            if(board[row][col] != ' ' || row < 0 && row > ROW || col < 0 && col > COL)
            {
                cout << "Please enter a valid index!" << endl;
            }
            else{
                break;
            }
       }
       
        board[row][col] = player;
        
        if(checkWin(board, player))
       {
           cout << "Player " << player << " wins!" << endl;
           drawboard(board);
           break;
       }
       
        player = (player == 'X') ? 'O' : 'X';
    }
    
    drawboard(board);

    if(round == 9 && !checkWin(board, 'X') && !checkWin(board, 'O'))
        {
            cout << "It's a draw, no one wins!" << endl;
        }
    }