 #pragma once
#include "Person.h"
class Customer :
    public Person
{
private:
    string CustomerId;
    string Password;
    string email;
public:
    Customer();
    Customer(string,string,string,int,string,string);
    ~Customer();
    void setname(string);
    string getname();
    void setid(string);
    string getid();
    void setpw(string);
    string getpw();
};

