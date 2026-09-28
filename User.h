//Nada Abdelhaliem Abdelfadel-20246114
//Hanya Essam Eldin Mohamed-20246122
//G7
#include<string>
using namespace std;
#ifndef USER_H
#define USER_H


class User {
protected :
    string userID;
    string name;
    string phoneNumber;
    static int totalUsers;
public:
    User();
    User(string ,string ,string );


    string getUserID()const;
    string getName()const;
    string getPhoneNumber()const;

    static int getTotalUsers();
    virtual void displayInfo()=0;
    virtual double calculateEarnings()=0;
    virtual~User();

};


#endif