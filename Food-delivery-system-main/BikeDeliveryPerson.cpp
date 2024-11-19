#include "BikeDeliveryPerson.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

BikeDeliveryPerson::BikeDeliveryPerson(string name, string distancePut) :  distance(distancePut), name(name) {}


void BikeDeliveryPerson::timeTaking()
{
    if(distance == "Ajax")
    {
        time += 10;
        cout << "Time will take for the order to arrive: " << time << " minutes" << endl;
    }
    else if(distance == "Whitby")
    {
        time += 5;
        cout << "Time will take for the order to arrive: " << time << " minutes" << endl;
    }
}

int BikeDeliveryPerson::traffic()
{
    int i = (rand()%20)+1; 
    return i;
}
void BikeDeliveryPerson::menuList()
{
    Menu::menuList();
}

void BikeDeliveryPerson::placeOrder()
{
    Menu::placeOrder();
}

void BikeDeliveryPerson::deliveryPersonImage()
{
    std::cout << "      O      " << std::endl;
    std::cout << "     /|\\    " << std::endl; 
    std::cout << "    / | \\   " << std::endl; 
    std::cout << "   /  |  \\  " << std::endl; 
    std::cout << "     / \\    " << std::endl; 
    std::cout << "    /   \\   " << std::endl; 
    std::cout << "   /_____\  " << std::endl;
    std::cout << "    [FOOD] " << std::endl; 
}
void BikeDeliveryPerson::distanceTaking()
{
    if(distance == "Ajax")
    {
        if(traffic() == 10 || traffic() == 8 || traffic() == 5 || traffic() == 19)
        {
            time += 10;
            cout << "\nThere is traffic, order will arrive in: " << time << " minutes\n" << endl;
        }
        char canceling;
        cout << "if you want to cancel your order press 'c' other wise write 'No': ";
        cin >> canceling;
        if(canceling == 'c' || canceling == 'C')
            {
            for (int i = 0; i <= time; ++i) {
                cout << "You canceled your order" << endl;
                break;
            }
        }else{
            for (int i = 0; i <= time; ++i) {
                cout << "Distance " << i << " meter" << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            cout << "Order arrived, Enjoy!" << endl;
            deliveryPersonImage();
        }
    }
    else if(distance == "Whitby")
    {
        if(traffic() == 10 || traffic() == 8 || traffic() == 5 || traffic() == 19)
        {
            time += 5;
            cout << "\nThere is traffic, order will arrive in: " << time << " minutes\n" << endl;
        }
        char canceling;
        cout << "if you want to cancel your order press 'c' other wise right 'No': ";
        cin >> canceling;
        if(canceling == 'c' || canceling == 'C')
            {
            for (int i = 0; i <= time; ++i) {
                cout << "You canceled your order" << endl;
                break;
            }
        }else{
            for (int i = 0; i <= time; ++i) {
                cout << "Distance " << i << " meter" << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            cout << "Order arrived, Enjoy!" << endl;
            deliveryPersonImage();
        }
    }
}

void BikeDeliveryPerson::print(ostream &os) const
{
    os << "Name: " << name << " " << "Address: " << distance << " " << endl;
}



