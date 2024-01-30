#pragma once
#ifndef lib
#define lib
#include <iostream>
#include "book.h"
#include "bookitem.h"
#include "general_member_account.h"
#include "Librarian.h"
#include <string>
#include <fstream>
using namespace std;
class library {
private:
	Book* headBook;
	Gmember* headmember;
	librarian person;
public:
	library();
	~library();
	void AddBook(long, string, string, string, int, int, string*, string);
	bool RemoveBook(long);
	void EditBook(long);
	void printBook(Book*);
	void AddBookItem(long, int);
	bool RemoveBookItem(long, int);
	void RemoveBookItem(Book*, string, string, string, string);
	void EditBookItem(long, int);
	void Edit(Book*);
	Book* SearchByTitleBook(string);
	Book* SearchByAuthorBook(string);
	Book* SearchBySubjectBook(string);
	Book* SearchByDateBook(string);
	void NewAccount(string, string, string, long);
	void transferBook(Gmember*);
	void DeleteAccount(string, string, string, long);
	Gmember* searchAccount(string, string);
	BookItem* SearchBookItem(Book*, string, string, string, string);
	void AddbookInAccount(Gmember*, long, string, string, string, int, int, string*, string);
	void AddbookitemInAccount(Gmember*, long, string, string, string, int, int, string*, string, int);
	Book* SearchBook(string, string, string, string);
	void BorrowABook(string, string, string, string, string, string);
	Book* searchBookInAccount(Gmember*, long, string, string, string, string, int, int);
	BookItem* searchBookItemInAccount(Gmember*, long, string, string, string, string, int, int);
	void DeleteBookInAccount(Gmember*, Book*);
	void DeleteBookItemInAccount(Gmember*, BookItem*);
	void ReturnBook(long, string, string, string, int, int, string*, string, string, string);
	void SetLibrarian(librarian);
	string whoTookABook(long);
	int searchIndexBook(Gmember*);
	int searchIndexBookItem(Gmember*);
	void RenewABook(long, string, string, string, int, int, string*, string, string, string);
	void AddBooktoFile(ofstream&,fstream&);
	void AddBookToLibFromFile(fstream&);
	void AddBookitemtoFile(ofstream&, fstream&);
	void AddBookitemToLibFromFile(fstream&);
	void AddAccountToFile(fstream&);
	void AddAccountToLibFromFile(fstream&);
	void pay(Gmember*);
};
#endif 
