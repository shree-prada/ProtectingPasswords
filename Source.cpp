#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class userdata
{
public:
	char u[30], p[30], p1[30], u1[30], rec[80], ch;
	int nump, i;
	void newuser();
	void login();
};
void userdata::newuser()
{
	ofstream fout;
	system("CLS");

	cout << "Enter Username: ";
	cin >> u;

	fout.open(u, ios::out);
	cout << "Enter password: ";
	cin >> p;
	fout << p;
	cout << "Registration completed successfully!....";

	fout.close();
	_getch();
}
void userdata::login()
{
	ifstream fin;
	system("CLS");
	int ch2;

	cout << "Enter user name: ";
	cin >> u;

	cout << "Enter password:";
	cin >> p1;
	fin.open(u, ios::in);
	fin.get(p, 30);
	fin.close();


	if (strcmp(p, p1) == 0)
	{
		do {
			system("CLS");
			nump = 10;

			cout << "\nWelcome to password storage Systm\n";
			cout << "Hi ";
			cout << u;
			cout << " Good day!";
			cout << "\n\n\n\n\n\n\n1.To display your passwords\n2.To save new passwords\n3.To logout from your account\n";
			cout << "\nPlese enter your option:";
			cin >> ch2;
			switch (ch2)
			{
			case 1:

			{       	system("CLS");
			cout << "Your accounts and passwords shown here:";
			ifstream fin;
			fin.open(u, ios::in);
			fin.seekg(0);

			cout << "\n";
			for (i = 0; i <= nump; i++)
			{

				fin.get(rec, 80);
				fin.get(ch);
				if (i != 0)
					cout << rec << "\n";


			}
			fin.close();
			cout << "\nPress any key to continue.....";
			_getch();
			break;

			}

			case 2: {
				system("CLS");
				ofstream fout;
				cout << "\nHow many passwords you want to store";
				cin >> nump;

				cout << "\nEnter your Account and Password separated by : \n";
				cout << "\nExample:S.No Gmail:password";


				fout.open(u, ios::out);
				fout << p;

				for (i = 0; i <= nump; i++)
				{
					cin.get(rec, 80);
					cin.get(ch);
					fout << rec << "\n";
					cout << "\n";
				}
				fout.close();
				break;
			}
			case 3:
				cout << "\nSuccessfully logged out";
				cout << "\nPress any  key to continue...........";
				_getch();
				break;

			default:
				cout << "\nChoose correct option";
			}
		} while (ch2 != 3);



	}
	else
	{
		cout << "\nUser name or password incorrect\n";
		_getch();
	}
}



void main()
{
	system("CLS");
	int ch1, ch2, ch3;
	userdata  ud;;
	do
	{
		system("CLS");
		cout << "\n********************************************************************************";
		cout << "\n                     WELCOME TO STANLEY PASSWORD LOCKER";
		cout << "\n********************************************************************************";

		cout << "\n\n\n1.New user------>Create account\n\n\n2.Existing User------>Login to your account\n\n\n3.Exit";
		cout << "\n\n\nPLEASE ENTER YOUR CHOICE:";
		cin >> ch1;

		switch (ch1)
		{
		case 1:ud.newuser();
			break;

		case 2:
		{	ud.login();

		}
		break;
		case 3:exit(1);
			break;
		}
	} while (ch1 <= 4);
}

