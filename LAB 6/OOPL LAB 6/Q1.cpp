//#include<iostream>
//using namespace std;
//class matrix
//{
//private:
//	int rows;
//	int columns;
//	int** data;
//	friend matrix operator+(matrix , matrix );
//	friend matrix operator+(int , matrix );
//	friend matrix operator+(matrix b, int a);
//public:
//	matrix()
//	{
//		rows = 0;
//		columns = 0;
//		data = nullptr;
//	}
//	matrix(int r, int c)
//	{
//		rows = r;
//		columns = c;
//		data = new int* [r];
//		for (int i = 0; i < r; i++)
//		{
//			data[i] = new int[c];
//		}
//	}
//	matrix(const matrix& a)
//	{
//		rows = a.rows;
//		columns = a.columns;
//		data = new int* [rows];
//		for (int i = 0; i < rows; i++)
//		{
//			data[i] = new int[columns];
//		}
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < columns; j++)
//			{
//				data[i][j] = a.data[i][j];
//			}
//		}
//	}
//	~matrix()
//	{
//		for (int i = 0; i < rows; i++)
//		{
//			delete[]data[i];
//		}
//		delete[]data;
//	}
//	void input()
//	{
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < columns; j++)
//			{
//				cout << "Enter " << i + 1 << j + 1 << " element of matrix: ";
//				cin >> data[i][j];
//			}
//		}
//	}
//	void print()
//	{
//
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < columns; j++)
//			{
//				cout << data[i][j] << "  ";
//			}
//			cout << endl;
//		}
//	}
//	matrix tarnsporse()
//	{
//		matrix a;
//		a.rows = columns;
//		a.columns = rows;
//		a.data = new int* [columns];
//		for (int i = 0; i < columns; i++)
//		{
//			a.data[i] = new int[rows];
//		}
//		for (int i = 0; i < columns; i++)
//		{
//			for (int j = 0; j < rows; j++)
//			{
//				a.data[i][j] = data[j][i];
//			}
//		}
//		return a;
//	}
//	 matrix operator=(matrix a)
//	 {
//		 if (this != &a)
//		 {
//			 if (data != nullptr)
//			 {
//				 for (int i = 0; i < rows; i++)
//				 {
//					 delete[]data[i];
//				 }
//				 delete[]data;
//			 }
//			 rows = a.rows;
//			 columns = a.columns;
//			 data = new int* [rows];
//			 for (int i = 0; i < rows; i++)
//			 {
//				 data[i] = new int[columns];
//			 }
//			 for (int i = 0; i < rows; i++)
//			 {
//				 for (int j = 0; j < columns; j++)
//				 {
//					 data[i][j] = a.data[i][j];
//				 }
//			 }
//		 }
//		 return *this;
//	 }
//};
//matrix operator+(matrix a, matrix b)
//{
//	if (a.rows != b.rows || a.columns != b.columns)
//	{
//		cout << "Cannot be added" << endl;
//	}
//	else
//	{
//		matrix c(a.rows, a.columns);
//		c.rows = a.rows;
//		c.columns = a.columns;
//		for (int i = 0; i < c.rows; i++)
//		{
//			for (int j = 0; j < c.columns; j++)
//			{
//				c.data[i][j] = a.data[i][j] + b.data[i][j];
//			}
//		}
//		return c;
//	}
//}
//matrix operator+(int a, matrix b)
//{
//	matrix c(b.rows, b.columns);
//	c.rows = b.rows;
//	c.columns = b.columns;
//	for (int i = 0; i < c.rows; i++)
//	{
//		for (int j = 0; j < c.columns; j++)
//		{
//			c.data[i][j] = b.data[i][j] + a;
//		}
//	}
//	return c;
//}
//matrix operator+(matrix b, int a)
//{
//	matrix c(b.rows, b.columns);
//	c.rows = b.rows;
//	c.columns = b.columns;
//	for (int i = 0; i < c.rows; i++)
//	{
//		for (int j = 0; j < c.columns; j++)
//		{
//			c.data[i][j] = b.data[i][j] + a;
//		}
//	}
//	return c;
//}
//int main()
//{
//	int rows,columns;
//	cout << "Enter number of rows: ";
//	cin >> rows;
//	cout << "Enter number number of columns: ";
//	cin >> columns;
//	matrix a(rows,columns);
//	a.input();
//	a.print();
//	cout << endl;
//	//here copy constructor is being used because copy constructor is being called when we initialize while declaration
//	matrix b=a.tarnsporse();
//    b.print();
//	cout << endl;
//	matrix c;
//	c = a + b;
//	c.print();
//	cout << endl;
//	matrix d = 5+c;
//	d.print();
//	cout << endl;
//}
