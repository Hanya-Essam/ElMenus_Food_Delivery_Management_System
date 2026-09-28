//Nada Abdelhaliem Abdelfadel-20246114
// Hanya Essam Eldin Mohamed-20246122
//G7
#include <iostream>
using namespace std;
#include "User.h"

#ifndef DELIVERYDRIVER_H
#define DELIVERYDRIVER_H


class DeliveryDriver: public User {
private:
    string vehicleType;
    int completedDeliveries ;
    double totalEarnings;

public:
    DeliveryDriver();
    DeliveryDriver(string ,string ,string  ,string  , int ,double);

    string getVehicleType() const;
    int getCompletedDeliveries () const;
    double getTotalEarnings() const;

    void displayInfo();
    double calculateEarnings();
    void completeDelivery(double );

    DeliveryDriver operator++(); // prefix
    DeliveryDriver operator++(int); // postfix



};


#endif