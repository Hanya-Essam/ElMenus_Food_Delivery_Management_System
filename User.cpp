//Nada Abdelhaliem Abdelfadel-20246114
//Hanya Essam Eldin Mohamed-20246122
//G7
#include <iostream>
using namespace std;

#include "User.h"

int User::totalUsers=0;

User::User() {
    userID=" ";
     name=" ";
    phoneNumber =" ";
    totalUsers++;
}
User::User(string uId,string n,string pNum) {
    userID=uId;
    name=n;
    phoneNumber =pNum ;

    totalUsers++;
}

string User::getUserID() const {
    return userID;
}
string User::getName() const {
    return name;
}
string User::getPhoneNumber() const {

    return phoneNumber;
}
int User:: getTotalUsers() {
    return totalUsers;
}


User::~User() {
    totalUsers--;
}