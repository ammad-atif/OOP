//#include<iostream>
//#include<conio.h>
//using namespace std;
//class shape
//{
//public:
//	virtual float area()
//	{
//		return 0.0;
//	}
//	string colour;
//	shape()
//	{
//		colour = "0";
//	}
//	shape(string c)
//	{
//		colour = c;
//	}
//};
//class rectangle :public shape
//{
//private:
//	float length;
//	float width;
//public:
//	float area()
//	{
//		float area = length * width;
//		return area;
//	}
//	rectangle()
//	{
//		length = 0;
//		width = 0;
//	}
//	rectangle(float l, float w, string c) :shape(c)
//	{
//		length = l;
//		width = w;
//	}
//};
//class triangle :public shape
//{
//private:
//	float base;
//	float height;
//public:
//	float area()
//	{
//		float area = 0.5 * (height * base);
//		return area;
//	}
//	triangle()
//	{
//		base = 0;
//		height = 0;
//	}
//	triangle(float b, float h, string c) :shape(c)
//	{
//		base = b;
//		height = h;
//	}
//};
//class circle :public shape
//{
//private:
//	float radius;
//public:
//	float area()
//	{
//		float area = 3.14 * radius * radius;
//		return area;
//	}
//	circle(float r, string c) :shape(c)
//	{
//		radius = r;
//	}
//	circle()
//	{
//		radius = 0;
//	}
//};
//int sumArea(shape& Shape1, shape& Shape2)
//{
//	int sum = (Shape1.area() + Shape2.area());
//	return sum;
//}
//int main()
//{
//	const int count = 5;
//	shape* shapesArray[count];
//	float base;
//	float height;
//	string color;
//	float length;
//	float width;
//	float radius;
//	for (int i = 0; i < count; )
//	{
//		cout << "Press 1 for a triangle, 2 for rectangle and 3 for a circle." << endl;
//		switch (_getch())
//		{
//		case '1':
//			
//			cout << "Enter base: "; cin >> base;
//			cout << "Enter height: "; cin >> height;
//			cout << "Enter colour: "; cin >> color;
//			shapesArray[i] = new triangle(base, height, color);
//			i++;
//			break;
//		case '2':
//			cout << "Enter length: "; cin >> length;
//			cout << "Enter width: "; cin >> width;
//			cout << "Enter colour: "; cin >> color;
//			shapesArray[i] = new rectangle(length, width, color);
//			i++;
//			break;
//
//
//		case '3':
//			cout << "Enter radius: "; cin >> radius;
//			cout << "Enter colour: "; cin >> color;
//			shapesArray[i] = new circle(radius,color);
//			i++;
//			break;
//
//
//		  default:
//			cout << "Invalid input. Enter again." << endl << endl;
//			break;
//		}
//
//	}
//	for (int i = 0; i < count; i++)
//	{
//		cout<<shapesArray[i]->area() << endl;
//	}
//	for (int i = 0; i < count; i++)
//	{
//		delete shapesArray[i];
//	}
//}