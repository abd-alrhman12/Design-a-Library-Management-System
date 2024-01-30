#include "bookbase.h"
BookBase::BookBase() {
	this->ISBN = 0;
	this->title = "\0";
	this->subject = "\0";
	this->NumPublishers = 0;
	this->publishers = new string[NumPublishers];
	this->numrack = 0;
	this->author = "\0";
	this->publicationDate = "\0";
}