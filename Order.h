//Nada Abdelhaliem Abdelfadel-20246114
// Hanya Essam Eldin Mohamed-20246122
//G7
#include <iostream>
using namespace std;
#include "FoodItem.h"
#include "Enum.h"
#include"DeliveryDriver.h"
#include"Customer.h"


#ifndef ORDER_H
#define ORDER_H


class Order {
private:
    string orderId;
    Customer* customer;
    DeliveryDriver* driver;
    FoodItem*items;
    int itemCount;
    int capacity;
    OrderStatus status;
    static int totalOrders;

public:
    Order();
    Order(string ,Customer*);
    Order(const Order&);
    ~Order();
    void addItem(const FoodItem&);
    void assignDriver(DeliveryDriver*);
    void updateStatus(OrderStatus );
    static int getTotalOrders();
    void displayOrder();
    double calculateTotal () const;
    string getOrderId()const;
    Customer* getCustomer() const;
    DeliveryDriver* getDriver() const ;
    OrderStatus getStatus() const;
    int getItemCount() const;
    Order& operator+=(const FoodItem& );
    Order operator+(const Order& );
    friend ostream& operator<<(ostream& , const Order& );
    friend bool operator>(const Order& , const Order&);

    FoodItem& operator[](int );
    const FoodItem& operator[](int ) const;




};


#endif