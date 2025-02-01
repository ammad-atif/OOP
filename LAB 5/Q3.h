#pragma once
#include<iostream>
using namespace std;
class ComplexNumber
{
private:
	int* real;
	int* imaginary;
	int a;
	int b;
public:
	ComplexNumber()
	{
		cout << "Constructor called" << endl;
		real = nullptr;
		imaginary = nullptr;
		a = 0;
		b = 0;
	}
	ComplexNumber(int c, int d)
	{
		cout << "Constructor called" << endl;
		a = c;
		b = d;
		real = new int[a];
		imaginary = new int[b];
	}
	~ComplexNumber()
	{
		cout << "Destructor called" << endl;
		delete[]imaginary;
		delete[]real;
	}
	void Input()
	{
		if (a==0&&b==0)
		{
			cout << "Enter total number of real numbers: ";
			cin >> a;
			cout << "Enter total number of imaginary numbers: ";
			cin >> b;
			real = new int[a];
			imaginary = new int[b];
		}
		for (int i = 0; i < a; i++)
		{
			cout << "Enter real number: ";
			cin >> real[i];
		}
		for (int i = 0; i < b; i++)
		{
			cout << "Enter imaginary number: ";
			cin >> imaginary[i];
		}
		for (int i = 1; i < a; i++)
		{
			real[0] = real[0] + real[i];
		}
		for (int i = 1; i < b; i++)
		{
			imaginary[0] = imaginary[0] + imaginary[i];
		}
		a = 1;
		b = 1;
	}
	void Output()
	{
		cout << real[0] << " + " << imaginary[0]<<"i"<<endl;
	}
	float Magnitude()
	{
		float mag;
		int r = real[0] * real[0];
		int im = imaginary[0] * imaginary[0];
		mag = sqrt((r + im));
		return mag;
	}
};
