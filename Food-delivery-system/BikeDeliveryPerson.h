#ifndef BIKEDELIVERYPERSON_H
#define BIKEDELIVERYPERSON_H

#include "Menu.h"
#include "I_Printing.h"
#include <string>
#include <iostream>

using namespace std;

class BikeDeliveryPerson : public I_Printing, Menu
{
public:
    
    string distance;
    string name;
    double time = 0;
    
    BikeDeliveryPerson(string name, string distance);
    
    virtual int traffic();
    virtual void timeTaking();
    virtual void distanceTaking();
    virtual void menuList() override;
    virtual void placeOrder() override;
    virtual void deliveryPersonImage();
    virtual void print(std::ostream &os) const override;
    
    virtual ~BikeDeliveryPerson() = default;

};

#endif // BIKEDELIVERYPERSON_H
