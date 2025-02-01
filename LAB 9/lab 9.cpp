#include<iostream>
using namespace std;
	class person
	{
	private:
		string  fname;
		string  lname;
	protected:
		int age;
	public:
		person()
		{
			fname = "0";
			lname = "0";
			age = 0;
		}
		person(string f,string l,int a)
		{
			fname =f;
			lname = l;
			age = a;
			cout << "Person (CONSTRUCTOR) called" << endl;
		}
		~person()
		{
			cout << "Person(DESTRUCTOR) called" << endl;
		}
		void printInformation()
		{
			cout << fname <<" "<<lname << " is " << age << " year old";
		}
	};
	class student:public person
	{
	private:
		float cgpa;
	public:
		student()
		{
			cgpa = 0;
		}
		~student()
		{
			cout << "Student(DESTRUCTOR) called" << endl;
		}
		student(string f, string  l, int a, float c) : person(f, l, a)
		{
			cout << "Student(CONSTRUCTOR) called";
			cgpa = c;
		}
		void printStudent()
		{
			printInformation(); cout << " his gpa is " << cgpa;
		}
	};
	class graduate:public student
	{
	private:
		string  thesistopic;
	public:
		graduate()
		{
			thesistopic = "0";
		}
		graduate(string  f, string  l, int a, float c,string t):student(f,l,a,c)
		{
			cout << "Graduate(CONSTRUCTOR) called" << endl;
			thesistopic = t;
		}
		~graduate()
		{
			cout << "Graduate(DESTRUCTOR) called" << endl;
		}
		void printGraduate()
		{
			printStudent(); cout << " and his thesis topic is: " << thesistopic<<endl;
		}
	};
	class undergraduate:public student
	{
	private:
		string  fyp_name;
	public:
		undergraduate()
		{
			fyp_name = "0";
		}
		~undergraduate()
		{
			cout << "Undergraduate(DESTRUCTOR) called" << endl;
		}
		undergraduate(string f, string  l, int a, float c,string fyp) :student(f, l, a, c)
		{
			cout << "Undergraduate(CONSTRUCTOR) called" << endl;
			fyp_name = fyp;
		}
		void printUndergraduate()
		{
			printStudent(); cout << " and his final year project is titled: " << fyp_name<<endl;
		}
	};
	class faculty:public person
	{
	private:
		int course_count;
		int txt_ext;
	public:
		faculty()
		{
			course_count = 0;
			txt_ext = 0;
		}
		faculty(string f,string l,int a,int c,int t):person(f,l,a)
		{
			cout << "Faculty(CONSTRUCTOR) called" << endl;
			course_count = c;
			txt_ext = t;
		}
		~faculty()
		{
			cout << "Faculty(DESTRUCTOR) called" << endl;
		}
		void printfaculty()
		{
			printInformation(); cout << " Course_count " <<course_count<<" Ext: "<<txt_ext<<endl;
		}
	};
	int main()
	{
			graduate g("Ali", "Hassan", 22, 3.51, "Distributed Algorithms");
			undergraduate u("John", "Cena", 25, 3.01, " The Even Locator");
			u.printUndergraduate(); 
			g.printGraduate();
			u.printStudent();
	}