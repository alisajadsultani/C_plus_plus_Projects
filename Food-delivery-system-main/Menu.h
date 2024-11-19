#ifndef MENU_H
#define MENU_H

//#include "BikeDeliveryPerson.h"
#include <vector>
#include <iostream>

using namespace std;

class Menu 
{
public:
    
    Menu(){};
    vector<string> list;
    string arr[10][2] {
        {"0. Pizza", "8.99$"}, 
        {"1. Pasta", "3.99$"}, 
        {"2. Burger", "5.99$"},
        {"3. Appetizers", "5.99$"},
        {"4. Soups", "1.99$"},
        {"5. Salads", "2.99$"},
        {"6. Entrees", "3.99$"},
        {"7. Sides", "2.99$"},
        {"8. Desserts", "3.99$"},
        {"9. Beverages", "6.99$"}
    };
    virtual void menuList();
    virtual void placeOrder();
    virtual ~Menu() = default;

};

#endif // MENU_H
