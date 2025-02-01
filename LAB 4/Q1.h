#pragma once
#include<iostream>
using namespace std;
class employ
{
private:
	float id;
	float position;
	float salary;
	char* name;
public:
	employ()
	{
		name = nullptr;
	}
	~employ()
	{
		if (name!=nullptr)
		{
			delete[]name;
		}
	}
	void inputemployinfo()
	{
		int size;
		cout << "Enter id: ";
		cin >> id;
		cout << "Enter position: ";
		cin >> position;
		cout << "Enter salary: ";
		cin >> salary;
		cout << "Enter length of name: ";
		cin >> size;
		size++;
		name = new char[size];
		cout << "Enter name: ";
		cin.ignore();
		cin.getline(name, size);
	}
	void printemployinfo()
	{
		cout << "Name:  " << name<<endl;
		cout << "ID:  " << id<<endl;
		cout << "POSITION:  " << position<<endl;
		cout << "SALARY:  " << salary<<endl;
	}
};
