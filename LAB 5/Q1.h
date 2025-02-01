#pragma once
#include<iostream>
using namespace std;
class matrix
{
private:
	int rows;
	int columns;
	int** data;
public:
	matrix()
	{
		rows = 0;
		columns = 0;
		data = nullptr;
	}
	matrix(int r, int c)
	{
		rows = r;
		columns = c;
		data = new int* [r];
		for (int i = 0; i < r; i++)
		{
			data[i] = new int[c];
		}
	}
	matrix(const matrix& a)
	{
		rows = a.rows;
		columns = a.columns;
		data = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new int[columns];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				 data[i][j]=a.data[i][j];
			}
		}
	}
	~matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[]data[i];
		}
		delete[]data;
	}
	void input()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << "Enter " << i + 1 << j + 1 << " element of matrix: ";
				cin >> data[i][j];
			}
		}
	}
	void print()
	{

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << data[i][j] << "  ";
			}
			cout << endl;
		}
	}
	matrix tarnsporse()
	{
		matrix a;
		a.rows = columns;
		a.columns = rows;
		a.data = new int* [columns];
		for (int i = 0; i < columns; i++)
		{
			a.data[i] = new int[rows];
		}
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				a.data[i][j] = data[j][i];
			}
		}
		return a;
	}
};
