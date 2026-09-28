//Nada Abdelhaliem Abdelfadel-20246114
// Hanya Essam Eldin Mohamed-20246122
//G7
using namespace std;
#include <string>
#ifndef FOODITEM_H
#define FOODITEM_H


class FoodItem {
    string itemName;
    double price;
    int quantity;

public:
    FoodItem();
    FoodItem(string ,double ,int );
    void setItemName(string);

    void setPrice(double);

    void setQuantity(int);

    string getItemName()const ;

    double getPrice()const ;

    int getQuantity()const;

    double calculateItemTotal() const;
    void displayItem();


};


#endif