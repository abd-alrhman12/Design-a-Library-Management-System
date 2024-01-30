#pragma once
#ifndef Librarian
#define Librarian
#include "account.h"
#include "LibraryCard.h"
class librarian :public Account {
	librarycard card;
public:
	librarian();
	void setInfo(string, string, string, long);
	librarian operator=(const librarian&);
	void ShowCard();
};
#endif
