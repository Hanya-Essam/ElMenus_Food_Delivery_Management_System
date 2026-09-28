//Nada Abdelhaliem Abdelfadel-20246114
// Hanya Essam Eldin Mohamed-20246122
//G7

#include <iostream>
#include "FoodItem.h"
#include "User.h"
#include "DeliveryDriver.h"
#include "Customer.h"
#include "Order.h"
#include "Enum.h"
#include"FileOperation.h"
#include<iomanip>
#include<chrono>
#include <cstring>
using namespace std::chrono;
using namespace std;

int main() {
    //we make coutomers, drivers and orders a double pointer as it is does not crash like the pointer and can make resizing easily.
    Customer**customers=new Customer*[2];
    int customerCounter=0;
    int sizeOfarrayCustomers=2;
    Customer**newCustomers=nullptr;
    Customer*searchForCustomer=nullptr;


    DeliveryDriver**drivers=new DeliveryDriver*[2];
    int driverCounter=0;
    int sizeOfarrayDrivers=2;
    DeliveryDriver**newDrivers=nullptr;
    DeliveryDriver*searchForDriver=nullptr;

    Order**orders=new Order*[5];
    int orderCounter=0;
    int sizeOfarrayOrders=5;
    Order**newOrders=nullptr;
    Order*searchForOrder=nullptr;
    int TotalRecords=0;//used it in section of binary files

    int choice;
    do {
        cout<<"+------------------------------------------------------------------------+\n";
        cout<<"|                                                                        |\n";
        cout<<"|                     ELMENUS MANAGEMENT SYSTEM V1.0                     |\n";
        cout<<"|                                                                        |\n";
        cout<<"+------------------------------------------------------------------------+\n";
        cout<<"|                           USER MANAGEMENT                              |\n";
        cout<<"+------------------------------------------------------------------------+\n";
        cout<<"|  1. Register New Customer                                              |\n";
        cout<<"|  2. Register New Delivery Driver                                       |\n";
        cout<<"+------------------------------------------------------------------------+\n";
        cout<<"|                           ORDER MANAGEMENT                             |\n";
        cout<<"+------------------------------------------------------------------------+\n";
        cout<<"|  3. Create New Order                                                   |\n";
        cout<<"|  4. Add Items to Order                                                 |\n";
        cout<<"|  5. Assign Driver to Order                                             |\n";
        cout<<"|  6. Update Order Status                                                |\n";
        cout<<"|  7. Display Order Details                                              |\n";
        cout<<"+------------------------------------------------------------------------+\n";
        cout<<"|                        INFORMATION & REPORTS                           |\n";
        cout<<"+------------------------------------------------------------------------+\n";
        cout<<"|  8. Display Customer Information                                       |\n";
        cout<<"|  9. Display Driver Information                                         |\n";
        cout<<"| 10. Compare Two Orders by Total                                        |\n";
        cout<<"| 11. Display System Statistics                                          |\n";
        cout<<"+------------------------------------------------------------------------+\n";
        cout<<"|                           FILE OPERATIONS                              |\n";
        cout<<"+------------------------------------------------------------------------+\n";
        cout<<"| 12. Save Completed Orders to File                                      |\n";
        cout<<"| 13. Save Driver Statistics to File                                     |\n";
        cout<<"+------------------------------------------------------------------------+\n";
        cout<<"|                            BONUS FEATURES                              |\n";
        cout<<"+------------------------------------------------------------------------+\n";
        cout<<"| 14. Save Orders to Binary File                                         |\n";
        cout<<"| 15. Load Order by Position(0(1))                                       |\n";
        cout<<"| 16. Binary File Statistics                                             |\n";
        cout<<"+------------------------------------------------------------------------+\n";
        cout<<"| 17. Exit System                                                        |\n";
        cout<<"+------------------------------------------------------------------------+\n";

        cin>>choice;
        if (choice==1) {

            if (customerCounter>=sizeOfarrayCustomers) {
                sizeOfarrayCustomers+=5;
                newCustomers=new Customer*[sizeOfarrayCustomers];

                for (int i=0;i<customerCounter;++i) {

                    newCustomers[i]=customers[i];
                }


                delete []customers;
                customers=newCustomers;
                newCustomers=nullptr;


            }



            string customerID,name,phoneNum,address;

            cout<<"Enter CustomerID:";
            cin>>customerID;
            cin.ignore();

            cout<<"Enter Customer Name: ";
            getline(cin,name);

            cout<<"Enter Customer phone number: ";
            getline(cin,phoneNum);

            cout<<"Enter Customer Address: ";
            getline(cin,address);

            customers[customerCounter]=new Customer(customerID,name,phoneNum,address);

            customerCounter++;


        }
        else if (choice==2){
            if (driverCounter>=sizeOfarrayDrivers) {
                sizeOfarrayDrivers+=5;
                newDrivers=new DeliveryDriver*[sizeOfarrayDrivers];

                for (int i=0;i<driverCounter;++i) {

                    newDrivers[i]=drivers[i];
                }
                delete []drivers;
                drivers=newDrivers;
                newDrivers=nullptr;

            }



            string driverID,name,phoneNum,vehicle;

            cout<<"\nEnter DriverID:";
            cin>>driverID;
            cin.ignore();

            cout<<"\nEnter Driver Name: ";
            getline(cin,name);

            cout<<"\nEnter Driver phone number: ";
            getline(cin,phoneNum);

            cout<<"\nEnter Driver Vehicle Type: ";
            getline(cin,vehicle);

            drivers[driverCounter]=new DeliveryDriver (driverID,name,phoneNum,vehicle,0,0.00);

            driverCounter++;

        }

        else if (choice==3){
            if (customerCounter==0) {
                cout<<"\nYou have to register customer first.\n";
            }
            else {
                if (orderCounter>=sizeOfarrayOrders) {
                    sizeOfarrayOrders+=5;
                    newOrders=new Order*[sizeOfarrayOrders];
                    for (int i=0;i<orderCounter;i++) {


                        newOrders[i]=orders[i];
                    }


                    delete[]orders;
                    orders=newOrders;
                    newOrders=nullptr;
                }

                string orderId,customerId;

                cout<<"\nEnter orderID: ";
                cin>>orderId;
                cout<<"\nEnter customerID: ";
                cin>>customerId;
                searchForCustomer= nullptr;
                for (int i=0;i<customerCounter;i++) {
                    if (customers[i]->getUserID()==customerId) {

                        searchForCustomer=customers[i];
                        break;
                    }
                }
                if (searchForCustomer==nullptr) {

                    cout<<"\nNo Customer found with that Id.\n";
                }
                else {
                    orders[orderCounter]=new Order(orderId,searchForCustomer);
                    ++orderCounter;

                }

            }




        }
        else if (choice==4){

            string orderId;
            cout<<"\nEnter OrderId: ";
            cin>>orderId;
            if (orderCounter==0) {
                cout<<"\nNO Order Found\n";
            }
            else {
                searchForOrder=nullptr;
                for (int i =0;i<orderCounter;i++) {
                    if (orders[i]->getOrderId()==orderId) {
                        searchForOrder=orders[i];
                        break;
                    }
                }
                if (searchForOrder==nullptr) {
                    cout<<"\nNo Order found with that Id.\n";

                }
                else {
                    char addItem;
                    do {
                        string itemName;
                        double price;
                        int quantity;

                        cin.ignore();
                        cout<<"\nEnter Item Name: ";
                        getline(cin,itemName);

                        cout<<"\nEnter Item price: ";
                        cin>>price;

                        cout<<"\nEnter Item quantity: ";
                        cin>>quantity;

                        FoodItem item(itemName,price,quantity);
                        *searchForOrder+=item;
                        cout<<"\nDo you want to add more items ? \n";
                        cout<<"Enter y->YES OR n-> NO";
                        cin>>addItem;


                    }while (addItem=='y'||addItem=='Y');


                }
            }
        }


        else if (choice==5){

            if (orderCounter==0) {
                cout<<"\nNO Order Found.\n";
            }
            else if (driverCounter==0) {
                cout<<"\nYou have to register driver first.\n";
            }
            else {
                string orderId,driverId;
                cout<<"Enter order Id: ";
                cin>>orderId;

                searchForOrder=nullptr;
                for (int i=0;i<orderCounter;i++) {
                    if (orders[i]->getOrderId()==orderId) {
                        searchForOrder=orders[i];
                        break;
                    }
                }
                if (searchForOrder==nullptr) {
                    cout<<"\nNo Order found with that Id.\n";
                }
                else {
                    cout<<"Driver ID: ";
                    cin>>driverId;
                    searchForDriver=nullptr;
                    for (int i=0;i<driverCounter;i++) {
                        if (drivers[i]->getUserID() == driverId) {
                            searchForDriver=drivers[i];
                            break;
                        }
                    }
                    if (searchForDriver==nullptr) {
                        cout<<"\nNo Driver found with that Id.\n";

                    }
                    else {
                        searchForOrder->assignDriver(searchForDriver);
                    }
                }
            }
        }



        else if (choice==6){
            if (orderCounter==0) {
                cout<<"\nNO Order Found.\n";
            }
            else {
                string orderId;
                int statusNumber;

                cout<<"Enter order Id: ";
                cin>>orderId;

                searchForOrder=nullptr;
                for (int i=0;i<orderCounter;i++) {
                    if (orders[i]->getOrderId()==orderId) {
                        searchForOrder=orders[i];
                        break;
                    }
                }
                if (searchForOrder==nullptr) {
                    cout<<"\nNo Order found with that Id.";
                }
                else {
                    cout<<"Choose the number of New Status "<<endl;
                    cout<<"1.PENDING "<<endl;
                    cout<<"2.PREPARING "<<endl;
                    cout<<"3.OUT_FOR_DELIVERY "<<endl;
                    cout<<"4.DELIVERED "<<endl;
                    cout<<"5.CANCELLED "<<endl;
                    cin>>statusNumber;
                    OrderStatus newStatus;

                    if(statusNumber==1)
                    {
                        newStatus=OrderStatus::PENDING;
                    }
                    else if(statusNumber==2)
                    {
                        newStatus=OrderStatus::PREPARING;
                    }

                    else if(statusNumber==3)
                    {
                        newStatus=OrderStatus::OUT_FOR_DELIVERY;
                    }

                    else if(statusNumber==4)
                    {
                        newStatus=OrderStatus::DELIVERED;
                    }

                    else if(statusNumber==5)
                    {
                        newStatus=OrderStatus::CANCELLED;
                    }
                    else {

                        cout<<"\nYou have entered a wrong number.\n";
                        continue;
                    }
                    searchForOrder->updateStatus( newStatus);

                }
            }
        }



        else if (choice==7){

            if (orderCounter==0) {
                cout<<"\nNO Order Found.\n";
            }
            else {
                string orderId;

                cout<<"Enter order Id: ";
                cin>>orderId;

                searchForOrder=nullptr;
                for (int i=0;i<orderCounter;i++) {
                    if (orders[i]->getOrderId()==orderId) {
                        searchForOrder=orders[i];
                        break;
                    }
                }
                if (searchForOrder==nullptr) {
                    cout<<"\nNo Order found with that Id.\n";
                }
                else {
                    cout<<endl;
                    searchForOrder->displayOrder();

                }
            }
        }



        else if (choice==8){

            if (customerCounter==0) {
                cout<<"\nNO Customer Found.\n";
            }
            else {
                string customerId;

                cout<<"Enter customer Id: ";
                cin>>customerId;

                searchForCustomer=nullptr;
                for (int i=0;i<customerCounter;i++) {
                    if (customers[i]->getUserID()==customerId) {
                        searchForCustomer=customers[i];
                        break;
                    }
                }
                if (searchForCustomer==nullptr) {
                    cout<<"\nNo Customer found with that Id.\n";
                }
                else {
                    cout<<endl;
                    searchForCustomer->displayInfo();

                }
            }
        }


        else if (choice==9){
            if (driverCounter==0) {
                cout<<"\nNO Driver Found.\n";
            }
            else {
                string driverId;

                cout<<"Enter driver Id: ";
                cin>>driverId;

                searchForDriver=nullptr;
                for (int i=0;i<driverCounter;i++) {
                    if (drivers[i]->getUserID()==driverId) {
                        searchForDriver=drivers[i];
                        break;
                    }
                }
                if (searchForDriver==nullptr) {
                    cout<<"\nNo Driver found with that Id.\n";
                }
                else {
                    cout<<endl;
                    searchForDriver->displayInfo();

                }
            }
        }
        else if (choice==10){
            if (orderCounter<2) {
                cout<<"\nNeed at least 2 orders to complete.\n";
            }
            else {
                string orderId1,orderId2;
                cout<<"\nEnter the ID of the First Order: ";
                cin>>orderId1;

                cout<<"\nEnter the ID of the Second Order: ";
                cin>>orderId2;
                Order*order1=nullptr;
                Order*order2=nullptr;

                for (int i=0;i<orderCounter;i++) {
                    if (orders[i]->getOrderId()==orderId1) {
                        order1=orders[i];
                    }
                    if (orders[i]->getOrderId()==orderId2) {
                        order2=orders[i];
                    }
                }

                if (order1==nullptr||order2==nullptr) {
                    cout<<"\nOne or Both of the orders not found.\n";
                }
                else {
                    if (*order1>*order2) {
                        cout<<"Order:"<<order1->getOrderId()<<" has higher total than Order:"<<order2->getOrderId()<<endl;

                    }
                    else if (*order2>*order1) {
                        cout<<"Order:"<<order2->getOrderId()<<" has higher total than Order:"<<order1->getOrderId()<<endl;

                    }
                    else {
                        cout<<"\nThe Two Orders have the same total.\n";

                    }
                }
            }
        }

        else if (choice==11){
            cout<<"************SYSTEM STATISTICS************\n";
            cout<<"Total Customers: "<<customerCounter<<endl;
            cout<<"Total Drivers: "<<driverCounter<<endl;

            int delivered=0;
            double totalPrice=0.00;
            for (int i=0;i<orderCounter;i++) {
                if (orders[i]->getStatus()==OrderStatus::DELIVERED) {
                    delivered++;
                    totalPrice+=orders[i]->calculateTotal();
                }

            }
            cout<<"Delivered Orders: "<<delivered<<endl;
            cout<<"The Price Of Delivered Orders: "<<fixed<<setprecision(2)<<totalPrice<<" EGP"<<endl;
        }


        else if (choice==12){
            if (orderCounter==0) {
                cout<<"\nNO Orders Found.\n";
            }
            else {
                SaveOrderDetials(orders,orderCounter);
                cout<<"Completed Orders Details have been saved to File 'completed_orders.txt'\n";
            }

        }

        else if (choice==13){
            if (driverCounter==0) {
                cout<<"\nNO Drivers Found.\n";
            }
            else {
                saveDriverStat(drivers,driverCounter);
                cout<<"\nDriver Statistics have been saved to File 'driver_stats.txt'\n";
            }

        }
        else if (choice==14){
            if (orderCounter==0) {
                cout<<"\nNO Orders Found.\n";
            }
            else {
                TotalRecords=orderCounter;     //saves the number of orders that will be saved in binary file
                SaveOrderRecord(orders,orderCounter);
            }

        }
        else if (choice==15){
            OrderRecord loadedRecord;
            string orderId;

            cout<<"Enter order Id: ";
            cin>>orderId;

            if (orderCounter==0) {
                cout<<"\nNO Order Found\n";
            }
            else {
                int temp =0;
                searchForOrder=nullptr;
                for (int i =0;i<TotalRecords;i++) {
                    if (orders[i]->getOrderId()==orderId) {
                        searchForOrder=orders[i];
                        temp=i;
                        break;
                    }
                }
                if (searchForOrder==nullptr) {
                    cout<<"\nNo Order found with that Id in 'orders.dat' File.\n";
                }
                else{

                    // we use chrono library to calculate time
                    auto start = high_resolution_clock::now(); //start to count time
                    bool success= LoadOrderRecord(loadedRecord,temp);
                    auto end = high_resolution_clock::now();//end to count time
                    auto duration = duration_cast<nanoseconds>(end - start);//this calculate the duration of loaded file from start to end

                    if (success) {

                        cout << "Order ID: " << loadedRecord.orderID << endl;
                        cout << "Customer: " << loadedRecord.customerName << endl;
                        cout << "Driver: " << loadedRecord.driverName << endl;
                        cout << "Total Amount: " << fixed << setprecision(2)<< loadedRecord.totalAmount << " EGP" << endl;

                        if(loadedRecord.status==OrderStatus::PENDING)
                        {
                            cout<<"order status: PENDING "<<endl;
                        }
                        else if(loadedRecord.status==OrderStatus::PREPARING)
                        {
                            cout<<"order status: PREPARING "<<endl;
                        }

                        else if(loadedRecord.status==OrderStatus::OUT_FOR_DELIVERY)
                        {
                            cout<<"order status: OUT_FOR_DELIVERY "<<endl;
                        }

                        else if(loadedRecord.status==OrderStatus::DELIVERED)
                        {
                            cout<<"order status: DELIVERED "<<endl;
                        }
                        else if(loadedRecord.status==OrderStatus::CANCELLED)
                        {
                            cout<<"order status: CANCELLED"<<endl;
                        }
                        cout << "Item Count: " << loadedRecord.itemCount << endl;
                        cout << "Vehicle Type: " << loadedRecord.vType << endl;




                        // line which print time
                        cout << "Direct access took " << duration.count() << " nanoseconds (O(1) time)" << endl;
                    }



                    else {
                        cout << "Failed to load record at position " << temp+1 << endl; //as temp start indexing from zero so we add 1


                    }
                }
            }

        }
        else if (choice==16){
            ifstream file("orders.dat", ios::binary | ios::in);

            if (!file) {
                cout << "Binary file 'orders.dat' not found!" << endl;
            }


            else {
                long long fileSize = TotalRecords*sizeof(OrderRecord);//tell the size of saved orders it maybe large so we but it long long data type
                file.seekg(0, ios::beg);

                int recordSize = sizeof(OrderRecord);


                cout << "Total file size: " << fileSize << " bytes" << endl;
                cout << "Total order records stored: " << TotalRecords << endl;
                cout << "Size of each record: " << recordSize << " bytes" << endl;
            }


            file.close();

        }
        else if (choice==17){
            if (customers) {
                for (int i=0;i<customerCounter;i++) {
                    delete customers[i];
                    customers[i]=nullptr;
                }
                delete []customers;
                customers=nullptr;
            }
            newCustomers=nullptr;

            searchForCustomer=nullptr;
            if (drivers) {
                for (int i=0;i<driverCounter;i++) {
                    delete drivers[i];
                    drivers[i]=nullptr;
                }
                delete []drivers;
                drivers=nullptr;
            }
            newDrivers=nullptr;

            searchForDriver=nullptr;
            if (orders) {
                for (int i=0;i<orderCounter;i++) {
                    delete orders[i];
                    orders[i]=nullptr;
                }
                delete []orders;
                orders=nullptr;
            }
            newOrders=nullptr;

            searchForOrder=nullptr;

            cout<<"\nExit System.\n";
            break;
        }
    }while(choice<=17||choice>0);

    return 0;
}

