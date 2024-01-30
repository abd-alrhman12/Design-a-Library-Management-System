#include "lib.h"
#include "book.h"
#include "bookitem.h"
#include "Librarian.h"
string* pp;
string* pp2;
bool b = true, bi = true;
library::library() {
	headBook = NULL;
	headmember = NULL;
}
library::~library() {
	Book* p;
	BookItem* k;
	while (headBook) {
		p = headBook;
		while (p->headitem) {
			k = p->headitem;
			p->headitem = p->headitem->Nextitem;
			delete k;
		}
		headBook = headBook->Next;
		delete p;
	}
	delete headBook;
	Gmember* N;
	Book* p2;
	BookItem* k2;
	while (headmember) {
		N = headmember;
		while (N->headbookaccount) {
			p2 = N->headbookaccount;
			N->headbookaccount = N->headbookaccount->Next;
			delete p2;
		}
		while (N->headitemaccount) {
			k2 = N->headitemaccount;
			N->headitemaccount = N->headitemaccount->Nextitem;
			delete k2;
		}
		headmember = headmember->Nextmemb;
		delete N;
	}
	delete headmember;
}
void library::AddBook(long i, string t, string sub, string au, int rack, int num, string* pub, string date) {
	Book* N = new Book;
	delete[]N->publishers;
	N->ISBN = i;
	N->title = t;
	N->subject = sub;
	N->NumPublishers = num;
	N->author = au;
	N->numrack = rack;
	N->publishers = new string[num];
	for (int i = 0; i < num; i++) {
		N->publishers[i] = pub[i];
	}
	N->publicationDate = date;
	N->Next = headBook;
	headBook = N;
}
bool library::RemoveBook(long id) {
	Book* p1, * p2;
	p1 = headBook;
	p2 = NULL;
	while (p1 && p1->ISBN != id) {
		p2 = p1;
		p1 = p1->Next;
	}
	if (!p1 && !p2) {
		cout << "The library is empty\n";
		return false;
	}
	else if (!p1 && p2) {
		cout << "The Book was not found\n";
		return false;
	}
	else if (p1 && p2) {
		p2->Next = p1->Next;
		delete p1;
	}
	else if (p1 && !p2) {
		headBook = p1->Next;
		delete p1;
	}
	return true;
}
void library::EditBook(long id) {
	if (!headBook) {
		cout << "Library is Empty!\n";
	}
	else {
		Book* p = headBook;
		while (p && p->ISBN != id) {
			p = p->Next;
		}
		if (!p) {
			cout << "The Book was not found\n";
		}
		else {
			long i;
			string t, sub, au, date;
			int num, rack;
			cout << "Please Enter the ISBN new :\n";
			cin >> i;
			p->ISBN = i;
			cout << "Please Enter the Title new :\n";
			cin.ignore();
			getline(cin, t);
			p->title = t;
			cout << "Please Enter the Subject new :\n";
			getline(cin, sub);
			p->subject = sub;
			cout << "Please Enter the author new : \n";
			getline(cin, au);
			p->author = au;
			cout << "Please Enter the number of the rack new : \n";
			cin >> rack;
			p->numrack = rack;
			cout << "Please Enter the new number of the publishers :\n";
			cin >> num;
			p->NumPublishers = num;
			delete[]p->publishers;
			p->publishers = new string[num];
			pp = new string[num];
			cout << "Please Enter names Publishers new :\n";
			cin.ignore();
			for (int i = 0; i < num; i++) {
				getline(cin, pp[i]);
				p->publishers[i] = pp[i];
			}
			cout << "Please Enter publication date new (dd/mm/yyyy) :\n";
			cin >> date;
			p->publicationDate = date;
			this->Edit(p);
			cout << "Edit Book is done\n";
		}
	}
}
void library::Edit(Book* b) {
	if (!b->headitem) {
		return;
	}
	else {
		BookItem* bi = b->headitem;
		while (bi) {
			bi->ISBN = b->ISBN;
			bi->title = b->title;
			bi->subject = b->subject;
			bi->author = b->author;
			bi->numrack = b->numrack;
			bi->NumPublishers = b->NumPublishers;
			delete[]bi->publishers;
			bi->publishers = new string[bi->NumPublishers];
			for (int i = 0; i < bi->NumPublishers; i++) {
				bi->publishers[i] = b->publishers[i];
			}
			bi->publicationDate = b->publicationDate;
			bi = bi->Nextitem;
		}
	}
}
void library::printBook(Book* p) {
	cout << "ISBN : " << p->ISBN << "\n";
	cout << "Title : " << p->title << "\n";
	cout << "Subject : " << p->subject << "\n";
	cout << "Author : " << p->author << "\n";
	cout << "Number of the rack : " << p->numrack << "\n";
	cout << "Publishers : \n";
	for (int i = 0; i < p->NumPublishers; i++) {
		cout << i + 1 << ". " << p->publishers[i] << "\n";
	}
	cout << "Publication date (dd/mm/yyyy) : " << p->publicationDate << "\n";
	cout << "---------------------------------------\n";
}
void library::AddBookItem(long i, int code) {
	if (!headBook) {
		cout << "The library is empty\n";
		return;
	}
	Book* p = headBook;
	while (p && p->ISBN != i) {
		p = p->Next;
	}
	if (!p) {
		cout << "Book was not found\n";
	}
	else {
		BookItem* N = new BookItem;
		delete[]N->publishers;
		N->ISBN = p->ISBN;
		N->title = p->title;
		N->subject = p->subject;
		N->author = p->author;
		N->numrack = p->numrack;
		N->NumPublishers = p->NumPublishers;
		N->publishers = new string[N->NumPublishers];
		for (int i = 0; i < N->NumPublishers; i++) {
			N->publishers[i] = p->publishers[i];
		}
		N->publicationDate = p->publicationDate;
		N->barcode = code;
		N->Nextitem = p->headitem;
		p->headitem = N;
	}
}
void library::RemoveBookItem(Book* p, string t, string s, string a, string d) {
	BookItem* p1, * p2;
	p1 = p->headitem;
	p2 = NULL;
	while (p1 && (p1->title != t || p1->subject != s || p1->author != a || p1->publicationDate != d)) {
		p2 = p1;
		p1 = p1->Nextitem;
	}
	if (p1 && p2) {
		p2->Nextitem = p1->Nextitem;
		delete p1;
	}
	else if (p1 && !p2) {
		p->headitem = p1->Nextitem;
		delete p1;
	}
}
bool library::RemoveBookItem(long i, int code) {
	if (!headBook) {
		cout << "The library is empty\n";
		return false;
	}
	Book* p = headBook;
	while (p && p->ISBN != i) {
		p = p->Next;
	}
	if (!p) {
		cout << "Book was not found\n";
		return false;
	}
	else
	{
		BookItem* p1, * p2;
		p1 = p->headitem;
		p2 = NULL;
		while (p1 && p1->barcode != code) {
			p2 = p1;
			p1 = p1->Nextitem;
		}
		if (!p1 && !p2) {
			cout << "The Book Item is empty\n";
			return false;
		}
		else if (!p1 && p2) {
			cout << "The Book Item was not found\n";
			return false;
		}
		else if (p1 && p2) {
			p2->Nextitem = p1->Nextitem;
			delete p1;
		}
		else if (p1 && !p2) {
			p->headitem = p1->Nextitem;
			delete p1;
		}
		return true;
	}
}
void library::EditBookItem(long i, int code) {
	if (!headBook) {
		cout << "The library is empty\n";
		return;
	}
	Book* p = headBook;
	while (p && p->ISBN != i) {
		p = p->Next;
	}
	if (!p) {
		cout << "Book was not found\n";
	}
	else {
		if (!p->headitem) {
			cout << "The Book Item is empty\n";
		}
		else {
			BookItem* p1 = p->headitem;
			while (p1 && p1->barcode != code) {
				p1 = p1->Nextitem;
			}
			if (!p1) {
				cout << "The BookItem was not found\n";
			}
			else {
				int cod;
				cout << "Please Enter the barcode new : \n";
				cin >> cod;
				p1->barcode = cod;
				cout << "Edit Book Item is done\n";
			}
		}
	}
}
bool c(Book* m,string ser) {
	string s = m->title;
	bool flag = true;
	int i;
	for (i = 0; s[i] && flag; i++) {
		if (s[i] != ser[i]) {
			flag = false;
		}
	}
	if (flag == false && i>=3) {
		return true;
	}
	if (flag == true) {
		return true;
	}
	return false;
}
Book* library::SearchByTitleBook(string t) {
	Book* p = headBook;
	while (p) {
		if (c(p,t) == true) {
		this->printBook(p);
		}
		p = p->Next;
	}
	return p;
}
Book* library::SearchByAuthorBook(string a) {
	Book* p = headBook;
	while (p && p->author != a) {
		p = p->Next;
	}
	return p;
}
Book* library::SearchBySubjectBook(string sub) {
	Book* p = headBook;
	while (p && p->subject != sub) {
		p = p->Next;
	}
	return p;
}
Book* library::SearchByDateBook(string date) {
	Book* p = headBook;
	while (p && p->publicationDate != date) {
		p = p->Next;
	}
	return p;
}
void library::NewAccount(string n, string pass, string a, long p) {
	Gmember* N = new Gmember;
	N->name = n;
	N->password = pass;
	N->address = a;
	N->phone = p;
	N->Nextmemb = headmember;
	headmember = N;
}
void library::transferBook(Gmember* m1) {
	Book* b = m1->headbookaccount;
	BookItem* bi = m1->headitemaccount;
	while (b) {
		this->AddBook(b->ISBN, b->title, b->subject, b->author, b->numrack, b->NumPublishers, b->publishers, b->publicationDate);
		b = b->Next;
	}
	while (bi) {
		this->AddBookItem(bi->ISBN, bi->barcode);
		bi = bi->Nextitem;
	}
}
void library::DeleteAccount(string n, string pass, string a, long p) {
	Gmember* m1 = headmember;
	Gmember* m2 = NULL;
	while (m1 && (m1->name != n || m1->password != pass || m1->address != a || m1->phone != p)) {
		m2 = m1;
		m1 = m1->Nextmemb;
	}
	if (!m1 && !m2) {
		cout << "no Accounts\n";
	}
	else if (!m1 && m2) {
		cout << "The Account was not found\n";
	}
	else if (m1 && m2) {
		this->transferBook(m1);
		m2->Nextmemb = m1->Nextmemb;
		delete m1;
		cout << "Remove Account is done\n";
	}
	else if (m1 && !m2) {
		this->transferBook(m1);
		headmember = m1->Nextmemb;
		delete m1;
		cout << "Remove Account is done\n";
	}
}
Gmember* library::searchAccount(string n, string pass) {
	Gmember* p = headmember;
	while (p && (p->name != n || p->password != pass)) {
		p = p->Nextmemb;
	}
	return p;
}
BookItem* library::SearchBookItem(Book* p, string t, string s, string a, string d) {
	BookItem* n = p->headitem;
	while (n && (n->title != t || n->subject != s || n->author != a || n->publicationDate != d)) {
		n = n->Nextitem;
	}
	return n;
}
void library::AddbookInAccount(Gmember* g, long i, string t, string sub, string au, int rack, int num, string* pub, string date) {
	Book* N = new Book;
	delete[]N->publishers;
	N->ISBN = i;
	N->title = t;
	N->subject = sub;
	N->NumPublishers = num;
	N->author = au;
	N->numrack = rack;
	N->publishers = new string[num];
	for (int i = 0; i < num; i++) {
		N->publishers[i] = pub[i];
	}
	N->publicationDate = date;
	N->Next = g->headbookaccount;
	g->headbookaccount = N;
}
void library::AddbookitemInAccount(Gmember* g, long i, string t, string sub, string au, int rack, int num, string* pub, string date, int bco) {
	BookItem* N = new BookItem;
	delete[]N->publishers;
	N->ISBN = i;
	N->title = t;
	N->subject = sub;
	N->NumPublishers = num;
	N->author = au;
	N->numrack = rack;
	N->publishers = new string[num];
	for (int i = 0; i < num; i++) {
		N->publishers[i] = pub[i];
	}
	N->publicationDate = date;
	N->barcode = bco;
	N->Nextitem = g->headitemaccount;
	g->headitemaccount = N;
}
Book* library::SearchBook(string t, string s, string a, string date) {
	Book* p = headBook;
	while (p && (p->title != t || p->subject != s || p->author != a || p->publicationDate != date)) {
		p = p->Next;
	}
	return p;
}
void library::BorrowABook(string t, string s, string a, string date, string n, string pa) {
	Gmember* k = this->searchAccount(n, pa);
	if (!k) {
		cout << "Account was not found\n";
	}
	else {
		if (k->flagBorrow == true) {
			if (k->maxBook < 2) {
				Book* b1 = NULL;
				b1 = this->SearchBook(t, s, a, date);
				if (b1) {
					if (!b1->headitem) {
						int dd, mm;
						this->AddbookInAccount(k, b1->ISBN, b1->title, b1->subject, b1->author, b1->numrack, b1->NumPublishers, b1->publishers, b1->publicationDate);
						k->maxBook++;
						cout << " Please Enter Date of the borrowing (dd/mm) : \n";
						cout << "day : ";
						cin >> dd;
						cout << "month : ";
						cin >> mm;
						k->DateOfTheBorrowingBook[k->indexb++].SetDate(dd, mm);
						cout << "Borrow a Book is done\n";
						bool x;
						x = this->RemoveBook(b1->ISBN);
					}
					else {
						int ddd, mmm;
						BookItem* m = this->SearchBookItem(b1, t, s, a, date);
						this->AddbookitemInAccount(k, m->ISBN, m->title, m->subject, m->author, m->numrack, m->NumPublishers, m->publishers, m->publicationDate, m->barcode);
						k->maxBook++;
						cout << " Please Enter Date of the borrowing (dd/mm) : \n";
						cout << "day : ";
						cin >> ddd;
						cout << "month : ";
						cin >> mmm;
						k->DateOfTheBorrowingBookitem[k->indexbi++].SetDate(ddd, mmm);
						cout << "Borrow a Book is done\n";
						this->RemoveBookItem(b1, t, s, a, date);
					}
				}
				else {
					cout << "Book was not found\n";
				}
			}
			else {
				cout << "Cannot Borrow a Book\n";
			}
		}
		else {
			cout << "Can not Borrow a Book , You must pay a fine for being late in returning the book\n";
		}
	}
}
Book* library::searchBookInAccount(Gmember* k, long i, string ti, string sub, string au, string da, int r, int num) {
	Book* n = k->headbookaccount;
	while (n && (n->ISBN != i || n->title != ti || n->subject != sub || n->author != au || n->publicationDate != da || n->numrack != r || n->NumPublishers != num)) {
		n = n->Next;
	}
	if (!n) {
		b = false;
	}
	else
		b = true;
	return n;
}
BookItem* library::searchBookItemInAccount(Gmember* k, long i, string ti, string sub, string au, string da, int r, int num) {
	BookItem* n = k->headitemaccount;
	while (n && (n->ISBN != i || n->title != ti || n->subject != sub || n->author != au || n->publicationDate != da || n->numrack != r || n->NumPublishers != num)) {
		n = n->Nextitem;
	}
	if (!n) {
		bi = false;
	}
	else
		bi = true;
	return n;
}
void library::DeleteBookInAccount(Gmember* k, Book* N) {
	Book* p1 = k->headbookaccount;
	Book* p2 = NULL;
	while (p1 && (p1->ISBN != N->ISBN || p1->title != N->title || p1->subject != N->subject || p1->author != N->author)) {
		p2 = p1;
		p1 = p1->Next;
	}
	if (p1 && p2) {
		p2->Next = p1->Next;
		delete p1;
	}
	else if (p1 && !p2) {
		k->headbookaccount = p1->Next;
		delete p1;
	}
}
void library::DeleteBookItemInAccount(Gmember* k, BookItem* N) {
	BookItem* p1 = k->headitemaccount;
	BookItem* p2 = NULL;
	while (p1 && (p1->ISBN != N->ISBN || p1->title != N->title || p1->subject != N->subject || p1->author != N->author || p1->barcode != N->barcode)) {
		p2 = p1;
		p1 = p1->Nextitem;
	}
	if (p1 && p2) {
		p2->Nextitem = p1->Nextitem;
		delete p1;
	}
	else if (p1 && !p2) {
		k->headitemaccount = p1->Nextitem;
		delete p1;
	}
}
void library::ReturnBook(long id, string t, string s, string a, int r, int numpub, string* pub, string date, string n, string pa) {
	Gmember* g = this->searchAccount(n, pa);
	if (!g) {
		cout << "Account was not found\n";
	}
	else {
		if (g->maxBook == 0) {
			cout << "No Book In Account\n";
		}
		else {
			Book* N1 = this->searchBookInAccount(g, id, t, s, a, date, r, numpub);
			BookItem* N2 = this->searchBookItemInAccount(g, id, t, s, a, date, r, numpub);
			if (b == true) {
				this->AddBook(N1->ISBN, N1->title, N1->subject, N1->author, N1->numrack, N1->NumPublishers, N1->publishers, N1->publicationDate);
				g->maxBook--;
				this->DeleteBookInAccount(g, N1);
				int d1, m1;
				cout << "Please Enter today's Date (dd/mm) : \n";
				cout << "Day : ";
				cin >> d1;
				cout << "Month : ";
				cin >> m1;
				int in1 = this->searchIndexBook(g);
				if (g->DateOfTheBorrowingBook[in1].getduedateMonth() == m1) {
					if (g->DateOfTheBorrowingBook[in1].getduedateDay() == d1) {
						cout << "Return Book is done\n";
					}
					else if (g->DateOfTheBorrowingBook[in1].getduedateDay() < d1) {
						cout << "Return Book is done , but you will have to pay a fine for being late in return the book \n";
						g->flagBorrow = false;
					}
					else {
						cout << "Return Book is done \n";
					}
				}
				else if (g->DateOfTheBorrowingBook[in1].getduedateMonth() < m1) {
					if (g->DateOfTheBorrowingBook[in1].getduedateMonth() + 1 == m1) {
						if (30 - g->DateOfTheBorrowingBook[in1].getduedateDay() + d1 <= 14) {
							cout << "Return Book is done\n";
						}
						else {
							cout << "Return Book is done , but you will have to pay a fine for being late in return the book \n";
							g->flagBorrow = false;
						}
					}
					else {
						cout << "Return Book is done , but you will have to pay a fine for being late in return the book \n";
						g->flagBorrow = false;
					}
				}
				else {
					cout << "Return Book is done , but you will have to pay a fine for being late in return the book \n";
					g->flagBorrow = false;
				}
			}
			else if (bi == true) {
				this->AddBookItem(N2->ISBN, N2->barcode);
				g->maxBook--;
				this->DeleteBookItemInAccount(g, N2);
				int d, m;
				cout << "Please Enter today's Date (dd/mm) : \n";
				cout << "Day : ";
				cin >> d;
				cout << "Month : ";
				cin >> m;
				int in = this->searchIndexBookItem(g);
				if (g->DateOfTheBorrowingBookitem[in].getduedateMonth() == m) {
					if (g->DateOfTheBorrowingBookitem[in].getduedateDay() == d) {
						cout << "Return Book is done\n";
					}
					else if (g->DateOfTheBorrowingBookitem[in].getduedateDay() < d) {
						cout << "Return Book is done , but you will have to pay a fine for being late in return the book \n";
						g->flagBorrow = false;
					}
					else {
						cout << "Return Book is done \n";
					}
				}
				else if (g->DateOfTheBorrowingBookitem[in].getduedateMonth() < m) {
					if (g->DateOfTheBorrowingBookitem[in].getduedateMonth() + 1 == m) {
						if (30 - g->DateOfTheBorrowingBookitem[in].getduedateDay() + d <= 14) {
							cout << "Return Book is done\n";
						}
						else {
							cout << "Return Book is done , but you will have to pay a fine for being late in return the book \n";
							g->flagBorrow = false;
						}
					}
					else {
						cout << "Return Book is done , but you will have to pay a fine for being late in return the book \n";
						g->flagBorrow = false;
					}
				}

			}
			else {
				cout << "Book was not found\n";
			}
		}

	}
}
int library::searchIndexBook(Gmember* k) {
	int i = 0;
	Book* N = k->headbookaccount;
	while (N && N != this->searchBookInAccount(k, N->ISBN, N->title, N->subject, N->author, N->publicationDate, N->numrack, N->NumPublishers)) {
		N = N->Next;
		i++;
	}
	return i;
}
int library::searchIndexBookItem(Gmember* k) {
	int i = 0;
	BookItem* N = k->headitemaccount;
	while (N && N != this->searchBookItemInAccount(k, N->ISBN, N->title, N->subject, N->author, N->publicationDate, N->numrack, N->NumPublishers)) {
		N = N->Nextitem;
		i++;
	}
	return i;
}
void library::SetLibrarian(librarian M) {
	this->person = M;
}
string library::whoTookABook(long i) {
	Gmember* p = headmember;
	if (!p) {
		return "No Account , please Add account";
	}
	Book* b;
	BookItem* bi;
	bool flag = true;
	while (p && flag) {
		b = p->headbookaccount;
		while (b && b->ISBN != i && flag) {
			b = b->Next;
		}
		if (b) {
			flag = false;
		}
		else {
			bi = p->headitemaccount;
			while (bi && bi->ISBN != i && flag) {
				bi = bi->Nextitem;
			}
			if (bi) {
				flag = false;
			}
			if (flag == true) {
				p = p->Nextmemb;
			}
		}
	}
	if (!p) {
		return "Not found Book...";
	}
	else
		return p->name;
}
void library::RenewABook(long id, string t, string s, string a, int r, int numpub, string* pub, string date, string n, string pass) {
	Gmember* g = this->searchAccount(n, pass);
	if (!g) {
		cout << "Account was not found\n";
	}
	else {
		Book* N1 = this->searchBookInAccount(g, id, t, s, a, date, r, numpub);
		BookItem* N2 = this->searchBookItemInAccount(g, id, t, s, a, date, r, numpub);
		if (b == true) {
			int in = this->searchIndexBook(g);
			g->DateOfTheBorrowingBook[in].EditDueDate();
			cout << "Renewed Book successfully\n";
		}
		else if (bi == true) {
			int in = this->searchIndexBookItem(g);
			g->DateOfTheBorrowingBookitem[in].EditDueDate();
			cout << "Renewed Book successfully\n";
		}
		else {
			cout << "Book was not found\n";
		}
	}
}
void library::AddBooktoFile(ofstream& fptr,fstream& f) {
	Book* p = this->headBook;
	if (p) {
		while (p) {
			fptr << "ISBN : " << p->ISBN << "\n";
			f << p->ISBN << "\n";
			fptr << "title : " << p->title << "\n";
			f << p->title << "\n";
			fptr << "subject : " << p->subject << "\n";
			f << p->subject << "\n";
			fptr << "author : " << p->author << "\n";
			f << p->author << "\n";
			fptr << "number of the rack : " << p->numrack << "\n";
			f << p->numrack << "\n";
			fptr << "number of publishers : " << p->NumPublishers << "\n";
			f << p->NumPublishers << "\n";
			fptr << "Publishers : \n";
			for (int i = 0; i < p->NumPublishers; i++) {
				fptr << i + 1 << ". " << p->publishers[i] << "\n";
				f << p->publishers[i] << "\n";
			}
			fptr << "Publication date : " << p->publicationDate << "\n";
			f << p->publicationDate << "\n";
			fptr << "-------------------------------------------------------------------------\n";
			p = p->Next;
		}
	}
	else return;
	fptr.close();
	f.close();
}
void library::AddBookToLibFromFile(fstream& fptr1) {
	string test;
	long i;
	string t, s, a, date;
	int r, num;
	string* p;
	int j;
	fptr1 >> test;
	if (test!="") {
		fptr1.close();
		fptr1.open("ImaginaryBook.txt",fstream::in);
		while (fptr1>>i) {
			fptr1.ignore();
			getline(fptr1, t);
			getline(fptr1, s);
			getline(fptr1, a);
			fptr1 >> r;
			fptr1 >> num;
			p = new string[num];
			fptr1.ignore();
			for (j = 0; j < num; j++) {
				getline(fptr1, p[j]);
			}
			getline(fptr1, date);
			this->AddBook(i, t, s, a, r, num, p, date);
			delete []p;
		}
	}
	fptr1.close();
}
void library::AddBookitemtoFile(ofstream& fptr, fstream& f) {
	Book* p = this->headBook;
	while (p) {
		BookItem* N = p->headitem;
		while (N) {
			fptr << "ISBN : " << N->ISBN << "\n";
			f << N->ISBN << "\n";
			fptr << "barcode : " << N->barcode << "\n";
			f << N->barcode << "\n";
			fptr << "----------------------------------\n";
			N = N->Nextitem;
		}
		p = p->Next;
	}
	fptr.close();
	f.close();
}
void library::AddBookitemToLibFromFile(fstream& fptr1) {
	string test;
	long i;
	int bcode;
	fptr1 >> test;
	if (test != "") {
		fptr1.close();
		fptr1.open("ImaginaryBookitem.txt", fstream::in);
		while (fptr1 >> i) {
			fptr1 >> bcode;
			this->AddBookItem(i, bcode);
		}
	}
	fptr1.close();
}
void library::AddAccountToFile(fstream& f) {
	Gmember* g = this->headmember;
	while (g) {
		f << g->name << "\n";
		f << g->password << "\n";
		f << g->address << "\n";
		f << g->phone << "\n";
		f << g->flagBorrow << "\n";
		f << g->maxBook << "\n";
		Book* b = g->headbookaccount;
		BookItem* bi = g->headitemaccount;
		if (g->maxBook == 2) {
			if (!bi) {
				int i = 0;
				while (b) {
					f << b->ISBN << "\n";
					f << b->title << "\n";
					f << b->subject << "\n";
					f << b->author << "\n";
					f << b->numrack << "\n";
					f << b->NumPublishers << "\n";
					for (int i = 0; i < b->NumPublishers; i++) {
						f << b->publishers[i] << "\n";
					}
					f << b->publicationDate << "\n";
					f << g->DateOfTheBorrowingBook[i];
					f << g->DateOfTheBorrowingBook[i].getduedateDay() << " " << g->DateOfTheBorrowingBook[i].getduedateMonth() << "\n";
					i++;
					f << "Book\n";
					b = b->Next;
				}
			}
			else if (!b) {
				int j = 0;
				while (bi) {
					f << bi->ISBN << "\n";
					f << bi->title << "\n";
					f << bi->subject << "\n";
					f << bi->author << "\n";
					f << bi->numrack << "\n";
					f << bi->NumPublishers << "\n";
					for (int i = 0; i < bi->NumPublishers; i++) {
						f << bi->publishers[i] << "\n";
					}
					f << bi->publicationDate << "\n";
					f << g->DateOfTheBorrowingBookitem[j];
					f << g->DateOfTheBorrowingBookitem[j].getduedateDay() << " " << g->DateOfTheBorrowingBookitem[j].getduedateMonth() << "\n";
					j++;
					f << "Bookitem\n";
					f << bi->barcode << "\n";
					bi = bi->Nextitem;
				}
			}
			else if (b && bi) {
				f << b->ISBN << "\n";
				f << b->title << "\n";
				f << b->subject << "\n";
				f << b->author << "\n";
				f << b->numrack << "\n";
				f << b->NumPublishers << "\n";
				for (int i = 0; i < b->NumPublishers; i++) {
					f << b->publishers[i] << "\n";
				}
				f << b->publicationDate << "\n";
				f << g->DateOfTheBorrowingBook[0];
				f << g->DateOfTheBorrowingBook[0].getduedateDay() << " " << g->DateOfTheBorrowingBook[0].getduedateMonth() << "\n";
				f << "Book\n";
				f << bi->ISBN << "\n";
				f << bi->title << "\n";
				f << bi->subject << "\n";
				f << bi->author << "\n";
				f << bi->numrack << "\n";
				f << bi->NumPublishers << "\n";
				for (int i = 0; i < bi->NumPublishers; i++) {
					f << bi->publishers[i] << "\n";
				}
				f << bi->publicationDate << "\n";
				f << g->DateOfTheBorrowingBookitem[0];
				f << g->DateOfTheBorrowingBookitem[0].getduedateDay() << " " << g->DateOfTheBorrowingBookitem[0].getduedateMonth() << "\n";
				f << "Bookitem\n";
				f << bi->barcode << "\n";
			}

		}
		else if (g->maxBook == 1) {
			if (!bi) {
				f << b->ISBN << "\n";
				f << b->title << "\n";
				f << b->subject << "\n";
				f << b->author << "\n";
				f << b->numrack << "\n";
				f << b->NumPublishers << "\n";
				for (int i = 0; i < b->NumPublishers; i++) {
					f << b->publishers[i] << "\n";
				}
				f << b->publicationDate << "\n";
				f << g->DateOfTheBorrowingBook[0];
				f << g->DateOfTheBorrowingBook[0].getduedateDay() << " " << g->DateOfTheBorrowingBook[0].getduedateMonth() << "\n";
				f << "Book\n";
			}
			else if (!b) {
				f << bi->ISBN << "\n";
				f << bi->title << "\n";
				f << bi->subject << "\n";
				f << bi->author << "\n";
				f << bi->numrack << "\n";
				f << bi->NumPublishers << "\n";
				for (int i = 0; i < bi->NumPublishers; i++) {
					f << bi->publishers[i] << "\n";
				}
				f << bi->publicationDate << "\n";
				f << g->DateOfTheBorrowingBookitem[0];
				f << g->DateOfTheBorrowingBookitem[0].getduedateDay() << " " << g->DateOfTheBorrowingBookitem[0].getduedateMonth() << "\n";
				f << "Bookitem\n";
				f << bi->barcode << "\n";
			}
		}
		g = g->Nextmemb;
	}
	f.close();
}
void library::AddAccountToLibFromFile(fstream& f) {
	long i;
	string t, s, a, date;
	int r, num;
	string* pp;
	int day, month,day1,month1;
	int code;
	//////////////////////////////////////////
	string n, pass, ad;
	long p;
	bool flag;
	int maxboo,j;
	string test,test1;
	f >> test;
	if (test != "") {
		f.close();
		f.open("Account.txt", fstream::in);
		//f.ignore();
		while (getline(f,n)) {
			getline(f, pass);
			getline(f, ad);
			f >> p;
			this->NewAccount(n, pass, ad, p);
			Gmember* g = this->searchAccount(n, pass);
			f >> flag;
			g->set_flagborrow(flag);
			f >> maxboo;
			g->maxBook = maxboo;
			for (int k = 0; k < maxboo; k++) {
				f >> i;
				f.ignore();
				getline(f, t);
				getline(f, s);
				getline(f, a);
				f >> r;
				f >> num;
				pp = new string[num];
				f.ignore();
				for (j = 0; j < num; j++) {
					getline(f, pp[j]);
				}
				getline(f, date);
				f >> day >> month;
				f >> day1 >> month1;
				f >> test1;
				if (test1 == "Book") {
					g->DateOfTheBorrowingBook[k].SetDate(day, month);
					g->DateOfTheBorrowingBook[k].Set_dueDate(day1, month1);
					this->AddbookInAccount(g, i, t, s, a, r, num, pp, date);
				}
				else {
					g->DateOfTheBorrowingBookitem[k].SetDate(day, month);
					g->DateOfTheBorrowingBookitem[k].Set_dueDate(day1, month1);
					f >> code;
					this->AddbookitemInAccount(g, i, t, s, a, r, num, pp, date, code);
				}
				delete[]pp;
			}
			f.ignore();
		}
	}
	f.close();
}
void library::pay(Gmember* g) {
	if (g->flagBorrow == false) {
		g->flagBorrow = true;
		cout << "fine was successfully paid\n";
	}
	else
		cout << "There are no fines for him\n";
}