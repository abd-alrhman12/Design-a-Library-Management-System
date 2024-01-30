#include "book.h"
Book::Book() :BookBase() {
	this->Next = NULL;
	this->headitem = NULL;
}
Book::~Book() {
	delete[]this->publishers;
}
Book::Book(const Book& M) {
	this->ISBN = M.ISBN;
	this->title = M.title;
	this->subject = M.subject;
	this->author = M.author;
	this->numrack = M.numrack;
	this->NumPublishers = M.NumPublishers;
	this->publishers = new string[NumPublishers];
	for (int i = 0; i < NumPublishers; i++) {
		this->publishers[i] = M.publishers[i];
	}
	this->publicationDate = M.publicationDate;
}
Book Book::operator=(const Book& M) {
	delete[]this->publishers;
	this->ISBN = M.ISBN;
	this->title = M.title;
	this->subject = M.subject;
	this->author = M.author;
	this->numrack = M.numrack;
	this->NumPublishers = M.NumPublishers;
	this->publishers = new string[NumPublishers];
	for (int i = 0; i < NumPublishers; i++) {
		this->publishers[i] = M.publishers[i];
	}
	this->publicationDate = M.publicationDate;
	return*this;
}