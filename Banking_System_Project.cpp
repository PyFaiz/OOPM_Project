//Bank record system project using Object Oriented Programming
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <list>
#include <ctime>
#include <fstream>
#include <dos.h>
#include <windows.h>
#include <cctype>
#include <limits>
#include <ios>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

vector<int> ids;
vector<int> pins;
vector<int> atm_ids;
vector<string> holder_name;
vector<char> account_type;
vector<int> account_bal;
int intbank[1000];
vector<int> mobiles;


class admin {
private:
	int choice;
	int ID;
	int password;
public:
	void actualpanel() {
		int colWidth = 15;
		cout << setfill('*') << setw(6 * colWidth) << "*" << endl;
		cout << setfill(' ') << fixed;
		cout << setw(colWidth) << "Account Holder Name" << setw(colWidth) << "Account Id" << setw(colWidth)
			 << "Account Type" << setw(colWidth) << "Account Pins" << setw(colWidth	) << "Balance" << endl;
		cout << setfill('*') << setw(6 * colWidth) << "*" << endl;
		cout << setfill(' ') << fixed;
			for (int i = 0; i < ids.size(); i++) {
				cout << setprecision(4) << setw(colWidth) << holder_name[i] << setprecision(4) <<
					setw(colWidth)
					<< ids[i] << setprecision(0) << setw(colWidth) << account_type[i] << setprecision(0) << setw(colWidth) <<pins[i] << setprecision(10) << setw(19) << account_bal[i] << endl;

			}
			cout << "Press Any Key To Go back\n";
			getch();
			system("cls");
	}
	void adminpanel() {
		cout << "**************Welcome To Admin Panel*****************\n\n";
		cout << "\t\t1.Login\n";
		cout << "\t\t2. Go Back\n";
		cin >> choice;
		switch (choice) {
		case 1:
		{
			system("cls");
			cout << "Enter Admin ID:";
			cin >> ID;
			cout << "Enter Admin Password:";
			cin >> password;
			if (ID == 10 && password == 10) {
				actualpanel();
			}
			else {
				char choice2;
				cout << "Wrong ID or Password!!!!!!!!\n";
				cout << "Do You Want to try Again?(Y/N): ";
				cin >> choice2;
				if (choice2 == 'Y' || choice2 == 'y') {
					adminpanel();
				}
				else {
					system("cls");
				}
			}
		}
		}
	}
};

class modifyaccount {
public:
	int choice;
	void mod() {
		system("cls");
		cout << "**************Welcome To Account Modify System*****************\n\n";
		cout << "\t\t1.Modify Account Name\n"; 
		cout << "\t\t2.Modify Account Type\n";
		cout << "\t\t3.Modify Mobile Number\n";
		cout << "\t\t4.Go Back\n";
		cout << "\n********************************************************************\n\n";
		cout << "Enter Service Number: ";
		cin >> choice;
		switch (choice) {
		case 1:
		{
			cout << "Wait";
			break;
		}
		case 2:
		{
			cout << "Wait2";
			break;
		}
		case 3:
		{
			cout << "Wait3";
			break;
		}
		defalut: {
		}
		}
	}
};

class delaccount {
public:
	int choice2;
	void delaccout() {
		system("cls");
		cout << "**************Welcome To Account Delete System*****************\n\n";
		cout << "\t\t1.Delete Your Account\n";
		cout << "\t\t2.Go Back\n";
		cout << "\n********************************************************************\n\n";
		cout << "Enter Service Number: ";
		cin >> choice2;
		switch (choice2) {
		case 1:
		{
			cout << "Wait";
			break;
		}
		case 2:
		{
			cout << "Wait2";
			break;
		}
		case 3:
		{
			cout << "Wait3";
			break;
		}
	defalut: {
		}
		}
	}
};

