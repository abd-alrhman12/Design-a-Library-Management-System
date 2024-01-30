#include <iostream>
#include "account.h"
#include "general_member_account.h"
#include <string>
#include <fstream>
#include "Librarian.h"
#include "general_member_account.h"
#include "lib.h"
using namespace std;
int main() {
	//////////////////////////////
	string test, testname, testpass;
	string na, pass, ad;
	long p;
	/////////////////////////////
	string* pub;
	string nam, addr;
	long pho;
	long id;
	string t, sub, a, date;
	int num, r, code;
	bool flag;
	string who;
	int choice = 0;
	int choice1 = 0;
	int choice2 = 0;
	ifstream f1;
	ofstream f2;
	fstream f3;
	/////////////////////////////////////////
	ofstream f4;
	fstream f5;
	fstream f6;
	librarian Person;
	library l;
	f3.open("ImaginaryBook.txt",fstream::in);
	l.AddBookToLibFromFile(f3);
	f3.close();
	//////////////////////////////////////////////////
	f5.open("ImaginaryBookitem.txt");
	l.AddBookitemToLibFromFile(f5);
	f5.close();
	//////////////////////////////////////////////////
	f6.open("Account.txt", fstream::in);
	l.AddAccountToLibFromFile(f6);
	f6.close();
	///////////////////////////////////// 
	Gmember* gg;
	while (choice != 3) {
		cout << "----------------------------------------------------------------------------------------------------\n";
		cout << "Please choose a number\n";
		cout << "1. librarian\n";
		cout << "2. Public User\n";
		cout << "3. Close Aplication\n";
		cout << "----------------------------------------------------------------------------------------------------\n";
		choice1 = 0;
		choice2 = 0;
		cin >> choice;
		switch (choice) {
		case 1:
			f1.open("librarian.txt");
			if (!f1) {
				cout << "Error file....\n";
			}
			cin.ignore();
			cout << "Name :\n";
			getline(cin, na);
			cout << "Password :\n";
			getline(cin, pass);
			getline(f1, test);
			testname = test;
			getline(f1, test);
			testpass = test;
			if (na == testname && pass == testpass) {
				getline(f1, ad);
				f1 >> p;
				Person.setInfo(na, pass, ad, p);
				l.SetLibrarian(Person);
				while (choice1 != 17) {
					cout << "Please choose a number\n";
					cout << "1. Add Book\n";
					cout << "2. Remove Book\n";
					cout << "3. Edit Book\n";
					cout << "4. Add Book Item\n";
					cout << "5. Remove Book Item\n";
					cout << "6. Edit Book Item\n";
					cout << "7. Search book by title\n";
					cout << "8. Search book by author\n";
					cout << "9. Serach book by subject\n";
					cout << "10. Serach book by publication date\n";
					cout << "11. Add Account\n";
					cout << "12. Cancel Account\n";
					cout << "13. Find out who borrowed a book ? \n";
					cout << "14. Show library card in librarian\n";
					cout << "15. Show library card in Account\n";
					cout << "16. Pay a late fine for an account\n";
					cout << "17. Close\n";
					cin >> choice1;
					switch (choice1) {
					case 1:
						cout << "Please Enter the ISBN :\n";
						cin >> id;
						cout << "Please Enter the title :\n";
						cin.ignore();
						getline(cin, t);
						cout << "Please Enter the subject :\n";
						getline(cin, sub);
						cout << "Please Enter the author :\n";
						getline(cin, a);
						cout << "Please Enter number of the rack :\n";
						cin >> r;
						cout << "Please Enter the number of the publishers :\n";
						cin >> num;
						pub = new string[num];
						cout << "Please Enter names Publishers :\n";
						cin.ignore();
						for (int i = 0; i < num; i++) {
							getline(cin,pub[i]);
						}
						cout << "Please Enter publication date (dd/mm/yyyy) :\n";
						cin >> date;
						l.AddBook(id, t, sub, a, r, num, pub, date);
						cout << "Add Book is done\n";
						break;
					case 2:
						cout << "Please Enter the ISBN :\n";
						cin >> id;
						flag = l.RemoveBook(id);
						if (flag == true) {
							cout << "Remove Book is done\n";
						}
						break;
					case 3:
						cout << "Please Enter the ISBN :\n";
						cin >> id;
						l.EditBook(id);
						break;
					case 4:
						cout << "Please Enter the ISBN :\n";
						cin >> id;
						cout << "Please Enter the barcode :\n";
						cin >> code;
						l.AddBookItem(id, code);
						cout << "Add Book Item is done\n";
						break;
					case 5:
						cout << "Please Enter the ISBN :\n";
						cin >> id;
						cout << "Please Enter the barcode :\n";
						cin >> code;
						flag = l.RemoveBookItem(id, code);
						if (flag == true) {
							cout << "Remove BookItem is done\n";
						}
						break;
					case 6:
						cout << "Please Enter the ISBN :\n";
						cin >> id;
						cout << "Please Enter the barcode :\n";
						cin >> code;
						l.EditBookItem(id, code);
						break;
					case 7:
						cout << "Please Enter the title :\n";
						cin.ignore();
						getline(cin, t);
						Book* p;
						p = l.SearchByTitleBook(t);
						//if (!p) {
							//cout << "Book was not found\n";
						//}
						//else {
							//l.printBook(p);
						//}
						break;
					case 8:
						cout << "Please Enter the author :\n";
						cin.ignore();
						getline(cin, a);
						Book* p1;
						p1 = l.SearchByAuthorBook(a);
						if (!p1) {
							cout << "Book was not found\n";
						}
						else {
							l.printBook(p1);
						}
						break;
					case 9:
						cout << "Please Enter the subject :\n";
						cin.ignore();
						getline(cin, sub);
						Book* p2;
						p2 = l.SearchBySubjectBook(sub);
						if (!p2) {
							cout << "Book was not found\n";
						}
						else {
							l.printBook(p2);
						}
						break;
					case 10:
						cout << "Please Enter the publication date (dd/mm/yyyy) :\n";
						cin >> date;
						Book* p3;
						p3 = l.SearchByDateBook(date);
						if (!p3) {
							cout << "Book was not found\n";
						}
						else {
							l.printBook(p3);
						}
						break;
					case 11:
						cout << "Please Enter name of the Account :\n";
						cin.ignore();
						getline(cin, nam);
						cout << "Please Enter Password of the Account :\n";
						getline(cin, pass);
						cout << "Please Enter address of the Account :\n";
						getline(cin, addr);
						cout << "Please Enter phone of the Account :\n";
						cin >> pho;
						l.NewAccount(nam, pass, addr, pho);
						cout << "Add Account general member is done\n";
						break;
					case 12:
						cout << "Please Enter name of the Account :\n";
						cin.ignore();
						getline(cin, nam);
						cout << "Please Enter Password of the Account :\n";
						getline(cin, pass);
						cout << "Please Enter address of the Account :\n";
						getline(cin, addr);
						cout << "Please Enter phone of the Account :\n";
						cin >> pho;
						l.DeleteAccount(nam, pass, addr, pho);
						break;
					case 13:
						cout << "Please Enter the ISBN Book : \n";
						cin >> id;
						who = l.whoTookABook(id);
						if (who == "No Account , please Add account" || who == "Not found Book...") {
							cout << "---------------------------------------------------------------------------------------------------------------------\n";
							cout << who << "\n";
							cout << "---------------------------------------------------------------------------------------------------------------------\n";
						}
						else
							cout << "Who borrowed the book is : " << who << endl;
						break;
					case 14 :
						Person.ShowCard();
						break;
					case 15 :
						cout << "Please Enter the Name :\n";
						cin.ignore();
						getline(cin, nam);
						cout << "Please Enter the Password :\n";
						getline(cin, pass);
						gg=l.searchAccount(nam, pass);
						if (gg) {
							gg->Showcard(gg);
						}
						else {
							cout << "Account was not found\n";
						}
						break;
					case 16:
						cout << "Please Enter the Name :\n";
						cin.ignore();
						getline(cin, nam);
						cout << "Please Enter the Password :\n";
						getline(cin, pass);
						gg = l.searchAccount(nam, pass);
						l.pay(gg);
						break;
					case 17:
						f2.open("Book.txt");
						f3.open("ImaginaryBook.txt",fstream::out);
						remove("Book.txt");
						remove("ImaginaryBook.txt");
						f2.close();
						f3.close();
						f2.open("Book.txt");
						f3.open("ImaginaryBook.txt",fstream::out);
						l.AddBooktoFile(f2,f3);
						f2.close();
						f3.close();
						///////////////////////////////////////////////////
						f4.open("Bookitem.txt");
						f5.open("ImaginaryBookitem.txt",fstream::out);
						remove("Bookitem.txt");
						remove("ImaginaryBookitem.txt");
						f4.close();
						f5.close();
						f4.open("Bookitem.txt");
						f5.open("ImaginaryBookitem.txt", fstream::out);
						l.AddBookitemtoFile(f4, f5);
						f4.close();
						f5.close();
						/////////////////////////////////////////////////
						f6.open("Account.txt", ios::out);
						remove("Account.txt");
						f6.close();
						f6.open("Account.txt", ios::out);
						l.AddAccountToFile(f6);
						f6.close();
						/////////////////////////////////////////////////
						f1.close();
						break;
					default:
						cout << "---------------------------------------------------------------------------------------------------------------------\n";
						cout << "                   invalid input , please enter the number between 1 and 14                                          \n";
						cout << "---------------------------------------------------------------------------------------------------------------------\n";
						break;
					}
				}
			}
			else {
				cout << "---------------------------------------------------------------------------------------------------------------------\n";
				cout << "                                         Error in name or password                                                   \n";
				cout << "---------------------------------------------------------------------------------------------------------------------\n";
				f1.close();
			}
			break;
		case 2:
			while (choice2 != 4) {
				cout << "Please choose a number\n";
				cout << "1. Borrow a Book\n";
				cout << "2. Return Book to Library\n";
				cout << "3. Renew a Book in Library\n";
				cout << "4. Close\n";
				cin >> choice2;
				switch (choice2) {
				case 1:
					cout << "Enter Information Account\n";
					cout << "--------------------------------\n";
					cout << "Please Enter name of the Account :\n";
					cin.ignore();
					getline(cin, nam);
					cout << "Please Enter Password of the Account :\n";
					getline(cin, pass);
					cout << "--------------------------------------\n";
					cout << "Enter Information Book\n";
					cout << "----------------------------------------\n";
					cout << "Please Enter the title :\n";
					getline(cin, t);
					cout << "Please Enter the subject :\n";
					getline(cin, sub);
					cout << "Please Enter the author :\n";
					getline(cin, a);
					cout << "Please Enter publication date (dd/mm/yyyy) :\n";
					cin >> date;
					l.BorrowABook(t, sub, a, date, nam, pass);
					break;
				case 2:
					cout << "Enter Information Account\n";
					cout << "--------------------------------\n";
					cout << "Please Enter name of the Account :\n";
					cin.ignore();
					getline(cin, nam);
					cout << "Please Enter Password of the Account :\n";
					getline(cin, pass);
					cout << "--------------------------------------\n";
					cout << "Enter Information Book\n";
					cout << "----------------------------------------\n";
					cout << "Please Enter the ISBN :\n";
					cin >> id;
					cout << "Please Enter the title :\n";
					cin.ignore();
					getline(cin, t);
					cout << "Please Enter the subject :\n";
					getline(cin, sub);
					cout << "Please Enter the author :\n";
					getline(cin, a);
					cout << "Please Enter number of the rack :\n";
					cin >> r;
					cout << "Please Enter the number of the publishers :\n";
					cin >> num;
					pub = new string[num];
					cout << "Please Enter names Publishers :\n";
					cin.ignore();
					for (int i = 0; i < num; i++) {
						getline(cin, pub[i]);
					}
					cout << "Please Enter publication date (dd/mm/yyyy) :\n";
					cin >> date;
					l.ReturnBook(id, t, sub, a, r, num, pub, date, nam, pass);
					break;
				case 3:
					cout << "Enter Information Account\n";
					cout << "--------------------------------\n";
					cout << "Please Enter name of the Account :\n";
					cin.ignore();
					getline(cin, nam);
					cout << "Please Enter Password of the Account :\n";
					getline(cin, pass);
					cout << "--------------------------------------\n";
					cout << "Enter Information Book\n";
					cout << "---------------------------------------\n";
					cout << "Please Enter the ISBN :\n";
					cin >> id;
					cout << "Please Enter the title :\n";
					cin.ignore();
					getline(cin, t);
					cout << "Please Enter the subject :\n";
					getline(cin, sub);
					cout << "Please Enter the author :\n";
					getline(cin, a);
					cout << "Please Enter number of the rack :\n";
					cin >> r;
					cout << "Please Enter the number of the publishers :\n";
					cin >> num;
					pub = new string[num];
					cout << "Please Enter names Publishers :\n";
					cin.ignore();
					for (int i = 0; i < num; i++) {
						getline(cin, pub[i]);
					}
					cout << "Please Enter publication date (dd/mm/yyyy) :\n";
					cin >> date;
					l.RenewABook(id, t, sub, a, r, num, pub, date, nam, pass);
					break;
				case 4:
					f2.open("Book.txt");
					f3.open("ImaginaryBook.txt", fstream::out);
					remove("Book.txt");
					remove("ImaginaryBook.txt");
					f2.close();
					f3.close();
					f2.open("Book.txt");
					f3.open("ImaginaryBook.txt", fstream::out);
					l.AddBooktoFile(f2, f3);
					f2.close();
					f3.close();
					///////////////////////////////////////////////////
					f4.open("Bookitem.txt");
					f5.open("ImaginaryBookitem.txt", fstream::out);
					remove("Bookitem.txt");
					remove("ImaginaryBookitem.txt");
					f4.close();
					f5.close();
					f4.open("Bookitem.txt");
					f5.open("ImaginaryBookitem.txt", fstream::out);
					l.AddBookitemtoFile(f4, f5);
					f4.close();
					f5.close();
					/////////////////////////////////////////////////
					f6.open("Account.txt", ios::out);
					remove("Account.txt");
					f6.close();
					f6.open("Account.txt", ios::out);
					l.AddAccountToFile(f6);
					f6.close();
					break;
				default:
					cout << "---------------------------------------------------------------------------------------------------------------------\n";
					cout << "                   invalid input , please enter the number between 1 and 3                                           \n";
					cout << "---------------------------------------------------------------------------------------------------------------------\n";
					break;
				}
			}
			break;
		case 3:
			cout << "---------------------------------------------------------------------------------------------------------------------\n";
			cout << "                                                              Bye!                                                   \n";
			cout << "---------------------------------------------------------------------------------------------------------------------\n";
			break;
		default:
			cout << "---------------------------------------------------------------------------------------------------------------------\n";
			cout << "                   invalid input , please enter the number between 1 and 3                                           \n";
			cout << "---------------------------------------------------------------------------------------------------------------------\n";
			break;
		}
	}
	f1.close();
	return 0;
}