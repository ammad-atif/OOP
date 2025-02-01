#include<iostream>
#include<conio.h>
using namespace std;
class account
{
public:
    account() {  }
	virtual double get_balance()=0;
	virtual void deposit(double amount)=0;
	virtual void withdraw(double amount) = 0;
	~account() {   }
};

class account_exception :public exception
{
	const char* message;
public:
	account_exception() :message("THIS AMOUNT IS INVALID")
	{};
	const char* what()
	{
		return message;
	}
};

class checking_account:public account
{
private:
	double balance;
public:
	checking_account()
	{
		balance = 0;
	}
	checking_account(double amount)
	{
		balance = amount;
	}
	double get_balance()
	{
		return balance;
	}
	void deposit(double amount)
	{
		balance = amount;
	}
	void withdraw(double amount)
	{
		try
		{
			if (amount > 25000 || amount > balance)
			{
				throw account_exception();
			}
			balance -= amount;
			cout << "YOUR TRANSACTION WAS SUCCESSFULL";
		}
		catch (account_exception e)
		{
			cout << e.what();
		}
	}
};


class saving_account:public account
{
private:
	double balance;
public:
	saving_account()
	{
		balance = 0;
	}
	saving_account(double amount)
	{
		balance = amount;
	}
	double get_balance()
	{
		return balance;
	}
	void deposit(double amount)
	{
		balance = amount;
	}
	void withdraw(double amount)
	{
		try 
		{
			if (amount>25000||amount>balance)
			{
				throw account_exception();
			}
			balance -= amount;
			cout << "YOUR TRANSACTION WAS SUCCESSFULL";
		}
		catch(account_exception e)
		{
			cout << e.what();
		}
	}
};


int main()
{
	int account_type=0;
	double d_amount;
	double t_amount;
	account *a=nullptr;
	cout << "ENTER ACCOUNT TYPE: " << endl << "1) CHECKING ACCOUNT" << endl << "2) SAVING ACCOUNT"<<endl;
	cin >> account_type;
	if (account_type==1)
	{
		a = new checking_account;
		cout << "CHECKING ACCOUNT CREATED"<<endl;
	}
	else if (account_type==2)
	{
		a = new saving_account;
		cout << "SAVING ACCOUNT CREATED" << endl;
	}
	cout << "ENTER INITIAL AMOUNT FOR ACCOUNT CREATION: ";
	cin >> d_amount;
	a->deposit(d_amount);
	cout << "ENTER A TRANSACTION AMOUNT: ";
	cin >> t_amount;
	a->withdraw(t_amount);
	delete a;
}