class newaccount: public modifyaccount,public delaccount {
public:
	;
	char name[50];
	int pin;
	int initialamt;
	char acctype;
	char confirm;
	char atmconfirm;
	int account_id;
	bool atmreq;
	int card_no;
	void creator() {
		system("cls");
		cout << "\nCreating Bank Account Might Take Some Time";
		for (int i = 0; i < 40; i++) {
			cout << ".";
			Sleep(100);
		}
		system("cls");
		cout << "\n====================================\n";
		cout << "\n   Account Creation Successful      \n";
		cout << "\n====================================\n";
		srand(time(0));
		account_id = rand();
		cout << "\n\nYour Account ID is : " << account_id;
		cout << "\n\nKindly Remember It!!!\n\n";
		if (atmreq == true){
			card_no = rand();
			cout << "Here's Your Card Number: " << card_no << endl;
			cout << "PIN is Same as Your Account PIN\n\n";
			cout << "HAPPY BANKING WITH US!\n";
			atm_ids.push_back(card_no);
		}
		cout << "HAPPY BANKING WITH US!\n";
		cout << "Press Any Key To Go Back To Menu\n";
		_getch();
		system("cls");
		ids.push_back(account_id);
	}
	void details() {

		cout << "\n====================================\n";
		cout << "\n   Welcome to Account Creation\n";
		cout << "\n====================================\n";
		cin.ignore();
		cout << "Enter The Account Holder First Name :";
		cin.getline(name, 50);
		cin.sync();
		cout << "Account Type [Saving(s)/Current(c)] : ";
		cin >> acctype;
		if (acctype != 'C' && acctype != 'c' && acctype != 's' && acctype != 'S') {
			system("cls");
			cout << "Can't be empty\n\n";
			details();
		}
		cout << "Accout PIN: ";
		cin >> pin;
		cout << "Enter The Initial amount(>=500 ) :";
		cin >> initialamt;
		if (initialamt < 500) {
			system("cls");
			cout << "Initial Amount Too Low Try Again....";
			details();
		}
		cout << "\nWould You Like ATM card?(Y/N) :";
		cin >> atmconfirm;
		system("cls");
		cout << "\n====================================\n";
		cout << "\n  Thanks For Filling In Details    \n";
		cout << "\n====================================\n";
		cout << "***********Please Verify These Information So we can generate The Account Number**********\n\n";
		cout << "Account Holder Name: " << name << endl;
		cout << "Account Type: ";
		if (acctype == 's' || acctype == 'S') {
			cout << "Saving" << endl;
		}
		else
		{
			cout << "Current" << "\n";
		}
		if (atmconfirm == 'Y' || atmconfirm == 'y') {
			cout << "ATM Card: YES\n";
			atmreq = true;
		}
		else {
			cout << "ATM CARD: NO\n";
			atmreq = false;
		}
			
		cout << "Account PIN: " << pin << endl;
		cout << "Account Current Balance: " << initialamt << endl;
		cout << "\n====================================\n";
		cout << "\nIf you Want to Cancel Account Creation Enter C\n\n";
		cout << "IS THIS INFORMATION CORRECT?(Y/N)  : ";
		cin >> confirm;
		if (confirm == 'Y' || confirm == 'y') {
			holder_name.push_back(name);
			account_type.push_back(acctype);
			pins.push_back(pin);
			account_bal.push_back(initialamt);
			creator();
		}
		else if (confirm == 'C' || confirm == 'c') {
			system("cls");
			cout << "ACCOUNT CREATION CANCELLED";
			cout << "\n\nReturning To Menu\n\n";
			for (int i = 0; i < 25; i++) {
				cout << ".";
				Sleep(100);
			}
			system("cls");

		}
		else {
			cout << "Ok Then Try Again";
			Sleep(500);
			system("cls");
			details();
		}
	}
	
};

void gotoxy(int i, int j)
{
	int o = 0, p = 0;
	for (; p <= j; p++)
	{
		cout << "\n";
	}
	for (; o <= i; o++)
	{
		cout << " ";
	}

}

