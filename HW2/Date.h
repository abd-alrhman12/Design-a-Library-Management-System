#pragma once
#ifndef Date
#define Date
#include <iostream>
#include <fstream>
using namespace std;
class date {
private:
	int d;
	int m;
	int dDueDate;
	int mDueDate;
public:
	date();
	void SetDate(int, int);
	int getduedateDay();
	int getduedateMonth();
	void EditDueDate();
	void Set_dueDate(int, int);
	friend ostream& operator<<(ostream&, const date&);
};
#endif
