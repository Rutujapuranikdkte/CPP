#include<iostream>
using namespace std;
 class Administration;
class Person
{
	protected:
		string name;
		int age;
	public:
		Person(string nm,int a)
		{
			name=nm;
			age=a;
		}
		virtual void display()
		{
			cout<<"\nThe name is: "<<name<<"\nThe age is: "<<age;
		}
};
class Student:virtual public Person
{
	protected:
		int rollnum;
		string branch;
		int marks;
	public:
		Student(string nm,int a,int no,string b,int m):Person(nm,a)
		{
			rollnum=no;
			branch=b;
			marks=m;
		}
		void display() override
		{
			cout<<"\nThe rollnumber is:"<<rollnum<<"\nThe branch name is:"<<branch<<"\nThe marks are:"<<marks;
		}
		friend class Administration;
};
class Faculty:virtual public Person
{
	protected:
		int facultyID;
		string department; 
		int salary;
	public:
		Faculty(string nm,int a,int id,string dept,int s):Person(nm,a)
		{
			facultyID=id;
			department=dept;
			salary=s;
		}
		void display() override
		{
			cout<<"\nThe faculty id is:"<<facultyID<<"\nThe dept they teach is:"
			<<department<<"\nTheir salary is:"<<salary;
		}
		friend class Administration;
};
class TeachingAssistant:public Student,public Faculty
{
	
	public:
		TeachingAssistant(string nm,int a,int no,string b,int m,int id,string dept,int s): Person(nm, a), Student(nm, a, no, b, m), Faculty(nm, a, id, dept, s)
		{
			
		}
		void display()
		{
			cout << "\nTeaching Assistant Details:";
			cout << "\nName: " << name << "\nAge: " << age;
			cout << "\nRoll Number: " << rollnum;
			cout << "\nBranch: " << branch;
			cout << "\nMarks: " << marks;
			cout << "\nFaculty ID: " << facultyID;
			cout << "\nDepartment: " << department;
			cout << "\nSalary: " << salary;
		}
};

class Administration
{
	public:
		void showDetails(const Student &s, const Faculty &f) {
			cout << "\nStudent " << s.name << " from " << s.branch << " scored " << s.marks << " marks.";
			cout << "\nFaculty " << f.name << " teaches " << f.department << ".";
		}
};
int main()
{
	Person p("Rutuja",20);
	p.display();
	Student s("Rutuja",20,46,"CSE-AIML",80);
	s.display();
	Faculty f(" Dr. A. Sharma",45,1001,"Computer Science",120000);
	f.display();
	TeachingAssistant t("Priya Desai", 25, 1923105, "CSE (AI-ML)", 2005, 2001, "Artificial Intelligence", 35000);

	t.display();
	// Call Administration friend function
	Administration a;
	a.showDetails(s, f);
	return 0;
}