class starting_functions {
public:
	void start() {
		cout << "\t_____________________________\n";
		cout << "\t|   Welcome To Fizvil Bank  |\n";
		cout << "\t-----------------------------\n";
	}
	
};
//int starting_functions::service;
class timethings {
public:
	int time_hour;
	time_t now = time(NULL);
	tm* ltm = localtime(&now);
	void gettime() {
		
		cout << "\t\t  " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl ;
		//time_hour = ltm->tm_hour;
		//cout << "\t" << ltm->tm_wday;
	}
	void bank_info() {
		Sleep(2000);
		cout << "\tMaking People Happy Since 1949\n\n";
		Sleep(2000);
	}
	void loadtime() {
		cout << "\nLoading Your Services";
		for (int i = 0; i < 10; i++) {
			cout << ".";
			Sleep(100);
		}
	}
	void greets_login() {
		if (ltm->tm_hour < 12 && ltm->tm_hour >= 5)
			cout << "Good Morning!!!" << endl;
		else if (ltm->tm_hour <= 24 && ltm->tm_hour >= 17)
			cout << "Good Evening!!!" << endl;
		else if (ltm->tm_hour < 17 && ltm->tm_hour >= 12)
			cout << "Good Afteroon!!!" << endl;
		else cout << "Good Evening!!!" << endl;
	}
};

class login_system  {
public:
	bool access = false;
	int  account_id;
	int Pin;
	void login() {
		
		cout << "\n\n||| Welcome to Login Page |||\n\n" << endl;
		cout << "Please Wait While We initailize resources";
		for (int i = 0; i < 15; i++) {
			Sleep(200);
			cout << ".";
		}
		cout << "\n\nEnter your Account Id : ";
		cin >> account_id;
		cout << "\n\nEnter your Account Pin : ";
		cin >> Pin;
		cin.sync();
		for (int i = 0; i < ids.size(); i++) {
			if (account_id == ids[i]) {
				if (Pin == pins[i]) {
					system("cls");
					cout << "=====================================\n";
					cout << "Login Successfully";
					access = true;
					break;
				}
				else {
					login();
				}
			}
		}
		if (access == false) {
			cout << "Do You Want To Try Again?(Y/N) :";
			cin >> tryagain;
		}
		if (tryagain == 'Y' || tryagain == 'y') {
			system("cls");
			login();
		}
		else {
			system("cls");
		}
	}
	bool successful() {
		if (access) {
			return true;
		}
		else
			return false;
	}	
private:
	char tryagain;
	
};


class bank :public timethings, public starting_functions,public newaccount,public login_system {
private:
	//int i;
public:
	starting_functions* star = new starting_functions();
	timethings* time = new timethings();
	login_system* person = new login_system();
	newaccount* per = new newaccount();
	admin* adm = new admin();
	static int choice1;
	static int service;
	void show_options();
	void options();
	void account_things();
	bank()
	{
		star->start();
		time->gettime();
		time->bank_info();
		options();
	};
	
};
int bank::choice1;
int bank::service;

int main(){
	ids.push_back(0);
	pins.push_back(0);
	holder_name.push_back("admin");
	account_type.push_back('s');
	atm_ids.push_back(0);
	account_bal.push_back(1000000);
	//memset(&atm_ids, -1, sizeof(atm_ids));
	memset(intbank, -1, sizeof(intbank));
	bank* acc1 = new bank();
	return 0;
}

