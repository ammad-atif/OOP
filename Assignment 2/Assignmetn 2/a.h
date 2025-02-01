#pragma once
#include<iostream>
using namespace std;
class polynomial
{
private:
	float* cof;
	int* exp;
	int n;
	void shift(int i)
	{
		//this function takes arrays and the index where ther is repeating power coeffecient after operation on polynomial so it can replace the values on indexes after that index
		while (i < n - 1)
		{
			cof[i] = cof[i + 1];
			exp[i] = exp[i + 1];
			i++;
		}
		n = n - 1;
	}
public:
	polynomial(int size)
	{
		n = size;
		cof = new float[n];
		exp = new int[n];
	}
	polynomial(const polynomial& a)
	{
		n = a.n;
		cof = new float[n];
		exp = new int[n];
		for (int i = 0; i < n; i++)
		{
			cof[i] = a.cof[i];
			exp[i] = a.exp[i];
		}
	};
	polynomial()
	{
		n = 0;
		cof = nullptr;
		exp = nullptr;
	}
	~polynomial()
	{
		if (cof != nullptr)
		{
			delete[]cof;
		}
		if (exp != nullptr)
		{
			delete[]exp;
		}
	}
	void input()
	{
		if (n == 0)
		{
			cout << "Enter the number of coefficient terms for the polynomial: ";
			cin >> n;
			cof = new float[n];
			exp = new int[n];
		}
		for (int i = 0; i < n; i++)
		{
			cout << "Enter the constant : ";
			cin >> cof[i];
			cout << "Now enter the power of variable : ";
			cin >> exp[i];
			if (exp[i] < 0)
			{
				while (exp[i] < 0)
				{
					cout << "Enter correct power of variable : ";
					cin >> exp[i];
				}
			}
			if (cof[i] == 0)
			{
				exp[i] = 0;
			}
			//this loop is checking if there is any coeffecient with same power entered before so it can add those coefficients
			for (int j = 0; j < i; j++)
			{
				if (exp[j] == exp[i])
				{
					cof[j] = cof[j] + cof[i];
					i--;
					n--;
				}
				if (cof[j] == 0)
				{
					exp[j] = 0;
				}
			}
			//this loop is checking if there is any lower power than this power entered so it can swap higher power coeffecient with lower one
			for (int j = 0; j < i; j++)
			{
				if (exp[i] > exp[j])
				{
					swap(cof[i], cof[j]);
					swap(exp[i], exp[j]);
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (cof[i] == 0 && i != 0)
			{
				this->shift(i);
				i--;
			}
		}
		float* coftemp = new float[n];
		int* exptemp = new int[n];
		for (int i = 0; i < n; i++)
		{
			coftemp[i] = cof[i];
		}
		for (int i = 0; i < n; i++)
		{
			exptemp[i] = exp[i];
		}
		delete[]cof;
		delete[]exp;
		cof = coftemp;
		exp = exptemp;
	}
	void output()
	{
		int i;
		//this function is showing the reult on screen
		for (i = 0; i < n - 1; i++)
		{
			if (exp[i] != 0 && exp[i] != 1)
			{
				cout << cof[i] << "x" << "^" << exp[i] << " + ";
			}
			if (exp[i] == 1)
			{
				cout << cof[i] << "x" << " + ";
			}
			if (exp[i] == 0)
			{
				cout << cof[i] << " + ";
			}
		}
		if (exp[i] != 0 && exp[i] != 1)
		{
			cout << cof[i] << "x" << "^" << exp[i] << endl;
		}
		if (exp[i] == 1)
		{
			cout << cof[i] << "x" << endl;
		}
		if (exp[i] == 0)
		{
			cout << cof[i] << endl;
		}
	}
	polynomial operator=(const polynomial& a)
	{
		n = a.n;
		if (cof != nullptr || exp != nullptr)
		{
			delete[] cof;
			delete[] exp;
		}
		cof = new float[n];
		exp = new int[n];
		for (int i = 0; i < n; i++)
		{
			cof[i] = a.cof[i];
			exp[i] = a.exp[i];
		}
		return *this;
	}
	polynomial plus(const polynomial& b)
	{
		polynomial c;
		c.n = n + b.n;
		c.cof = new float[c.n];
		c.exp = new int[c.n];
		int x = 0, y = 0, z = 0;
		//this loop is arranging the coeffecients of 1 and 2 polynomials in descending order
		while (x < n && y < b.n)
		{
			if (exp[x] > b.exp[y])
			{
				c.exp[z] = exp[x];
				c.cof[z] = cof[x];
				z++;
				x++;
			}
			else
			{
				c.exp[z] = b.exp[y];
				c.cof[z] = b.cof[y];
				z++;
				y++;
			}
		}
		while (x < n)
		{
			c.exp[z] = exp[x];
			c.cof[z] = cof[x];
			z++;
			x++;
		}
		while (y < b.n)
		{
			c.exp[z] = b.exp[y];
			c.cof[z] = b.cof[y];
			z++;
			y++;
		}
		//this loop is adding the polynomials
		for (int i = 0; i < c.n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (c.exp[i] == c.exp[j])
				{
					c.cof[j] = c.cof[i] + c.cof[j];
					c.shift(i);
					i--;
				}
				if (c.cof[j] == 0)
				{
					c.exp[j] = 0;
				}
			}
		}
		for (int i = 0; i < c.n; i++)
		{
			if (c.cof[i] == 0 && i != 0)
			{
				c.shift(i);
				i--;
			}
		}
		float* temptr1 = new float[c.n];
		int* temptr2 = new int[c.n];
		for (int i = 0; i < c.n; i++)
		{
			temptr1[i] = c.cof[i];
		}
		for (int i = 0; i < c.n; i++)
		{
			temptr2[i] = c.exp[i];
		}
		delete[]c.cof;
		delete[]c.exp;
		c.cof = temptr1;
		c.exp = temptr2;
		return c;
	}
	polynomial multiply(const polynomial& b)
	{
		polynomial c;
		c.n = n * b.n;
		c.cof = new float[c.n];
		c.exp = new int[c.n];
		int k = 0;
		//this loop is multiplying the coefficients
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < b.n; j++)
			{
				if (cof[i] == 0 || b.cof[j] == 0)
				{
					c.cof[k] = 0;
					c.exp[k] = 0;
				}
				else
				{
					c.cof[k] = (cof[i]) * (b.cof[j]);
					c.exp[k] = exp[i] + b.exp[j];
				}
				k++;
			}
		}
		for (int i = 0; i < c.n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (c.exp[i] == c.exp[j])
				{
					c.cof[j] = c.cof[i] + c.cof[j];
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
				if (c.exp[i] > c.exp[j])
				{
					swap(c.cof[i], c.cof[j]);
					swap(c.exp[i], c.exp[j]);
				}
			}
		}
		for (int i = 0; i < c.n; i++)
		{
			if (c.cof[i] == 0 && i != 0)
			{
				c.shift(i);
				i--;
			}
		}
		//temporay pointers are being created of te exact size of polynomial after operation because the first pointers were of full sizes of 1st and 2nd pointers
		float* temptr1 = new float[c.n];
		int* temptr2 = new int[c.n];
		for (int i = 0; i < c.n; i++)
		{
			temptr1[i] = c.cof[i];
		}
		for (int i = 0; i < c.n; i++)
		{
			temptr2[i] = c.exp[i];
		}
		delete[]c.cof;
		delete[]c.exp;
		c.cof = temptr1;
		c.exp = temptr2;
		return c;
	}
};
