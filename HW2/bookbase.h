#pragma once
#ifndef bookbase
#define bookbase
#include <iostream>
using namespace std;
class BookBase {
public:
	long ISBN;
	string title;
	string subject;
	int NumPublishers;
	string* publishers;
	int numrack;
	string author;
	string publicationDate;
	BookBase();
};
#endif