void bank::show_options()
{
	cout << "\n\n***************Select One of the option Below*************\n\n";
	cout << "\t\t1. Login to your bank account\n";
	cout << "\t\t2. New Account\n";
	cout << "\t\t3. Close an Account\n";
	cout << "\t\t4. Modify Information\n";
	cout << "\t\t5. Back\n\n";
	cout << "**************************************************************\n\n";
	cout << "\nEnter Service Number: ";
	cin >> bank::choice1;
	if (bank::choice1 == 5) {
		system("cls");
		time->loadtime();
		options();
	}
	else if (bank::choice1 == 1) {
		system("cls");
		person->login();
		if (person->successful()) {
			account_things();
		}
		//cout << "Service 2 in progress";
		show_options();
	}
	else if (bank::choice1 == 2) {
		system("cls");
		per->details();
		options();
	}
	else if (choice1 == 3) {
		system("cls");
		per->delaccout();
		show_options();
	}
	else if (choice1 == 4)
	{
		system("cls");
		per->mod();
		show_options();
	}

}
void bank::options()
{
	cout << "\n**********Select One of the option below***********\n\n";
	cout << "\t\t1. Enter Bank\n";
	cout << "\t\t2. Enter  ATM\n";
	cout << "\t\t3. Check Account Balance\n";
	cout << "\t\t4. Admin Login\n";
	cout << "\t\t5. Exit Software\n";
	cout << "\n**************************************************\n\n";
	cout << "Enter Service Number: ";
	cin >> bank::service;
#ifdef _WIN32
	system("cls");
#endif
	if (bank::service == 1) {
		time->loadtime();
		show_options();
	}	
	else if (bank::service == 4) {
		time->loadtime();
		adm->adminpanel();
		show_options();
	}
	else if (service == 2) {
		system("cls");
		cout << "COMING SOON!!!\n";
		cout << "Press Any Key To Go Back\n";
		getch();
		options();
	}
	else if (service == 3) {
		system("cls");
		person->login();
		if (person->successful()) {
			account_things();
		}
		//cout << "Service 2 in progress";
		show_options();
	}
	else if (service == 5) {
		exit(0);
	}
} 
//int starting_functions::service;
void bank::account_things() {
	int given_acc = person->account_id;
	int given_pin = person->Pin;
	int i = 0;
	int deposit;
	int withdrawl;
	int transfer_id;
	int transfer;
	int service2;
	int service3;
	int bill_id;
	int amt;
	for (; i < ids.size(); i++)
	{
		if (given_acc == ids[i]) {
			break;
		}
	}
	string name = holder_name[i];
	char type = account_type[i];
	int bal = account_bal[i];
	cout << "\n====================================\n";
	time->greets_login();
	cout << "Username: ";
	cout << name << "\n";
	cout << "Account ID :" << given_acc << endl;
	cout << "Current Balance :" << bal << endl;
	cout << "\n*********************What Would You Like To Do Today>*****************\n\n";
	cout << "\t\t1. Deposit\n";
	cout << "\t\t2. Withdrawl\n";
	cout << "\t\t3. Bill Pays\n";
	cout << "\t\t4. Money Transfer\n";
	cout << "\t\t5. Internet Banking\n";
	cout << "\t\t6. Fixed Deposit\n";
	cout << "\t\t7. Investments\n";
	cout << "\t\t8. Loans\n";
	cout << "\t\t9. Recharge\n";
	cout << "\t\t10. Log Out\n\n";
	cout << "*************************************************************************";
	cout << "\n\nEnter Service Number: ";
	cin >> service2;
	switch (service2) {
	case 1: {
		cout << "How Much Money You Want To Deposit : ";
		cin >> deposit;
		if (deposit > 1000000) {
			cout << "Can't Deposit This Much\n";
			Sleep(1000);
		}
		else {
			account_bal[i] += deposit;
		}
		system("cls");
		account_things();
	}
	case 2: {
		cout << "How Much Money You Want To Withdraw : ";
		cin >> withdrawl;
		if (withdrawl > account_bal[i]-500) {
			cout << "Can't withdrawl This Much money\n";
			Sleep(1000);
		}
		else {
			account_bal[i] -= withdrawl;
		}
		system("cls");
		account_things();
	}
	case 3: {
		cout << "\n*****************Which type of Bill You Want To Pay?*******************\n";
		cout << "\n\t1.Electricity";
		cout << "\n\t2.Water";
		cout << "\n\t3.Gas";
		cout << "\n******************************************************\n";
		cout << "Enter Service Number: ";
		cin >> service3;
		switch (service3) {
		case 1: {
			cout << "Enter Electricity Bill Id:";
			cin >> bill_id;
			cout << "Enter Bill Amt:";
			cin >> amt;
			if (amt > bal) {
				cout << "You Don't Have Enough Money\n";
				Sleep(400);
			}
			else {
				account_bal[i] -= amt;
			}
			system("cls");
			account_things();
			break;
		}
		case 2: {
			cout << "Enter Water Bill Id:";
			cin >> bill_id;
			cout << "Enter Bill Amt:";
			cin >> amt;
			if (amt > bal) {
				cout << "You Don't Have Enough Money\n";
				Sleep(400);
			}
			else {
				account_bal[i] -= amt;
			}
			system("cls");
			account_things();
			break;
		}
		case 3: {
			cout << "Enter Gas Bill Id:";
			cin >> bill_id;
			cout << "Enter Bill Amt:";
			cin >> amt;
			if (amt > bal) {
				cout << "You Don't Have Enough Money\n";
				Sleep(400);
			}
			else {
				account_bal[i] -= amt;
			}
			system("cls");
			account_things();
			break;
		}
		}
	case 4:
		{
			bool exist= false;
			cout << "Enter Account Id: ";
			cin >> transfer_id;
			for (int j = 0; j < ids.size(); j++) {
				if (transfer_id == ids[j]) {
					exist = true;
					cout << "Enter Amount of Money: ";
					cin >> transfer;
					if (transfer > given_acc) {
						cout << "You Don't Have Enough Money";
					}
					else {
						account_bal[j] += transfer;
						account_bal[i] -= transfer;
					}
				}
			}
				if(exist==false) {
					cout << "Account Does Not Exist";
					system("cls");
					account_things();
				}
			system("cls");
			account_things();
			break;
		}
		case 5:
		{
			char activate;
			long int mobile;
			if (intbank[i] == 0) {
				cout << "\nInternet Banking Is Already Enabled!!\n";
				cout << "Press Any Button to go back ";
				getch();
				system("cls");
				account_things();
			}
			cout << "Do you want to activate Internet Banking?(Y\\N) : ";
			cin >> activate;
			if (activate == 'Y' || activate == 'y') {
				while (true) {
					cout << "Enter Your Mobile Number (0 to cancel) :";
					cin >> mobile;
					if (mobile == 0) {
						account_things();
					}
					int digits = 0;
					int temp = mobile;
					for (int k = 0; k >= 10; k++) {
						if (temp > 0) {
							temp = temp % 10;
							digits++;
						}
					}
					if (digits > 10) {
						cout << "\n\nInvalid Mobile Number";
						cout << "\nTry Again\n";
					}
					else {
						intbank[i] = 0;
						system("cls");
						cout << "Internet Banking Enabled!!!\n\n";
						cout << "Press Any Button to go back ";
						getch();
						system("cls");
						account_things();
					}
					
				}
			}
			else {
				account_things();
			}
		}
		case 6: {
			int choice;
			char choice2;
			int amt;
			int Years;
			system("cls");
			cout << "*****************Fixed Deposit Portal*********************\n\n";
			cout << "Our Bank Provides 8% p.a. Intersent of Fixed Deposit\n\n\n";
			cout << "\t\t1.Deposit Money\n";
			cout << "\t\t2.Go back\n";
			cout << "\n******************************************\n\n";
			cout << "Enter Your Choice:";
			cin >> choice;
			if (choice == 1) {
				cout << "Enter The Amount:";
				cin >> amt;
				if (amt > 500) {
					cout << "Enter Number of Years: ";
					cin >> Years;
					if (Years ==  0) {
						cout << "Zero Year Deposit is inavailable!!\n";
						Sleep(400);
						account_things();
					}
					cout << "You Will recieve $ " << (amt * 8 * Years) / 100 << " Per year\n";
					cout << "Do You Agree? (Y/N) : ";
					cin >> choice2;
					if (choice2 == 'Y' || choice2 == 'y') {
						system("cls");
						account_bal[i] -= amt;
						cout << "Deposit Completed" ;
						cout << "\nPress Any key To Go back!!";
						getch();
						account_things();
					}
				}
			}
			else {
				system("cls");
				account_things();
			}

		}
		case 10:
		{
			system("cls");
			show_options();
		}
		default:
		{
			system("cls");
			account_things();
		}
		}
	}
}

