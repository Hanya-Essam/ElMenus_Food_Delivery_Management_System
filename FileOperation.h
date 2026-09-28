//Nada Abdelhaliem Abdelfadel-20246114
// Hanya Essam Eldin Mohamed-20246122
//G7

#include "Order.h"
using namespace std;
#include "DeliveryDriver.h"
#include<fstream>

#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H

void  SaveOrderDetials( Order**,int );
void saveDriverStat( DeliveryDriver**,int);


//==========BONUS FEATURES===========


struct OrderRecord {

    char orderID[50];
    int itemCount;

    OrderStatus status;

    char customerID[50];
    char customerName[50];
    char customerPhoneNum[20];
    char customerAddress[70];
    int loyaltyPts;


    char driverID[50];
    char driverName[50];
    char driverPhoneNum[20];
    char vType[30];


    double totalAmount;

};

void SaveOrderRecord( Order**orders ,int ) ;
bool LoadOrderRecord(OrderRecord& ,int );









#endif