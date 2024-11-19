#include "Menu.h"
#include <iostream>
#include <vector>

using namespace std;

int rows = sizeof(Menu::arr) / sizeof(Menu::arr[0]); 

int cols = sizeof(Menu::arr[0]) /sizeof(Menu::arr[0][0]); 
  
void Menu::menuList()
{
    cout << "Choose your desired food from the list below by entering the right number" << endl;
    cout << "==========================" << endl;
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "==========================" << endl;
}

void Menu::placeOrder()
{
    int numbers = 0;
    string over;

    while(over != "over" && over != "Over")
    {
    cout << "\nWhich one do you want - # of row: " ;
    cin >> numbers;
       for(int j = 0; j < cols; ++j)
            {
                if(numbers >= 0 && numbers <= 9)
                {
                    list.push_back(arr[numbers][j]);
                }
                else{
                    cout << "Invalid option";
                }
            }
        cout << "\nIf that's all you want write 'Over', other wise enter C: ";
        cin >> over;
        if(over == "Over" || over == "over")
                {
                    cout << "Thank you for your order" << endl;
                    break;
                }
            else if(over == "C" || over == "c")
            {
                continue;
            }else{
                cout << "Invalid option" << endl;
            }
    }
    cout << "\nSelected Options: ";
    for(size_t i = 0; i < list.size(); ++i)
    {
        cout << list[i] << " ";
    }  
    cout << endl;
}

