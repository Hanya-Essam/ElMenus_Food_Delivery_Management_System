//Nada Abdelhaliem Abdelfadel-20246114
// Hanya Essam Eldin Mohamed-20246122
//G7
#include <iostream>
using namespace std;
#include "User.h"

#ifndef CUSTOMER_H
#define CUSTOMER_H


class Customer: public User  {
 private:
    string deliveryAddress;
    int loyaltyPoints;

public:
    Customer();
    Customer(string ,string ,string  ,string  );

    void setDeliveryAddress(string);
    void setLoyaltyPoints(int );

    string getDeliveryAddress() const;
    int getLoyaltyPoints( ) const;

    void displayInfo();
    double calculateEarnings();

    Customer &operator +=(int );


















};




#endif