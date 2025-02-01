#include<iostream>
using namespace std;
template<class t,class u>
t getmax(t a,u b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}
template<class t,class u>
t getmin(t a, u b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}
int main()
{
	char i = 'Z';
	int j = 6, k;
	long l = 10, m = 5, n;
	k = getmax<int,long>(i, m);
	n = getmin<int ,char >(j, l);
	cout << k << endl;
	cout << n << endl;
	//no it does not give error.

}