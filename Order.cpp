//Nada Abdelhaliem Abdelfadel-20246114
// Hanya Essam Eldin Mohamed-20246122
//G7

#include <iostream>
using namespace std;
#include "FoodItem.h"
#include "DeliveryDriver.h"
#include "Customer.h"
#include "Enum.h"
#include "Order.h"
#include<iomanip>


int Order:: totalOrders=0;



Order:: Order() {
    orderId=" ";
    customer=nullptr;
    driver=nullptr;
    items=nullptr;
    itemCount=0;
    capacity=0;
    status=OrderStatus::PENDING;

    totalOrders++;
}
Order::Order(string oId,Customer*c) {

    orderId=oId;
    customer=c;
    driver=nullptr;
    items=nullptr;
    itemCount=0;
    capacity=0;
    status=OrderStatus::PENDING;


  totalOrders++;
}

Order::Order(const Order& object) {
    orderId=object.orderId;
    itemCount=object.itemCount;
    capacity=object.capacity;
    status=object.status;
    customer=object.customer;
    driver=object.driver;
    items = new FoodItem[capacity];
    for (int i = 0; i < itemCount; i++) {
        items[i] = object.items[i];
    }


    totalOrders++;
}

int Order:: getTotalOrders() {
    return totalOrders;


}
double Order:: calculateTotal () const {
    double total=0;

    for (int i=0;i<itemCount;i++) {
     total+=items[i].calculateItemTotal();

    }
    return total;
}


Order::~Order() {
    delete[] items;
    items=nullptr;

   totalOrders--;
}


void Order:: addItem(const FoodItem& item) {


    if (itemCount<capacity) {
        items[itemCount]=item;
        itemCount++;
    }
    else if (itemCount==capacity) {
        FoodItem* temp;
        capacity++;

        temp=new FoodItem [capacity];
        for (int i=0;i<itemCount;i++) {

            temp[i]=items[i];

          }
        delete[]items;
        items=temp;
        items[itemCount]=item;
        itemCount++;
    }
}


void Order:: assignDriver(DeliveryDriver*drv) {
    driver=drv;

}

void Order:: updateStatus(OrderStatus newStatus ) {
    bool wasDelivered = (status == OrderStatus::DELIVERED); // to handel if the order status was made delivered before & do not duplicate the calculations
    status=newStatus ;
    if (status==OrderStatus :: DELIVERED && !wasDelivered) {
        double orderTotal=calculateTotal();
        if (driver!=nullptr) {

            driver->completeDelivery(orderTotal);
            (*driver)++;
        }
        else {
            cout<<"Diver:Not Assigned Yet"<<endl;
        }
       if (customer != nullptr) {

           int points = static_cast<int>(orderTotal / 2);

            (*customer) += points;
        }
        else {
            cout<<"Customer:Not Assigned Yet"<<endl;
        }

    }

}



void Order:: displayOrder()  {

    cout << "\n**Order Details**" << endl;

    cout << "Order ID: " << orderId <<endl;
    cout << "Status: ";

    if(status==OrderStatus::PENDING)
        cout << "PENDING";
    else if (status==OrderStatus::PREPARING)
        cout << "PREPARING";
    else if (status==OrderStatus::OUT_FOR_DELIVERY)
        cout << "OUT FOR DELIVERY";
    else if (status==OrderStatus::DELIVERED)
        cout << "DELIVERED";
    else if(status==OrderStatus::CANCELLED)
        cout << "CANCELLED";

    cout<<endl;


    if (customer != nullptr) {
        cout << "\n**Customer Information**\n" ;
        customer->displayInfo();
        cout<<endl;
    }
    else {
        cout<<"NO Customer Assigned "<<endl;
    }

    if (driver != nullptr) {
        cout << "**Driver Information**\n";

        cout << " Driver ID: " << driver->getUserID() << endl;
        cout<<" Name: "<< driver->getName()<<endl;
       cout <<" Phone: "<< driver->getPhoneNumber()<<endl;
        cout<<" Vehicle Type: "<<driver->getVehicleType()<<endl;
    }
    else {
        cout<<"No Diver Assigned "<<endl;
    }
    cout << " Items:" << endl;
    for (int i = 0; i < itemCount; i++) {
        cout << "  ";
        items[i].displayItem();

    }

    cout << " Total: " << fixed <<setprecision(2)
              << calculateTotal() << " EGP" <<endl;

}

string Order::getOrderId() const
{ return orderId;
}
Customer* Order::getCustomer() const {
    return customer;
}
DeliveryDriver* Order::getDriver() const {
    return driver;
}
OrderStatus Order::getStatus() const {
    return status;
}
int Order::getItemCount() const {
    return itemCount;
}

Order& Order::operator+=(const FoodItem& item) {
    addItem(item);
    return *this;
}
Order Order::operator+(const Order& object)
{
    Order NewOrder;
    NewOrder.orderId=orderId + object.orderId;

    for (int i = 0; i < itemCount; i++) {
        NewOrder.addItem(items[i]);
    }


    for (int i = 0; i < object.itemCount; i++) {
        NewOrder.addItem(object.items[i]);
    }


    return NewOrder;

}

ostream& operator<<(ostream& os, const Order& order) {

    os << "\n**Order Details**" << endl;
    os << "Order ID: " << order.orderId <<endl;
    os << "Status: ";

    if(order.status==OrderStatus::PENDING)
        os << "PENDING";
    else if (order.status==OrderStatus::PREPARING)
        os << "PREPARING";
    else if (order.status==OrderStatus::OUT_FOR_DELIVERY)
        os << "OUT FOR DELIVERY";
    else if (order.status==OrderStatus::DELIVERED)
        os << "DELIVERED";
    else if(order.status==OrderStatus::CANCELLED)
        os << "CANCELLED";

    os<<endl;


    if (order.customer != nullptr) {
        os << "\n**Customer Information**\n" ;
        order.customer->displayInfo();
        os<<endl;
    }
    else {
        os<<"No Customer Assigned "<<endl;
    }

    if (order.driver != nullptr) {
        os << "**Driver Information**\n";

        os << " Driver ID: " << order.driver->getUserID() << endl;
        os<<" Name: "<< order.driver->getName()<<endl;
        os <<" Phone: "<< order.driver->getPhoneNumber()<<endl;
        os<<" Vehicle Type: "<<order.driver->getVehicleType()<<endl;
    }
    else {
        os<<"No Diver Assigned "<<endl;
    }
    os << " Items:" << endl;
    for (int i = 0; i < order.itemCount; i++) {
        os << "  ";
        order.items[i].displayItem();

    }

    os << "Total: " << fixed <<setprecision(2)
              << order.calculateTotal() << " EGP" <<endl;

    return os;
}


bool operator>(const Order& order1, const Order&order2) {

    bool flag;
    if (order1.calculateTotal()>order2.calculateTotal()) {

        flag=true;
    }
    else {
        flag=false;
    }
    return flag;
}
FoodItem& Order::operator[](int index) {
  return items[index];

}


const FoodItem& Order::operator[](int index)const {
    return items[index];
}
















