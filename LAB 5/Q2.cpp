//#include<iostream>
//#include<string.h>
//#include"Q2.h"
//using namespace std;
//bool isSameMonth( holiday& a,  holiday& b)
//{
//	//use of getter
//	string c = a.getMonth();
//	string d = b.getMonth();
//	if (c == d )
//	{
//		return 1;
//	}
//	return 0;
//}
//double avgDate(holiday arr[], int size)
//{ 
//	double avg = 0;
//	int count = 0;
//	int d;
//	for (int i = 0; i < size; i++)
//	{
//		d = arr[i].getDay();
//		avg = avg + d;
//		count++;
//	}
//	avg = avg / count;
//	return avg;
//}
//int main()
//{
//	string name;
//	string month;
//	int day;
//	double avg;
//	cout << "Enter name: ";
//	cin >> name;
//	cout << "Enter month: ";
//	cin >> month;
//	cout << "Enter day: ";
//	cin >> day;
//	holiday a(name,day,month);
//	cout << "Enter name: ";
//	cin >> name;
//	cout << "Enter month: ";
//	cin >> month;
//	cout << "Enter day: ";
//	cin >> day;
//	holiday b(name,day,month); 
//	if (isSameMonth(a,b))
//	{
//		cout << "Both have same months" << endl;
//	}
//	else
//	{
//		cout << "Both have different months" << endl;
//	}
//	holiday arr[5];
//	//use of setter
//	for (int i = 0; i < 5; i++)
//	{
//		cout << "Enter day: ";
//		cin >> day;
//		if (arr[i].setDay(day) == 0)
//		{
//			while (arr[i].setDay(day) == 0)
//			{
//				cout << "Enter day again: ";
//				cin >> day;
//			}
//		}
//	}
//	avg = avgDate(arr,5);
//	cout << avg;
//}