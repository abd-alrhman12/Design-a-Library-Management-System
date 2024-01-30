#include "Date.h"
date::date() {
	this->d = 0;
	this->m = 0;
	this->dDueDate = 0;
	this->mDueDate = 0;
}
void date::SetDate(int dd, int mm) {
	this->d = dd;
	this->m = mm;
	if (this->d > 16) {
		this->dDueDate = this->d - 16;
		if (this->m == 12) {
			this->mDueDate = 1;
		}
		else {
			this->mDueDate = this->m + 1;
		}
	}
	else {
		this->dDueDate = this->d + 14;
		this->mDueDate = this->m;
	}

}
void date::EditDueDate() {
	if (this->dDueDate > 16) {
		this->dDueDate = this->dDueDate - 16;
		if (this->mDueDate == 12) {
			this->mDueDate = 1;
		}
		else {
			this->mDueDate = this->mDueDate + 1;
		}
	}
	else {
		this->dDueDate = this->dDueDate + 14;
		this->mDueDate = this->mDueDate;
	}
}
int date::getduedateDay() {
	return this->dDueDate;
}
int date::getduedateMonth() {
	return this->mDueDate;
}
ostream& operator<<(ostream& out, const date& M) {
	out << M.d << " " << M.m << "\n";
	return out;
}
void date::Set_dueDate(int d, int m) {
	this->dDueDate = d;
	this->mDueDate = m;
}