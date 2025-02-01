#include<iostream>
#include"assignment3.h"
using namespace std;
int main()
{
	polynomial a, b, c;
	cin >> a>> b;
	cout << a << b;
	c = a*b;
	cout << c;
	c = a + b;
	cout << c;
	int val;
	cout << "Enter value of variable to calculate value of polynomial: ";
	cin >> val;
	cout << c(val);
}