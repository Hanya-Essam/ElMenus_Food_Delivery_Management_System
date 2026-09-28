//Nada Abdelhaliem Abdelfadel-20246114
// Hanya Essam Eldin Mohamed-20246122
//G7
#include<iostream>
using namespace std;

#include"FileOperation.h"
#include "Order.h"
#include "DeliveryDriver.h"
#include<iomanip>
#include <cstring>



void SaveOrderDetials( Order** orders,int counter) {
    fstream outfile("completed_orders.txt",ios::out);

    if (!outfile) {
        outfile.open("completed_orders.txt",ios::out);
    }
    int total=0;
    outfile<<"============Completed Orders=============\n";
    cout<<"============Completed Orders=============\n";
for (int i=0;i<counter;i++) {
    if (orders[i]->getStatus()==OrderStatus::DELIVERED) {
        ++total;
        outfile<<"***********Order #"<<total<<"************\n";
        outfile<<(*orders[i]);
        outfile<<"---------------------------------------------------------------------------\n";
        cout<<"***********Order #"<<total<<"************\n";
        cout<<(*orders[i]);
        cout<<"---------------------------------------------------------------------------\n";

    }

}
    outfile<<"Total Orders Delivered : "<<total<<endl;
    cout<<"Total Orders Delivered : "<<total<<endl;

    outfile.close();
}



void  saveDriverStat( DeliveryDriver** drivers,int counter ) {
    fstream outfile("driver_stats.txt",ios::out);
    if (!outfile) {
        outfile.open("driver_stats.txt",ios::out);
    }

    outfile<<"===========Drivers Statistics==========\n";
    cout<<"===========Drivers Statistics==========\n";
    for (int i=0;i<counter;i++) {
        outfile<<"****Driver #"<<i+1<<"****\n";
        outfile << "Driver ID: " <<drivers[i]->getUserID() << endl;
        outfile << "Name: " << drivers[i]->getName() << endl;
        outfile << "Phone: " << drivers[i]->getPhoneNumber() << endl;
        outfile << "Vehicle: " << drivers[i]->getVehicleType()<<endl;
        outfile << "Completed Deliveries: " << drivers[i]->getCompletedDeliveries () <<endl;
        outfile << "Total Earnings: " <<fixed<<setprecision(2)<< drivers[i]->getTotalEarnings()  << "EGP"<<endl;
        outfile<<"---------------------------------------------------------------------------\n";
        cout<<"****Driver #"<<i+1<<"****\n";
        drivers[i]->displayInfo();
        cout<<"---------------------------------------------------------------------------\n";
    }
    outfile<<"Total Drivers: "<<counter<<endl;
    cout<<"Total Drivers: "<<counter<<endl;

    outfile.close();



}

//==========BONUS FEATURES===========


void SaveOrderRecord( Order**orders,int orderCounter) {
    fstream SaveOrderRecord("orders.dat",ios::binary|ios::out);
    if (!SaveOrderRecord) {
        SaveOrderRecord.open("orders.dat",ios::binary|ios::out);
    }

    OrderRecord record;



    for (int i=0;i<orderCounter;i++) {
        if (orders[i]!=nullptr) {
            strncpy(record.orderID, orders[i]->getOrderId().c_str(), 49);
            record.orderID[49] = '\0';
            record.itemCount = orders[i]->getItemCount();
            record.status = orders[i]->getStatus();
            record.totalAmount = orders[i]->calculateTotal();

            Customer* customer = orders[i]->getCustomer();
            if (customer!=nullptr) {
                strncpy(record.customerID, customer->getUserID().c_str(), 49);
                record.customerID[49] = '\0';
                strncpy(record.customerName,customer->getName().c_str(), 49);
                record.customerName[49] = '\0';
                strncpy(record.customerPhoneNum, customer->getPhoneNumber().c_str(), 19);
                record.customerPhoneNum[19] = '\0';
                strncpy(record.customerAddress, customer->getDeliveryAddress().c_str(), 69);
                record.customerAddress[69] = '\0';
                record.loyaltyPts = customer->getLoyaltyPoints();
            }


            DeliveryDriver* driver = orders[i]->getDriver();
            if (driver!=nullptr) {
                strncpy(record.driverID, driver->getUserID().c_str(), 49);
                record.driverID[49] = '\0';
                strncpy(record.driverName, driver->getName().c_str(), 49);
                record.driverName[49] = '\0';
                strncpy(record.driverPhoneNum, driver->getPhoneNumber().c_str(), 19);
                record.driverPhoneNum[19] = '\0';
                strncpy(record.vType, driver->getVehicleType().c_str(), 29);
                record.vType[29] = '\0';
            }
            SaveOrderRecord.write(reinterpret_cast<const char *>(&record),sizeof(OrderRecord));
        }

    }
        SaveOrderRecord.close();
    cout << "Successfully saved " <<orderCounter<< " orders to binary file "<<endl;

}

    bool LoadOrderRecord(OrderRecord& order,int position) {
    ifstream SaveOrderRecord("orders.dat",ios::in|ios::binary);
    if (!SaveOrderRecord) {
        cout<<"\nFailed to open file.\n";
        return false;
    }


    SaveOrderRecord.seekg(position*sizeof(OrderRecord));

    SaveOrderRecord.read(reinterpret_cast< char *>(&order),sizeof(OrderRecord));

    SaveOrderRecord.close();
    return true;
}


