//#include<iostream>
//using namespace std;
//class money
//{
//private:
//	int dollars;
//	int cents;
//	friend ostream& operator<<(ostream& out, const money& a);
//	friend istream& operator>>(istream& out,  money& a);
//public:
//	money()
//	{
//		dollars = 0;
//		cents = 0;
//	}
//	money(int d, int c)
//	{
//		dollars = d;
//		cents = c;
//	}
//	int getdollars()
//	{
//		return dollars;
//	}
//	int getcents()
//	{
//		return cents;
//	}
//	money &operator=(const money& a)
//	{
//		dollars = a.dollars;
//		cents = a.cents;
//	}
//	money& operator+(const money& a)
//	{
//		money c;
//		c.dollars = dollars + a.dollars;
//		c.cents = cents + a.cents;
//		return c;
//	}
//	money operator-(const money& a)
//	{
//		money c;
//		c.dollars = dollars - a.dollars;
//		c.cents = cents - a.cents;
//		return c;
//	}
//	money& operator*= (int a)
//	{
//		dollars *= a;
//		cents *= a;
//		return *this;
//	}
//	money& operator/= (int a)
//	{
//		dollars /= a;
//		cents /= a;
//		return *this;
//	}
//	bool operator== (const money& a)
//	{
//		if (dollars == a.dollars && cents == a.cents)
//		{
//			return 1;
//		}
//		return 0;
//	}
//	~money() {};
//};
//istream& operator>>(istream& in,  money& a) 
//{
//	cout << "Enter dollars: ";
//	cin >> a.dollars;
//	cout << "Enter cents: ";
//	cin >> a.cents;
//	return in;
//}
//ostream& operator<<(ostream& out,const money& a)
//{
//	out << "Dollars: " << a.dollars << endl;;
//	out << "Cents: " << a.cents<< endl;
//	return out;
//}
//int main()
//{
//	money a;
//	cin >> a;
//	cout << a;
//	money b(3, 7);
//	money c = a + b;
//	 a *= 3;
//	 cout << a;
//}