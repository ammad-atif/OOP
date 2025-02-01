#include<iostream>
using namespace std;
class term
{
private:
	float cof;
	int exp;
	friend class polynomial;
	friend istream& operator>>(istream&,polynomial&);
	friend ostream& operator<<(ostream&,polynomial);
};
class polynomial
{
private:
	term*arr;
	int n;
	void shift(int i)
	{
		//this function takes arrays and the index where ther is repeating power coeffecient after operation on polynomial so it can replace the values on indexes after that index
		while (i < n - 1)
		{
			arr[i].cof = arr[i+1].cof;
			arr[i].exp = arr[i+1].exp;
			i++;
		}
		n = n - 1;
	}
	friend istream& operator>>(istream&, polynomial&);
	friend ostream& operator<<(ostream&, polynomial);
public:
	polynomial(int size)
	{
		n = size;
		arr = new term[n];
	}
	polynomial(const polynomial& a)
	{
		n = a.n;
		arr = new term[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = a.arr[i];
		}
	};
	polynomial()
	{
		n = 0;
		arr = nullptr;
	}
	~polynomial()
	{
		if (arr != nullptr)
		{
			delete[]arr;
		}
	}
	polynomial operator=(const polynomial& a)
	{
		n = a.n;
		if (arr != nullptr)
		{
			delete[] arr;
		}
		arr = new term[n];
		for (int i = 0; i < n; i++)
		{
			arr[i].cof = a. arr[i].cof;
			arr[i].exp= a.arr[i].exp;
		}
		return *this;
	}
	polynomial operator+(const polynomial& b)
	{
		polynomial c;
		c.n = n + b.n;
		c.arr = new term[c.n];
		int x = 0, y = 0, z = 0;
		//this loop is arranging the coeffecients of 1 and 2 polynomials in descending order
		while (x < n && y < b.n)
		{
			if (arr[x].exp > b.arr[y].exp)
			{
				c.arr[z].exp = arr[x].exp;
				c.arr[z].cof = arr[x].cof;
				z++;
				x++;
			}
			else
			{
				c.arr[z].exp = b.arr[y].exp;
				c.arr[z].cof = b.arr[y].cof;
				z++;
				y++;
			}
		}
		while (x < n)
		{
			c.arr[z].exp = arr[x].exp;
			c.arr[z].cof = arr[x].cof;
			z++;
			x++;
		}
		while (y < b.n)
		{
			c.arr[z].exp = b.arr[y].exp;
			c.arr[z].cof = b.arr[y].cof;
			z++;
			y++;
		}
		//this loop is adding the polynomials
		for (int i = 0; i < c.n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (c.arr[i].exp == c.arr[j].exp)
				{
					c.arr[j].cof = c.arr[i].cof + c.arr[j].cof;
					c.shift(i);
					i--;
				}
				if (c.arr[j].cof == 0)
				{
					c.arr[j].exp = 0;
				}
			}
		}
		for (int i = 0; i < c.n; i++)
		{
			if (c.arr[i].cof == 0 && i != 0)
			{
				c.shift(i);
				i--;
			}
		}
		term* f = new term[c.n];
		for (int i = 0; i < c.n; i++)
		{
			f[i].cof = c.arr[i].cof;
			f[i].exp = c.arr[i].exp;
		}
		delete[]c.arr;
		c.arr = f;
		return c;
	}
	polynomial operator*(const polynomial& b)
	{
		polynomial c;
		c.n = n * b.n;
		c.arr = new term[c.n];
		int k = 0;
		//this loop is multiplying the coefficients
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < b.n; j++)
			{
				if (arr[i].cof == 0 || b.arr[j].cof == 0)
				{
					c.arr[k].cof = 0;
					c.arr[k].exp = 0;
				}
				else
				{
					c.arr[k].cof = (arr[i].cof) * (b.arr[j].cof);
					c.arr[k].exp = arr[i].exp + b.arr[j].exp;
				}
				k++;
			}
		}
		for (int i = 0; i < c.n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (c.arr[i].exp == c.arr[j].exp)
				{
					c.arr[j].cof = c.arr[i].cof + c.arr[j].cof;
					c.shift(i);
					//after using shift function size is being minused
					i--;
				}
			}
		}
		//this loop arramge the array in descending order
		for (int i = 0; i < c.n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (c.arr[i].exp > c.arr[j].exp)
				{
					swap(c.arr[i].cof, c.arr[j].cof);
					swap(c.arr[i].exp, c.arr[j].exp);
				}
			}
		}
		for (int i = 0; i < c.n; i++)
		{
			if (c.arr[i].cof == 0 && i != 0)
			{
				c.shift(i);
				i--;
			}
		}
		//temporay pointers are being created of te exact size of polynomial after operation because the first pointers were of full sizes of 1st and 2nd pointers
		term* f = new term[c.n];
		for (int i = 0; i < c.n; i++)
		{
			f[i].cof = c.arr[i].cof;
			f[i].exp = c.arr[i].exp;
		}
		delete[]c.arr;
		c.arr = f;
		return c;
	}
	int operator()(int val)
	{
		int x = 1;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i].exp != 0)
			{
				for (int j = 0; j < arr[i].exp; j++)
				{
					x = x * val;
				}
				sum = sum + (arr[i].cof * x);
				x = 1;
			}
			else
			{
				sum = sum + arr[i].cof;
			}
		}
		return sum;
	}
};
istream& operator>>(istream& in, polynomial& a)
{
	if (a.n == 0)
	{
		cout << "Enter the number of coefficient terms for the polynomial: ";
		cin >> a.n;
		a.arr = new term[a.n];
	}
	for (int i = 0; i < a.n; i++)
	{
		cout << "Enter the constant : ";
		cin >> a.arr[i].cof;
		cout << "Now enter the power of variable : ";
		cin >> a.arr[i].exp;
		if (a.arr[i].exp < 0)
		{
			while (a.arr[i].exp < 0)
			{
				cout << "Enter correct power of variable : ";
				cin >> a.arr[i].exp;
			}
		}
		if (a.arr[i].cof == 0)
		{
			a.arr[i].exp = 0;
		}
		//this loop is checking if there is any coeffecient with same power entered before so it can add those coefficients
		for (int j = 0; j < i; j++)
		{
			if (a.arr[j].exp == a.arr[i].exp)
			{
				a.arr[j].cof = a.arr[j].cof + a.arr[i].cof;
				i--;
				a.n--;
			}
			if (a.arr[j].cof == 0)
			{
				a.arr[j].exp = 0;
			}
		}
		//this loop is checking if there is any lower power than this power entered so it can swap higher power coeffecient with lower one
		for (int j = 0; j < i; j++)
		{
			if (a.arr[i].exp > a.arr[j].exp)
			{
				swap(a.arr[i].cof, a.arr[j].cof);
				swap(a.arr[i].exp, a.arr[j].exp);
			}
		}
	}
	for (int i = 0; i < a.n; i++)
	{
		if (a.arr[i].cof == 0 && i != 0)
		{
			a.shift(i);
			i--;
		}
	}
	term* f = new term[a.n];
	for (int i = 0; i < a.n; i++)
	{
		f[i].cof = a.arr[i].cof;
		f[i].exp = a.arr[i].exp;
	}
	delete[]a.arr;
	a.arr = f;
	return in;
}
ostream& operator<<(ostream& out, polynomial a)
{
	int i;
	//this function is showing the reult on screen
	for (i = 0; i < a.n - 1; i++)
	{
		if (a.arr[i].exp != 0 && a.arr[i].exp != 1)
		{
			cout << a.arr[i].cof << "x" << "^" << a.arr[i].exp << " + ";
		}
		if (a.arr[i].exp == 1)
		{
			cout << a.arr[i].cof << "x" << " + ";
		}
		if (a.arr[i].exp == 0)
		{
			cout << a.arr[i].cof << " + ";
		}
	}
	if (a.arr[i].exp != 0 && a.arr[i].exp != 1)
	{
		cout << a.arr[i].cof << "x" << "^" << a.arr[i].exp << endl;
	}
	if (a.arr[i].exp == 1)
	{
		cout << a.arr[i].cof << "x" << endl;
	}
	if (a.arr[i].exp == 0)
	{
		cout << a.arr[i].cof << endl;
	}
	return out;
}
int main()
{
	polynomial a, b, c;
	cin >> a >> b;
	cout << a << b;
	c = a * b;
	cout << "Product is: ";
	cout << c;
	cin >> a >> b;
	cout << a << b;
	cout << "Sum is: ";
	c = a + b;
	cout << c;
	/*int val;
	cout << "Enter value of variable to calculate value of polynomial: ";
	cin >> val;
	cout << c(val);*/
}
