//Nada Abdelhaliem Abdelfadel-20246114
// Hanya Essam Eldin Mohamed-20246122
//G7
#include <iostream>
using namespace std;
#include "User.h"
#include "Customer.h"

Customer::Customer() {
    loyaltyPoints=0;
}
Customer::Customer(string uID,string name,string phone ,string address ):User(uID,name,phone) {
    loyaltyPoints=0;
    deliveryAddress=address;
}


void Customer:: setDeliveryAddress(string address) {

    deliveryAddress=address;
}
void Customer:: setLoyaltyPoints(int LoyaltyPts) {
    loyaltyPoints=LoyaltyPts;

}


string Customer:: getDeliveryAddress() const {

    return deliveryAddress;
}
int Customer:: getLoyaltyPoints() const {
    return loyaltyPoints;

}

void Customer:: displayInfo() {
    cout << "\n Customer ID: " << getUserID() << endl;
    cout << " Name: " << getName() << endl;
    cout << " Phone: " << getPhoneNumber() << endl;
    cout << " Address: " << deliveryAddress << endl;
    cout << " Loyalty Points: " << loyaltyPoints<<endl;
}


double Customer:: calculateEarnings() {

    return loyaltyPoints*0.5;
}

Customer& Customer::  operator +=(int num) {
    loyaltyPoints+=num;
    return *this;


}