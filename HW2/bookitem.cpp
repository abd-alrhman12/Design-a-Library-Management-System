#include "bookitem.h"
#include "book.h"
BookItem::BookItem() :BookBase() {
	this->Nextitem = NULL;
	this->barcode = 0;
}
BookItem::BookItem(const BookItem& M) {
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
BookItem BookItem::operator=(const BookItem& M) {
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
	return *this;
}