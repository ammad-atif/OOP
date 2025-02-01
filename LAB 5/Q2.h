#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class holiday
{
private:
	string name;
	int day;
	string month;
public: 
	holiday()
	{
		name = "0";
		day = 0;
		month = "0";
	}
	holiday( string &n, int &d, string&m)
	{
		name = n;
		day = d;
		month = m;
	}
	bool setName(  string& s)
	{
		if (s.length()>50)
		{
			return 0;
		}
		else
		{
			name = s;
			return 1;
		}
	}
	string getName()
	{
		return name;
	}
	bool setDay(int u)
	{
		if (u<0)
		{
			return 0;
		}
		else
		{
			day = u;
			return 1;
		}
	}
	int getDay()
	{
		return day;
	}
	bool setMonth( string& p)
	{
		if (p.length() > 10)
		{
			return 0;
		}
		else
		{
			month=p;
			return 1;
		}
	}
	string getMonth()
	{
		return month;
	}
};
