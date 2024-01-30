#pragma once
#ifndef account
#define account
#include <iostream>
using namespace std;
class Account {
protected:
	string  name;
	string password;
	string address;
	long phone;
public:
	Account();
};
#endif 
