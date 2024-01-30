#include "LibraryCard.h"
librarycard::librarycard() :Account() {

}
void librarycard::set_card(string n, string pass, string ad, long p) {
	this->name = n;
	this->password = pass;
	this->address = ad;
	this->phone = p;
}