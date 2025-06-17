#include<iostream>
using namespace std;
class BankAccount
{
	private:
		string name;
		int balance;
	public:
		BankAccount(string nm,int b)
		{
			name=nm;
			balance=b;
				cout<<"The owner name is: "<<name<<"\nTheir initial balance is: "<<balance;
		}
		void deposit(double amount)
		{
				balance+=amount;
				cout<<"\nThe balance is:"<<balance;	
		}
		void withdraw(double amount)
		{
			try
			{
				if (amount <= balance)
				{
					balance -= amount;
					cout << "\nThe remaining balance is: " << balance << endl;
				}
				else
				{
					throw "Insufficient funds!";
				}
			}
			catch (const char* msg)
			{
				cout << "Error: " << msg << endl;
			}
		}
		void transfer(BankAccount &to, double amount)
		{
			if (amount <= balance)
			{
				balance -= amount;
				to.balance += amount;
				cout << name << " transferred " << amount << " to " << to.name << "." << endl;
				cout << name << "'s balance: " << balance << endl;
				cout << to.name << "'s balance: " << to.balance << endl;
			}
			else
			{
				cout << "Transfer failed: Insufficient funds in " << name << "'s account." << endl;
			}
		}

};
int main()
{
	BankAccount b1("Rahul Sharma",5000);
	BankAccount b2("Priya Mehta", 3000);
	b1.deposit(1200.00);
	b1.withdraw(2000);
	b1.withdraw(5000);
	b1.transfer(b2, 2000); // transfer from Rahul to Priya
	b1.transfer(b2, 10000); // insufficient funds
}
