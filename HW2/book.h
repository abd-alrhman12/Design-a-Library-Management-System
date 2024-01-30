#pragma once
#ifndef book
#define book
#include <iostream>
#include <string>
#include "bookitem.h"
#include "bookbase.h"
using namespace std;
class Book :public BookBase {
private:
	Book* Next;
	BookItem* headitem;
public:
	Book();
	~Book();
	Book(const Book&);
	Book operator=(const Book&);
	friend class library;
};
#endif 
