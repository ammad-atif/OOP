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
//int main()
//{
//	triangle t1(1.0, 9.0, "Red");
//	circle c1(2, "Blue");
//	rectangle r1(6, 2, "Orange");
//	cout << t1.area()<<endl;
//	cout << t1.colour << endl;
//	cout << c1.area() << endl;
//	cout << r1.area() << endl;
//	shape* sptr = &t1;
//	shape& sref = r1;
//	cout << sptr->area() << endl;
//	cout << sptr->colour << endl;
//	cout << sref.colour << endl;
//	cout << sref.area() << endl;
//}