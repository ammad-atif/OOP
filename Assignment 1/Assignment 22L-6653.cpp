//#include<iostream>
//using namespace std;
//void hell(float* cof, int* exp, int n, int i)
//{
//	//this function takes arrays and the index where ther is repeating power coeffecient after operation on polynomial so it can replace the values on indexes after that index
//	while (i < n - 1)
//	{
//		cof[i] = cof[i + 1];
//		exp[i] = exp[i + 1];
//		i++;
//	}
//}
//void input(float *&cof, int*& exp, int& n)
//{
//	cout << "Enter the number of coefficient terms for the polynomial: ";
//	cin >> n;
//	 cof = new float[n];
//	 exp = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Enter the constant for " << i + 1 << " coeffecient term:  ";
//		cin >> cof[i];
//		cout << "Now enter the power of variable for " << i + 1 <<" coeffecient term:  ";
//		cin >> exp[i];
//		if (cof[i] == 0)
//		{
//			exp[i] = 0;
//		}
//		//this loop is checking if there is any coeffecient with same power entered before so it can add those coefficients
//		for (int j = 0; j <i ; j++)
//		{
//			if (exp[j]==exp[i])
//			{
//				cof[j] = cof[j] + cof[i];
//				i--;
//				n--;
//			}
//			if (cof[j]==0)
//			{
//				exp[j] = 0;
//			}
//		}
//		//this loop is checking if there is any lower power than this power entered so it can swap higher power coeffecient with lower one
//		for (int j = 0; j < i; j++)
//		{
//			if (exp[i] > exp[j])
//			{
//				swap(cof[i], cof[j]);
//				swap(exp[i], exp[j]);
//			}
//		}
//	}
//	for (int i = 0; i <n ; i++)
//	{
//		if (cof[i]==0&&i!=0)
//		{
//			hell(cof, exp, n, i);
//			i--;
//			n--;
//		}
//	}
//	float* coftemp = new float[n];
//	int* exptemp = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		coftemp[i] = cof[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		exptemp[i] = exp[i];
//	}
//	delete[]cof;
//	delete[]exp;
//	cof = coftemp;
//	exp = exptemp;
//}
//void output(float* cof, int* exp, int n)
//{
//	int i;
//	//this function is showing the reult on screen
//	for ( i = 0; i < n-1; i++)
//	{
//		if (exp[i] != 0&& exp[i] != 1)
//		{
//			cout << cof[i] << "x" << "^" << exp[i]<<" + ";
//		}
//		if (exp[i] ==1)
//		{
//			cout << cof[i] << "x"  << " + ";
//		}
//		if (exp[i]==0)
//		{
//			cout << cof[i] << " + ";
//		}
//	}
//	if (exp[i] != 0 && exp[i] != 1)
//	{
//		cout << cof[i] << "x" << "^" << exp[i] << endl;
//	}
//	if (exp[i] == 1)
//	{
//		cout << cof[i] << "x"<<endl ;
//	}
//	 if (exp[i] == 0)
//	{
//		cout << cof[i] <<endl;
//	}
//}
//void deallocation(float* cof, int* exp)
//{
//	//this function deallocates the dynamic memory at end of program execution
//	delete[]cof;
//	delete[]exp;
//}
//void multiply(float* cof1, int* exp1, int n1, float* cof2, int* exp2, int n2, float *&cof3, int *&exp3, int &n3)
//{
//	n3 = n1 * n2;
//	cof3 = new float[n3];
//	exp3 = new int[n3];
//	int k = 0;
//	//this loop is multiplying the coefficients
//	for (int i = 0; i < n1; i++)
//	{
//		for (int j = 0; j < n2; j++)
//		{
//			if (cof1[i]==0||cof2[j]==0)
//			{
//				cof3[k] = 0;
//				exp3[k] = 0;
//			}
//			else
//			{
//				cof3[k] = (cof1[i]) * (cof2[j]);
//				exp3[k] = exp1[i] + exp2[j];
//			}
//			k++;
//		}
//	}
//	for (int i = 0; i < n3; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (exp3[i]==exp3[j])
//			{
//				cof3[j] = cof3[i] + cof3[j];
//				hell(cof3, exp3, n3, i);
//				//after using hell function size is being minused
//				i--;
//				n3--;
//			}
//		}
//	}
//	//this loop arramge the array in descending order
//	for (int i = 0; i < n3; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (exp3[i] >exp3[j])
//			{
//				swap(cof3[i], cof3[j]);
//				swap(exp3[i], exp3[j]);
//			}
//		}
//	}
//	for (int i = 0; i <n3; i++)
//	{
//		if (cof3[i] == 0&&i!=0)
//		{
//			hell(cof3, exp3, n3, i);
//			i--;
//			n3--;
//		}
//	}
//	//temporay pointers are being created of te exact size of polynomial after operation because the first pointers were of full sizes of 1st and 2nd pointers
//	float* temptr1 = new float[n3];
//	int* temptr2 = new int[n3];
//			for (int i = 0; i < n3; i++)
//			{
//				temptr1[i] = cof3[i];
//			}
//			for (int i = 0; i < n3; i++)
//			{
//				temptr2[i] = exp3[i];
//			}
//			delete[]cof3;
//			delete[]exp3;
//			cof3 = temptr1;
//			exp3 = temptr2;
//}
//void add(float* cof1, int* exp1, int n1, float* cof2, int* exp2, int n2, float*& cof3, int*& exp3, int& n3)
//{
//	n3 = n1 + n2;
//	cof3 = new float[n3];
//	exp3 = new int[n3];
//	int x = 0, y = 0, z = 0;
//	//this loop is arranging the coeffecients of 1 and 2 polynomials in descending order
//	while (x<n1&&y<n2)
//	{
//		if (exp1[x]>exp2[y])
//		{
//			exp3[z] = exp1[x];
//			cof3[z] = cof1[x];
//			z++;
//			x++;
//		}
//		else
//		{
//			exp3[z] = exp2[y];
//			cof3[z] = cof2[y];
//			z++;
//			y++;
//		}
//	}
//	while (x<n1)
//	{
//		exp3[z] = exp1[x];
//		cof3[z] = cof1[x];
//		z++;
//		x++;
//	}
//	while (y<n2)
//	{
//		exp3[z] = exp2[y];
//		cof3[z] = cof2[y];
//		z++;
//		y++;
//	}
//	//this loop is adding the polynomials
//	for (int i = 0; i < n3; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (exp3[i] == exp3[j])
//			{
//				cof3[j] = cof3[i] + cof3[j];
//				hell(cof3, exp3, n3, i);
//				i--;
//				n3--;
//			}
//			if (cof3[j] == 0)
//			{
//				exp3[j] = 0;
//			}
//		}
//	}
//	for (int i = 0; i <n3; i++)
//	{
//		if (cof3[i] == 0&&i!=0)
//		{
//			hell(cof3, exp3, n3, i);
//			i--;
//			n3--;
//		}
//	}
//	float* temptr1 = new float[n3];
//	int* temptr2 = new int[n3];
//	for (int i = 0; i < n3; i++)
//	{
//		temptr1[i] = cof3[i];
//	}
//	for (int i = 0; i < n3; i++)
//	{
//		temptr2[i] = exp3[i];
//	}
//	delete[]cof3;
//	delete[]exp3;
//	cof3 = temptr1;
//	exp3 = temptr2;
//}
//int main()
//{ 
//	cout << "NOTE: to enter a constant without any variable enter the power of variable \"" << 0 << "\" for that coefficient term."<<endl;
//	//float datatype for real numbers and int datatype for whole numbers
//	char a;
//	float* cof1=0;
//	int* exp1=0;
//	int n1 = 0;
//	float* cof2 = 0;
//	int* exp2 = 0;
//	int n2 = 0;
//	float* cof3 = 0;
//	int* exp3 = 0;
//	int n3 = 0;
//	input(cof1, exp1,n1);
//	output(cof1, exp1,n1);
//	input(cof2, exp2, n2);
//	output(cof2, exp2, n2);
//	cout << "Enter + to add polynomials: " << endl;
//	cout << "Enter * to multiply polynomials: "<<endl;
//	cin >> a;
//	if (a=='+')
//	{
//		add(cof1, exp1, n1, cof2, exp2, n2, cof3, exp3, n3);
//	}
//	if (a=='*')
//	{
//		multiply(cof1, exp1, n1, cof2, exp2, n2, cof3, exp3, n3);
//	}
//	output(cof3, exp3, n3);
//	deallocation(cof3, exp3);
//	deallocation(cof1, exp1);
//	deallocation(cof2, exp2);
//
//
//}