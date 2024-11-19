#include "LoginAndRegister.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


LoginAndRegister::LoginAndRegister(){};
bool LoginAndRegister::registerUser()
{
    ifstream in_file;
    ofstream out_file;
    
    out_file.open("user.txt", ios::app);
    in_file.open("user.txt");
    
    if(!out_file || !in_file)
    {
        cout << "Failed to open the file" << endl;
        exit(1);
    }
    
    string str;

    while(in_file >> str)
    {
        if(str == username)
        {
            cout << "Username is already taken, please try again\n" << endl;
            return false;
        }
    }
    out_file << username << " " << password << endl;
    cout << "Registeration was successful\n" << endl;
    return true;
    
    out_file.close();    
}

bool LoginAndRegister::loginUser()
{
    ifstream in_file;
    in_file.open("user.txt");
    
    if(!in_file)
    {
        cout << "Failed to open the file" << endl;
        exit(1);
    }
    
    string str;
    
    while(getline(in_file, str))
    {
        if(str == (username + " " + password))
        {
            cout << "We have found your account, if you want to register with a new account please" 
            "choose the appropriate option\n" << endl;
            return true;
        }
        else{
            cout << "You don't have an account with us, please register one\n" << endl;
            return false;
        }
    }
    in_file.close();
}

void LoginAndRegister::runCode()
{
    char answer = '\0';
    
    while(answer != 'x' && answer != 'X')
    {
        cout << "register - R" << endl;
        cout << "Login - L" << endl;
        cout << "exit - X" << endl;
        
        cout << "Choose one of the option above: ";
        cin >> answer;
        
        if(answer == 'r' || answer == 'R')
        {
            cout << "\nYou want to register\n" << endl;
            
            cout << "Please enter your username: ";
            cin >> username;
            
            cout << "Please enter your password: ";
            cin >> password;
            
            registerUser();
            break;
            
        }
        
        else if(answer == 'l' || answer == 'L')
        {
            cout <<"\nYou want to login\n" << endl;
            cout << "Please enter your username: ";
            cin >> username;            
            cout << "Please enter your password: ";
            cin >> password;
            
            loginUser();
            
        }
        else if(answer == 'X' || answer == 'x')
        {
            cout << "Goodbye" << endl;
        }
        else{
            cout << "Invalid input!" << endl;
        }
    }
}