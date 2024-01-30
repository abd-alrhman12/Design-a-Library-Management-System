#pragma once
#ifndef LibraryCard
#define LibraryCard
#include "account.h"
class librarycard :public Account {
public :
	librarycard();
	void set_card(string, string, string, long);
};
#endif