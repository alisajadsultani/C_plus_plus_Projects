#include "CarDeliveryPerson.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

CarDeliveryPerson::CarDeliveryPerson(string name, string distance) : BikeDeliveryPerson(name, distance) {}


void CarDeliveryPerson::timeTaking()
{
    
    if(distance == "Ajax")
    {
        time += 5;
        cout << "\nTime will take for the order to arrive: " << time << " minute" << endl;
    }
    else if(distance == "Whitby")
    {
        time += 2;
        cout << "\nTime will take for the order to arrive: " << time << " minute" << endl;
    }
}

void CarDeliveryPerson::menuList()
{
    BikeDeliveryPerson::menuList();
}

void CarDeliveryPerson::placeOrder()
{
    BikeDeliveryPerson::placeOrder();
}

void CarDeliveryPerson::deliveryPersonImage()
{
    BikeDeliveryPerson::deliveryPersonImage();
}
void CarDeliveryPerson::distanceTaking()
{
    BikeDeliveryPerson::distanceTaking();
}



void CarDeliveryPerson::print(ostream &os) const
{
    os << "\nName: " << name << " " << "Address: " << distance;
}







