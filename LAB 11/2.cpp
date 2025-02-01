#include<iostream>
using namespace std;
template<class t>
class par
{
private:
	t values[2];
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
template <class t>
t par<t>::getmin()
{
	        if (values[0] <values[1])
			{
				return values[0];
			}
			return  values [1];
}
int main()
{
	par<double> myobject(1.012, 1.01234);
	cout << myobject.getmax();
}