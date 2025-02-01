//#include<iostream>
//#include"Q3.h"
//using namespace std;
//int main()
//{
//	float mag;
//	int size;
//	ComplexNumber c1;
//	c1.Input();
//	c1.Output();
//	ComplexNumber *cptr=&c1;
//	//no it doesnot call constructor
//	cptr->Output();
//	ComplexNumber arr1[5];
//	//no we don't need to delete this array as it is not dynamcially allocated array
//	for (int i = 0; i < 5; i++)
//	{
//		arr1[i].Input();
//		arr1[i].Output();
//		mag = arr1[i].Magnitude();
//		cout << mag << endl;
//	}
//	cout << "Enter size for array: ";
//	cin >> size;
//	ComplexNumber* arr2 = new ComplexNumber[size];
//	//yes we have to delete in this case
//	for ( int i = 0; i < size; i++)
//	{
//		arr2[i].Input();
//		arr2[i].Output();
//		mag = arr2[i].Magnitude();
//		cout << mag << endl;
//	}
//	delete[]arr2;
//}