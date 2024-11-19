#ifndef CARDELIVERYPERSON_H
#define CARDELIVERYPERSON_H

#include "BikeDeliveryPerson.h"

class CarDeliveryPerson : public BikeDeliveryPerson
{
public:
    CarDeliveryPerson(std::string name, std::string distance);
    
    virtual void timeTaking() override;
    virtual void distanceTaking() override;
    virtual void menuList() override;
    virtual void placeOrder() override;
    virtual void deliveryPersonImage() override;
    virtual void print(std::ostream &os) const override;
    
    virtual ~CarDeliveryPerson() = default;

};

#endif // CARDELIVERYPERSON_H
