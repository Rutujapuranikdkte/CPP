// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;
class Balance;
class Bank
{
	private:
		string name;
		int age;
	public:
		Bank(string nm,int a)
		{
		    name=nm;
		    age=a;
		}
		   
			void showBank()
			{
				cout<<"the name is:"<<name<<endl<<"the age is:"<<age<<endl;
			}
			friend class Balance;//friend function
};
class Balance
{
public:

   int balance;
  void getBalance()
			{
			    cout<<"enter balance:";
			    cin>>balance;
			}
			void show()
			{
			    cout<<"balance is:"<<balance;
			}
			friend class Bank;
};
class Deposit :public Balance //single inheritance
{
    public:
    int balance2;
    void depositAmt()
    {
    cout<<"enter amount:";
    cin>>balance2;
    balance+=balance2;
    cout<<"the final balance is:"<<balance;
    }  
};
int main()
{
	Bank b1("Rutuja", 20);
	
	b1.showBank();
	Deposit d;
	d.getBalance();
	d.show();
	d.depositAmt();
	return 0;
}
