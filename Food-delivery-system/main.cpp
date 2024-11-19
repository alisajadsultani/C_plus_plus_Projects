#include <iostream>
#include "BikeDeliveryPerson.h"
#include "CarDeliveryPerson.h"
#include "Menu.h"
#include <vector>
#include <string>

using namespace std;
     

int main()
{
    string name, address;
    char option;
    
    cout << "\nWelcome to Denis" << endl;
    cout << "Please enter your name and follow up your address" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Address: ";
    cin >> address;
    cout << "For fast delivery plus additional 2.99$ press - F " << endl;
    cout << "For normal delivery press - N " << endl;
    cout << "Choose one: ";
    cin >> option;
    
    switch(option)
    {
        case 'F':
        case 'f':
        {
            CarDeliveryPerson fast(name, address);
            cout << fast << endl;
            fast.timeTaking();
            fast.menuList();
            fast.placeOrder();
            fast.distanceTaking();
            break; 
        }
        case 'N':
        case 'n':
        {
            BikeDeliveryPerson normal(name, address);
            cout << normal << endl;
            normal.timeTaking();
            normal.menuList();
            normal.placeOrder();
            normal.distanceTaking();
            break;
        }
        default:
            cout << "Invalid option" << endl;
            break;
    }
}
