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
//	int sum= (Shape1.area() + Shape2.area());
//	return sum;
//}
//int main()
//{
//	triangle t1(1.0, 9.0, "Red");
//	circle c1(2, "Blue");
//	rectangle r1(6, 2, "Orange");
//	shape s1("purple");
//	cout << sumArea(t1, c1)<<endl;
//	cout << sumArea(s1, r1)<<endl;
//	cout << sumArea(s1, t1)<<endl;
//}