//#include <iostream>
//using namespace std;
//
//void func(int* a, int size)
//{
//	int mini = 0, maxi = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		if (*(a + i) < *(a + mini))
//		{
//			mini = i;
//		}
//	}
//	swap(*(a + 0), *(a + mini));
//	for (int i = 0; i < 5; i++)
//	{
//		if (*(a + i) > * (a + maxi))
//		{
//			maxi = i;
//		}
//	}
//	swap(*(a + 4), *(a + maxi));
//}
//int main()
//{
//	int arr[5];
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> arr[i];
//	}
//	func(arr, 5);
//	cout << "Smallest value is: " << *(arr + 0) << endl;
//	cout << "Largest value is: " << *(arr + 4) << endl;
//}