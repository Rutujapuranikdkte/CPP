#include<iostream>
#include<fstream>
using namespace std;
int main()
{
ofstream out("student.txt");
out<<"Rutuja 80";
out.close();

string name;
int marks;
ifstream in("student.txt");
in>>name>>marks;
in.close();

cout<<"current data:\n";
cout<<"name"<<name<<"marks"<<marks<<endl;

cout<<"enter new marks";
cin>>marks;

ofstream update("student.txt");
update<<name<<" "<<marks;
update.close();
}
