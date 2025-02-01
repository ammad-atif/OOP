#pragma once
#include<iostream>
using namespace std;
class rectangle
{
private:
	float width;
	float height;
public:
	void setwidth(float w)
	{
		width = w;
	}
	void setheight(float h)
	{
		height = h;
	}
	void printdimensions()
	{
		cout << "WIDTH: " << width<<endl;
		cout << "HEIGHT: " << height<<endl;
	}
	void printarea()
	{
		cout << "AREA: "<<height * width;
	}
	float getarea()
	{
		float area = height * width;
		return area;
	}
};
