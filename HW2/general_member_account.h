#pragma once
#ifndef general_member_account
#define general_member_account
#include "account.h"
#include"book.h"
#include "Date.h"
#include "LibraryCard.h"
class Gmember : public Account {
private:
	Gmember* Nextmemb;
	int maxBook;
	Book* headbookaccount;
	BookItem* headitemaccount;
	date DateOfTheBorrowingBook[2];
	date DateOfTheBorrowingBookitem[2];
	int indexb, indexbi;
	librarycard card;
	bool flagBorrow;

public:
	Gmember();
	Gmember(const Gmember&);
	Gmember operator=(const Gmember&);
	void Showcard(Gmember*);
	void set_flagborrow(bool);
	friend class library;
	friend class Book;
};
#endif
