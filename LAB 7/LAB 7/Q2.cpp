//#include<iostream>
//using namespace std;
//class polynomial
//{
//private:
//	int t;
//	int* cof;
//	int* exp;
//	friend ostream& operator<< (ostream& out, polynomial a);
//	friend polynomial operator+(int a, polynomial b);
//	void shift(int i)
//	{
//		//this function takes arrays and the index where ther is repeating power coeffecient after operation on polynomial so it can replace the values on indexes after that index
//		while (i < t - 1)
//		{
//			cof[i] = cof[i + 1];
//			exp[i] = exp[i + 1];
//			i++;
//		}
//		t= t - 1;
//	}
//public:
//	polynomial()
//	{
//		t = 0;
//		cof = nullptr;
//		exp = nullptr;
//	}
//	polynomial(int x,int*c,int*e)
//	{
//		t = x;
//		cof = new int[t];
//		exp = new int[t];
//		for (int i = 0; i < t; i++)
//		{
//			cof[i] = c[i];
//			exp[i] = e[i];
//			if (cof[i] == 0)
//			{
//				exp[i] = 0;
//			}
//			//this loop is checking if there is any coeffecient with same power entered before so it can add those coefficients
//			for (int j = 0; j < i; j++)
//			{
//				if (exp[j] == exp[i])
//				{
//					cof[j] = cof[j] + cof[i];
//					i--;
//					t--;
//				}
//				if (cof[j] == 0)
//				{
//					exp[j] = 0;
//				}
//			}
//			//this loop is checking if there is any lower power than this power entered so it can swap higher power coeffecient with lower one
//			for (int j = 0; j < i; j++)
//			{
//				if (exp[i] > exp[j])
//				{
//					swap(cof[i], cof[j]);
//					swap(exp[i], exp[j]);
//				}
//			}
//		}
//		for (int i = 0; i < t; i++)
//		{
//			if (cof[i] == 0 && i != 0)
//			{
//				this->shift(i);
//				i--;
//			}
//		}
//		int* coftemp = new int[t];
//		int* exptemp = new int[t];
//		for (int i = 0; i < t; i++)
//		{
//			coftemp[i] = cof[i];
//		}
//		for (int i = 0; i < t; i++)
//		{
//			exptemp[i] = exp[i];
//		}
//		delete[]cof;
//		delete[]exp;
//		cof = coftemp;
//		exp = exptemp;
//	}
//	polynomial(const polynomial& a)
//	{
//		t = a.t;
//		cof = new int[t];
//		exp = new int[t];
//		for (int i = 0; i < t; i++)
//		{
//			cof[i] = a.cof[i];
//			exp[i] = a.exp[i];
//		}
//	};
//	~polynomial()
//	{
//		if (cof != nullptr)
//		{
//			delete[]cof;
//		}
//		if (exp != nullptr)
//		{
//			delete[]exp;
//		}
//	}
//	bool operator== (polynomial a)
//	{
//		int flag = 1;
//		if (t!=a.t)
//		{
//			return 0;
//		}
//		for (int i = 0; i < t; i++)
//		{
//			if (exp[i]!=a.exp[i])
//			{
//				flag = 0;
//			}
//			if (cof[i] != a.cof[i])
//			{
//				flag = 0;
//			}
//		}
//		return flag;
//	}
//	bool operator!= (polynomial a)
//	{
//		if (*this == a)
//		{
//			return 0;
//		}
//		return 1;
//	}
//	bool operator!()
//	{
//		if (t == 1 && cof[0] == 0 && exp[0] == 0)
//		{
//			return 1;
//		}
//		return 0;
//	}
//	polynomial operator+(polynomial b)
//	{
//		polynomial c;
//		c.t = t + b.t;
//		c.cof = new int[c.t];
//		c.exp = new int[c.t];
//		int x = 0, y = 0, z = 0;
//		//this loop is arranging the coeffecients of 1 and 2 polynomials in descending order
//		while (x < t && y < b.t)
//		{
//			if (exp[x] > b.exp[y])
//			{
//				c.exp[z] = exp[x];
//				c.cof[z] = cof[x];
//				z++;
//				x++;
//			}
//			else
//			{
//				c.exp[z] = b.exp[y];
//				c.cof[z] = b.cof[y];
//				z++;
//				y++;
//			}
//		}
//		while (x < t)
//		{
//			c.exp[z] = exp[x];
//			c.cof[z] = cof[x];
//			z++;
//			x++;
//		}
//		while (y < b.t)
//		{
//			c.exp[z] = b.exp[y];
//			c.cof[z] = b.cof[y];
//			z++;
//			y++;
//		}
//		//this loop is adding the polynomials
//		for (int i = 0; i < c.t; i++)
//		{
//			for (int j = 0; j < i; j++)
//			{
//				if (c.exp[i] == c.exp[j])
//				{
//					c.cof[j] = c.cof[i] + c.cof[j];
//					c.shift(i);
//					i--;
//				}
//				if (c.cof[j] == 0)
//				{
//					c.exp[j] = 0;
//				}
//			}
//		}
//		for (int i = 0; i < c.t; i++)
//		{
//			if (c.cof[i] == 0 && i != 0)
//			{
//				c.shift(i);
//				i--;
//			}
//		}
//		int* temptr1 = new int[c.t];
//		int* temptr2 = new int[c.t];
//		for (int i = 0; i < c.t; i++)
//		{
//			temptr1[i] = c.cof[i];
//		}
//		for (int i = 0; i < c.t; i++)
//		{
//			temptr2[i] = c.exp[i];
//		}
//		delete[]c.cof;
//		delete[]c.exp;
//		c.cof = temptr1;
//		c.exp = temptr2;
//		return c;
//	}
//	polynomial operator++()
//	{
//		for (int i = 0; i < t; i++)
//		{
//			cof[i] = ++cof[i];
//		}
//		return *this;
//	}
//	polynomial operator++(int a)
//	{
//		polynomial c;
//		c.t = t;
//		c.cof = new int[c.t];
//		c.exp = new int[c.t];
//		for (int i = 0; i < c.t; i++)
//		{
//			c.exp[i] = exp[i];
//			c.cof[i] = cof[i];
//		}
//		++* this;
//		return c;
//	}
//	polynomial operator=(const polynomial& a)
//	{
//		t= a.t;
//		if (cof != nullptr || exp != nullptr)
//		{
//			delete[] cof;
//			delete[] exp;
//		}
//		cof = new int[t];
//		exp = new int[t];
//		for (int i = 0; i < t; i++)
//		{
//			cof[i] = a.cof[i];
//			exp[i] = a.exp[i];
//		}
//		return *this;
//	}
//};
//ostream& operator<< (ostream& out,polynomial a)
//{
//	int i;
//	//this function is showing the reult on screen
//	for (i = 0; i < a.t - 1; i++)
//	{
//		if (a.exp[i] != 0 && a.exp[i] != 1)
//		{
//			cout <<a.cof[i] << "x" << "^" << a.exp[i] << " + ";
//		}
//		if (a.exp[i] == 1)
//		{
//			cout << a.cof[i] << "x" << " + ";
//		}
//		if (a.exp[i] == 0)
//		{
//			cout << a.cof[i] << " + ";
//		}
//	}
//	if (a.exp[i] != 0 && a.exp[i] != 1)
//	{
//		cout << a.cof[i] << "x" << "^" << a.exp[i] << endl;
//	}
//	if (a.exp[i] == 1)
//	{
//		cout << a.cof[i] << "x" << endl;
//	}
//	if (a.exp[i] == 0)
//	{
//		cout << a.cof[i] << endl;
//	}
//	return out;
//}
//polynomial operator+(int a, polynomial b)
//{
//	polynomial c;
//	c.t = b.t;
//	c.cof = new int[c.t];
//	c.exp = new int[c.t];
//	for (int i = 0; i < c.t; i++)
//	{
//		c.exp[i] = b.exp[i];
//		c.cof[i] = b.cof[i]+a;
//	}
//	return c;
//}
//
//int main()
//{
//	
//	int coeff_P1[3] = { 1,2,5 }; 
//	int exp_P1[3] = { 4,2,0 };
//	int coeff_P2[2] = { 4,3 }; 
//	int exp_P2[2] = { 6,2 };
//	polynomial P1(3, coeff_P1, exp_P1); 
//	polynomial P2(2, coeff_P2, exp_P2); 
//	cout << "P1 = " << P1 << endl;
//	cout << "P2 = " << P2 << endl;
//	if (!P1)
//		cout << "P1 is zero" << endl; 
//	if (P1 != P2)
//		cout << "P1 is Not Equal to P2" << endl;
//	polynomial P3 = P1 + P2;
//	cout << "P3 = " << P3 << endl;
//	P3 = 2+ P1; 
//	cout << "P3 = " << P3 << endl;
//	cout << ++P1 << endl;
//	cout << P1 << endl;
//	cout << P1++ << endl;
//	cout << P1 << endl;
//}