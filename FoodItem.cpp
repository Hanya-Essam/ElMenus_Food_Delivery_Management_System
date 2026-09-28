//Nada Abdelhaliem Abdelfadel-20246114
// Hanya Essam Eldin Mohamed-20246122
//G7
#include <iostream>
#include <iomanip>
using namespace std;

#include "FoodItem.h"

FoodItem::FoodItem() {

    itemName=" ";
    price=0.00;
    quantity=0;

}

FoodItem::FoodItem(string name,double p,int q) {

    itemName=name;
    price=p;
    quantity=q;

}
void FoodItem::setItemName(string name) {
    itemName=name;
}

void FoodItem::setPrice(double p) {
    price=p;

}

void FoodItem::setQuantity(int q) {
    quantity=q;
}

string FoodItem::getItemName()const {
    return itemName;
}

double FoodItem:: getPrice()const {
    return price;
}

int FoodItem:: getQuantity()const {
    return quantity;
}

double FoodItem:: calculateItemTotal() const {

    return price*quantity;
}
void FoodItem:: displayItem() {


    cout<<itemName<<" x"<<quantity<<" @ "<<price<<"EGP= "<<fixed<<setprecision(2)<<calculateItemTotal()<<" EGP"<<endl;

}