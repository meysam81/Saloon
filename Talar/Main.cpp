#include<iostream>
#include<string>
#include<string.h>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;
struct orders
{
	string first_name;
	string last_name;
	int age;
	string address;
	int code_posti;
	int code_melli;
	int phone_number;
	string username;
	string password;
	int tedad_mihman;
	int ghaza;
	//dates date;
	bool bagh=0;
	bool film_bardar = 0;
	bool khanande = 0;
	bool pay = 0;
};
void customer(int);
struct dates
{
	int day;
	int month;
	int year;
};
orders order[100];
int counter = 0;
string inbox[100];
unsigned long deposit = 0;
int counter_inbox = 0;
void list_order()
{
	if (counter == 0)
	{
		cout << "No entry."<<endl;
		_getch();
		return;
	}
	cout << setw(2) << "No."
		<< setw(12) << "First-name"
		<< setw(12) << "Last-name"
		<< setw(5) << "Age"
		<< setw(15) << "Phone-number"
		<< setw(15) << "Tedad-mihman"
		<< setw(8) << "Ghaza" << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << i + 1
			<< setw(12) << order[i].first_name
			<< setw(12) << order[i].last_name
			<< setw(5) << order[i].age
			<< setw(15) << order[i].phone_number
			<< setw(15) << order[i].tedad_mihman
			<< setw(8) << order[i].ghaza << endl;
	}
	_getch();
}
void check()
{
	bool CONTINUE = 1;
	do
	{
		system("cls");
		string head(71, '*'), middle(32, '*');
		cout << head << endl << middle << "Welcome" << middle << endl << head << endl;
		cout << "Username: ";
		string user, pass;
		cin >> user;
		cout << "Password: ";
		cin >> pass;
		for (int i = 0; i < counter; i++)
		{
			if ((user == order[i].username) && (pass == order[i].password))
			{
				customer(i);
				return;
			}
		}
		cout << "Wrong username or password. Try again? (1: yes, 0: no) ";
		cin >> CONTINUE;
	} while (CONTINUE);
}
void function_get_orders(int i)
{
	cout << "Enter your guest number: ";
	cin >> order[i].tedad_mihman;
	cout << "Choose your food:" << endl
		<< "1. Cholo kabab 5,000 T" << endl
		<< "2. Jouje kabab 7,000 T" << endl
		<< "3. Polo morgh 6,000 T" << endl
		<< "Enter your choice: ";
	int select=1;
	cin >> select;
	switch (select)
	{
	case 1:
		order[i].ghaza = 5000;
		break;
	case 2:
		order[i].ghaza = 7000;
		break;
	case 3:
		order[i].ghaza = 6000;
	default:
		cout << "Wrong Entry. We chose Cholo kabab as default for you." << endl;
		_getch();
		break;
	}
	cout << "You want Singer? (1: yes, 0: no) ";
	cin >> order[i].khanande;
	cout << "You want Garden? (1: yes, 0: no) ";
	cin >> order[i].bagh;
	cout << "You want movie taker? (1: yes, 0: no) ";
	cin >> order[i].film_bardar;
	cout << "Taking order successful. Thank you for your time." << endl;
	_getch();
}
void payment(int i)
{
	if (order[i].tedad_mihman == 0 || order[i].pay==1)
	{
		cout << "Your cost is 0 T until now." << endl;
		_getch();
		return;
	}
	int cost = order[i].tedad_mihman*(order[i].ghaza + 2000) + 5000000;
	if (order[i].khanande)
		cost += 300000;
	if (order[i].film_bardar)
		cost += 500000;
	if (order[i].bagh)
		cost += 1000000;
	cout << "Here's your factor:" << endl;
	cout << "Tedad mihman (" << order[i].tedad_mihman << ") * food ("
		<< order[i].ghaza << ") + service for each person (2,000)" << endl
		<< " + Money for one night in talar (5,000,000)" << endl;
	if (order[i].khanande)
		cout << "+ Singer (300,000)" << endl;
	if (order[i].film_bardar)
		cout << "+ Film bardar (500,000)" << endl;
	if (order[i].bagh)
		cout << "+ bagh (1,000,000)" << endl;
	string sum(71, '-');
	cout << "Sum is= " << cost << endl;
	cout << "Enter 1 to continue paying or 0 to skip: ";
	bool paying;
	cin >> paying;
	if (paying)
	{
		system("cls");
		string head(71, '*'), middle(32, '*');
		cout << head << endl << middle << "Welcome" << middle << endl << head << endl;
		cout << "Enter your card number: ";
		int card_number;
		cin >> card_number;
		cout << "Enter you CVV2: ";
		int cvv2;
		cin >> cvv2;
		cout << "Enter your card 2nd password: ";
		int card_pass;
		cin >> card_pass;
		cout << "Enter your card expiration date:" << endl << "Month: ";
		int month;
		cin >> month;
		cout << "Year: ";
		int year;
		cin >> year;
		srand(time(0));
		int caption = 1 + rand() % 10000;
		cout << "Caption: " << caption << endl << "Enter caption: ";
		int test;
		cin >> test;
		if (test == caption)
		{
			cout << "Your payment was successful." << endl;
			order[i].pay = 1;
			deposit += cost;
			cout << "We will contact you for arranging date" << endl;
		}
		else
		{
			cout << "Wrong caption!!!" << endl << "Payment UNSUCCESSFUL!!!" << endl;
		}
		_getch();
	}
}
void registration()
{
	system("cls");
	string head(71, '*'), middle(32, '*');
	cout << head << endl << middle << "Welcome" << middle << endl << head << endl;
	cout << "Enter your first name: ";
	cin >> order[counter].first_name;
	cout << "Enter your last name: ";
	cin >> order[counter].last_name;
	cout << "Enter your age: ";
	cin >> order[counter].age;
	//cout << "Enter your address: ";
	//getline(cin, order[counter].address);
	cout << "Enter your code posti: ";
	cin >> order[counter].code_posti;
	cout << "Enter your code melli: ";
	cin >> order[counter].code_melli;
	cout << "Enter your phone number: ";
	cin >> order[counter].phone_number;
	cout << "Enter your username: ";
	cin >> order[counter].username;
	cout << "Enter your password: ";
	cin >> order[counter++].password;
	cout << endl << "Registration successful. thank you for your patience." << endl;
	_getch();
}
void pass_change(string &pass)
{
	bool continue_pass_change = 1;
	do
	{
		cout << "Enter your current password: ";
		string test_pass;
		cin >> test_pass;
		cout << "Enter your new password: ";
		string new_pass1, new_pass2;
		cin >> new_pass1;
		cout << "Enter your new password again: ";
		cin >> new_pass2;
		if (test_pass == pass)
		{
			if (new_pass1 == new_pass2)
			{
				pass = new_pass1;
				continue_pass_change = 0;
				cout << "Changing password done successfully." << endl;
				_getch();
			}
			else
			{
				cout << "Your new password doesn't match." << endl;
				cout << "Try again? (1: yes, 0: no) ";
				cin >> continue_pass_change;
			}
		}
		else
		{
			cout << "Wrong password." << endl;
			cout << "Try again? (1: yes, 0: no) ";
			cin >> continue_pass_change;
		}
	} while (continue_pass_change);
}
void msg()
{
	/*string ex;
	while (1)
	{
		char x = cin.get();
		int a = x;
		if (a == 10)
			break;
		ex = ex + x;
	}
	inbox[counter_inbox++] = ex;*/
	getline(cin, inbox[counter_inbox++]);
	cout << "Thank you for you time." << endl;
}
void customer(int i)
{
	bool CONTINUE = 1;
	do
	{
		system("cls");
		string head(71, '*'), middle(32, '*');
		cout << head << endl << middle << "Welcome" << middle << endl << head << endl;
		cout << "1. Edit your Information." << endl
			//<< "3. Send gratitude." << endl
			<< "2. Enter an order." << endl
			<< "3. Pay your charge." << endl
			<< "4. Send a message to manager." << endl
			<< "10. Logout." << endl;
		cout << endl << "Enter your choice: ";
		short select;
		cin >> select;
		system("cls");
		cout << head << endl << middle << "Welcome" << middle << endl << head << endl;
		switch (select)
		{
		case 1:
			cout << "Enter your first name: ";
			cin >> order[i].first_name;
			cout << "Enter your last name: ";
			cin >> order[i].last_name;
			cout << "Enter your age: ";
			cin >> order[i].age;
			/*cout << "Enter your address: ";
			getline(cin, order[i].address);*/
			cout << "Enter your code posti: ";
			cin >> order[i].code_posti;
			cout << "Enter your code melli: ";
			cin >> order[i].code_melli;
			cout << "Enter your phone number: ";
			cin >> order[i].phone_number;
			cout << "Enter your username: ";
			cin >> order[i].username;
			cout << "Enter your password: ";
			cin >> order[i].password;
			cout << endl << "Edit successful. thank you for your patience." << endl;
			_getch();
			break;
		//case 3:
		//	cout << "Enter your gratitude text:" << endl;
		//	//getline(cin, inbox[counter_inbox++]);
		//	msg();
		//	_getch();
		//	break;
		case 2:
			function_get_orders(i);
			break;
		case 3:
			payment(i);
			break;
		case 4:
			cout << "Enter your message:" << endl;
			//getline(cin, inbox[counter_inbox++]);
			msg();
			_getch();
			break;
		case 10:
			CONTINUE = 0;
			break;
		default:
			cout << "Wrong Entry!!!" << endl;
			_getch();
			break;
		}
	} while (CONTINUE);
}
void user()
{
	bool CONTINUE = 1;
	do
	{
		system("cls");
		string head(71, '*'), middle(32, '*');
		cout << head << endl << middle << "Welcome" << middle << endl << head << endl;
		cout << "1. I have a username & password." << endl
			<< "2. I don't have a username & password." << endl
			<< "10. Exit" << endl;
		cout << endl << "Enter your choice: ";
		short select;
		cin >> select;
		switch (select)
		{
		case 1:
			check();
			break;
		case 2:
			registration();
			break;
		case 10:
			CONTINUE = 0;
			break;
		default:
			cout << "Wrong choice!!!" << endl;
			_getch();
			break;
		}
	} while (CONTINUE);
}
void admin(string & user, string & pass)
{
	bool CONTINUE = 1;
	do
	{
		system("cls");
		string head(71, '*'), middle(32, '*');
		cout << head << endl << middle << "Welcome" << middle << endl << head << endl;
		cout << "1. Change password" << endl
			<< "2. List all orders" << endl
			//<< "3. Message inbox" << endl
			<< "3. Deposit" << endl
			/*<< "5. Warehouse inventory" << endl*/
			<< "10. logout" << endl
			<< endl << "Enter your choice:";
		short select;
		cin >> select;
		system("cls");
		cout << head << endl << middle << "Welcome" << middle << endl << head << endl;
		switch (select)
		{
		case 1:
			pass_change(pass);
			break;
		case 2:
			list_order();
			break;
		/*case 3:
			if (counter_inbox != 0)
			{
				for (int i = 0; i < counter_inbox; i++)
				{
					cout << i + 1 << inbox[i] << endl;
				}
			}
			else
				cout << "No message." << endl;
			_getch();
			break;*/
		case 3:
			cout << "We have " << deposit << " in our deposit.";
			_getch();
			break;
		case 10:
			CONTINUE = 0;
			break;
		default:
			cout << "WRONG SELECTION!!!" << endl;
			_getch();
			break;
		}
	} while (CONTINUE);
}
void enter_admin(string &admin_user,string &admin_pass)
{
	bool right_or_wrong = 1;
	do
	{
		system("cls");
		string head(71, '*'), middle(32, '*');
		cout << head << endl << middle << "Welcome" << middle << endl << head << endl;
		cout << "Enter your administration username & password" << endl
			<< "Default username & password: admin, admin" << endl;
		string user, pass;
		cout << "Username: ";
		cin >> user;
		cout << "Password: ";
		cin >> pass;
		if (pass == admin_pass && user == admin_user)
		{
			admin(admin_user, admin_pass);
			right_or_wrong = 0;
		}
		else
		{
			cout << "Wrong username or password."
				<< endl << "You want to try again? (1: yes, 0: no) ";
			cin >> right_or_wrong;
		}
	} while (right_or_wrong);
}
int main()
{
	string admin_user("admin"), admin_pass("admin");
	bool CONTINUE = 1;
	do
	{
		system("cls");
		string head(71, '*'), middle(32, '*');
		cout << head << endl << middle << "Welcome" << middle << endl << head << endl;
		cout << "1. I'm the manager" << endl
			<< "2. I'm a customer" << endl
			<< "10. Exit the system" << endl
			<< endl << "Enter your choice:";
		short select;
		cin >> select;
		switch (select)
		{
		case 1:
			enter_admin(admin_user, admin_pass);
			break;
		case 2:
			user();
			break;
		case 10:
			CONTINUE = 0;
			break;
		default:
			cout << "WRONG SELECTION!!!" << endl;
			_getch();
			break;
		}
	} while (CONTINUE);
	return 0;
}