#include<iostream>
using namespace std;
class Book
{
	private:
		string title;
		string author;
		int pagecount;
	public:
		Book(string t,string a,int c)//parameterized constructor
		{
			title=t;
			author=a;
			pagecount=c;
		}
	
	
	//default constructor
	Book()
	{
		
		  	 title="";
			 author="";
			 pagecount=0;
	}
	
	//copy constructor
	Book(Book& b)
	{
		title=b.title;
		author=b.author;
		pagecount=b.pagecount;
		cout<<"copy constructor is called:\n";
	}
			void show()
			{
				cout<<"Enter title of book:"<<endl;
				cin>>title;
				cout<<"Enter author of the book:"<<endl;
				cin>>author;
				cout<<"Enter page count of book:"<<endl;
				cin>>pagecount;
			}
			void display()
			{
				cout<<"Title of book:"<<title<<"\nName of author is:"<<author<<"\nPage count is:"<<pagecount;
			}
			 ~Book() {
        cout << "Destructor called for book: " << title << endl;
    }
		
};
int main()
{
	Book b1("Wings of fire","Abdul Kalam",300);
	b1.display();
	//parameterized constructor+copy constructor
	Book b2=b1;
	b2.show();
	b2.display();
	return 0;
}
