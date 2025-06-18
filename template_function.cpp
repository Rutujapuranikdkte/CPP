#include<iostream>//use T in place of return type that is int or void
using namespace std;
template <typename T>
T findmax(T a,T b)
{
	if(a>b)
	
		return a;
	else
		return b;
}
template <typename T>
class Calculator
{
	T a,b;
	public:
		Calculator(T x,T y)
		{
			a=x;
			b=y;
		}
		T add()
		{
			return a+b;
		}
		T sub()
		{
			return a-b;
		}
		T mul()
		{
			return a*b;
		}
		T div()
		{
			if(b!=0)
				return a/b;
			else
				cout<<"error";
		}
};
int main()
{
	cout<<"\nMax is:"<<findmax(5,4);
	Calculator <int> c(10,8);
	cout<<"Addition:"<<c.add()<<endl;
	cout<<"Subtraction:"<<c.sub()<<endl;
	cout<<"Multiplication:"<<c.mul()<<endl;
	cout<<"Division:"<<c.div()<<endl;
	return 0;
}
