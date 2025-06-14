#include<iostream>
using namespace std;
class Bank//function overloading
{
	private:
		double balance=0;
	public:
		Bank()
		{
			balance=0.0;			
		}
		void deposit(int amount)
		{
			balance+=amount;
			cout<<"\nThe balance is: "<<balance;
			
		}
		void deposit(double amount)
		{
			balance+=amount;
			cout<<"\nThe balance is: "<<balance;
			
		}
		void deposit(string upiID)
		{
			double upiAmount = 1000.0;
			balance+=upiAmount;
			cout<<"\nDepositing rupee:"<<upiAmount<<"\nvia UPI from ID:"<<upiID;
		
		}
		
};
class Account//operator overloading
{
	private:
		int A_number;
		int balance;
	public:
		Account(int n,int b)
		{
			A_number=n;
			balance=b;
		}
	void operator+(Account &other)
	{
		other.balance=0;
		this->balance+=other.balance;
	}
	void operator-(int amount)
	{
		if(amount<=balance)
		{
			cout<<"\nyou can easily withdraw the funds:";
			balance=balance-amount;
			cout<<"the remaining balance is:\n"<<balance;
		}
		else
		{
			cout<<"\nyou can not easily withdraw the funds:";
		}
	}
	void display()
	{
		cout<<"\nThe account number is:"<<A_number<<"\nThe balance is: "<<balance;
	}
		
};
int main()
{
	Bank b;
	b.deposit(500);
	b.deposit(300.00);
	b.deposit("rutuja@upi");
	
	Account a1(101,5000);
	Account a2(102,6000);
	
	cout<<"\nbefore transfer";
	a1.display();
	a2.display();
	a1+a2;
	cout<<"\nafter transfer";
	a1.display();
	a2.display();
	
	a1 - 2000;

    cout << "\nAfter Withdrawal:\n";
    a1.display();
	return 0;
}
