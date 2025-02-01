//#include<iostream>
//#include<conio.h>
//using namespace std;
//class shape
//{
//public:
//	virtual float area() = 0;
//	string colour;
//	shape()
//	{
//		colour = "0";
//	}
//	shape(string c)
//	{
//		colour = c;
//	}
//	virtual ~shape() {
//		cout << "~shape() called." << endl;
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
//	~rectangle() { cout << "~rectangle() called." << endl; }
//
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
//	~triangle() { cout << "~ triangle () called." << endl; }
//
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
//	~circle() { cout << "~ circle () called." << endl; }
//};
//int sumArea(shape& Shape1, shape& Shape2)
//{
//	int sum = (Shape1.area() + Shape2.area());
//	return sum;
//}
//int main()
//{
//	shape S1("red");
//}