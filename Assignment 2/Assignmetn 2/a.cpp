#include<iostream>
#include"a.h"
using namespace std;
int main()
{
	polynomial a, b, c;
	a.input();
	a.output();
	b.input();
	b.output();
	c = a.multiply(b);
	c.output();
	c = a.plus(b);
	c.output();
	/*polynomial d(4);
	d.input();
	d.output();*/
}