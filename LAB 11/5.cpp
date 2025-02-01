#include<iostream>
using namespace std;
template<class t>
class par
{
private:
	t values[2];
	template<class t>
	friend ostream& operator << (ostream& out, const par<t>& p);
public:
	par()
	{
		values[0] = 0;
		values[1] = 0;
	}
	par(t a, t b)
	{
		values[0] = a;
		values[1] = b;
	}
    t getmax()
	{
		        if (values[0] > values[1])
				{
					return values[0];
				}
				return values[1];
	}
	t getmin();
};
template<class t>
ostream& operator << (ostream& out, const par<t>& p)
{
	out << p.values[0]<<endl<<p.values[1]<<endl;
	return out;
}
template <class t>
t par<t>::getmin()
{
	        if (values[0] <values[1])
			{
				return values[0];
			}
			return  values [1];
}

template<class t, int n>
class sequence
{
	t memblock[n];
public:
	void setmember(int x, t value);
	t getmember(int x);
};
template<class t,int x>
void sequence<t, x>::setmember(int a, t value)
{
	memblock[a] = value;
}
template<class t, int x>
t sequence<t, x>::getmember(int a)
{
	return memblock[a];
}
int main()
{
	par <double> y(2.23, 3.45);
	sequence <par<double>, 5> myPairs;
	myPairs.setmember(0, y);
	cout << myPairs.getmember(0) << '\n';
}