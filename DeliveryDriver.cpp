//Nada Abdelhaliem Abdelfadel-20246114
// Hanya Essam Eldin Mohamed-20246122
//G7
#include <iostream>
using namespace std;
#include "User.h"


#include "DeliveryDriver.h"

DeliveryDriver:: DeliveryDriver() {

    vehicleType=" ";
    completedDeliveries=0;
    totalEarnings=0.00;

}

DeliveryDriver::DeliveryDriver(string uID, string name, string phone, string vType, int completeD,
                               double totalE) : User(uID, name, phone) {

    vehicleType=vType;
    completedDeliveries=completeD;
    totalEarnings=totalE;

}



string DeliveryDriver:: getVehicleType() const {
    return vehicleType;
}
int DeliveryDriver:: getCompletedDeliveries () const {
    return completedDeliveries;
}
double DeliveryDriver:: getTotalEarnings() const {
    return totalEarnings;
}


void DeliveryDriver:: displayInfo()  {
    cout << "Driver ID: " << getUserID() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Phone: " << getPhoneNumber() << endl;
    cout << "Vehicle: " << vehicleType <<endl;
    cout << "Completed Deliveries: " << completedDeliveries <<endl;
    cout << "Total Earnings: " << totalEarnings << " EGP"<<endl;
    if (completedDeliveries>0) {
        cout << "Average Earnings per delivery: " << totalEarnings/completedDeliveries << " EGP"<<endl;
    }


}

double DeliveryDriver::  calculateEarnings() {

    return totalEarnings;
}

void DeliveryDriver::completeDelivery(double orderValue) {
    totalEarnings += orderValue * 0.15;
}

DeliveryDriver DeliveryDriver:: operator++() {
    ++completedDeliveries;
    return *this;

}
DeliveryDriver DeliveryDriver:: operator++(int) {
    DeliveryDriver result;
    result=*this;
    completedDeliveries++;
    return result ;

}


