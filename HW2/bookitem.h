#pragma once
#ifndef bookitem
#define bookitem
#include <iostream>
#include <string>
#include "bookbase.h"
using namespace std;
class BookItem : public BookBase {
private:
	BookItem* Nextitem;
	int barcode;
public:
	BookItem();
	BookItem(const BookItem&);
	BookItem operator=(const BookItem&);
	friend class library;
	friend class Book;
};
#endif 

