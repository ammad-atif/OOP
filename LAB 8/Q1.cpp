#include<iostream>
using namespace std;
#include<string.h>
class passenger
{
	string name;
	char gender;
public:
	void setname(string n)
	{
		name = n;
	}
	string getname()
	{
		return name;
	}
	void setgender(char g)
	{
		gender = g;
	}
	char getgender()
	{
		return gender;
	}
	void displaypasenger()
	{
		cout << "Name: " << name << endl;
	}
};
class engine
{
	string type;
	int hp;
public:
	engine()
	{
		type = "0";
		hp = 0;
	}
	engine(string t,int h)
	{
		type = t;
		hp = h;
	}
	string gettype()
	{
		return type;
	}
	int gethp()
	{
		  return hp;
	}
	void displayengine()
	{
		cout << "Engine Type: " << type << endl;
		cout << "Engine HP: " << hp << endl;
	}
};
class bus
{
	string busno;
	int seatingcapacity;
	int seatreservedsofar;
	int numpassengers;
	passenger* pas;
	engine eng;
public:
	bus()
	{
		busno = "0";
		seatingcapacity = 0;
		seatreservedsofar = 0;
		numpassengers = 0;
		pas = nullptr;
	}
	~bus()
	{
		delete[]pas;
	}
	bus(string a,int b,int c,int d,string e, int f,passenger* g):eng(e,f)
	{
		busno = a;
		seatingcapacity = b;
		seatreservedsofar = c;
		numpassengers = d;
		pas = new passenger[b];
	}
	int getseatingcapacity()
	{
		return seatingcapacity;
	}
	void setseatingcapacity(int a)
	{
		seatingcapacity = a;
	}
	string getbusno()
	{
		return busno;
	}
	void setbusno(string a)
	{
		busno = a;
	}
	void reserveseat(passenger p)
	{
		pas[seatreservedsofar] = p;
		seatreservedsofar++;
		numpassengers++;
	}
	int getnumpassengers()
	{
		return numpassengers;
	}
	void display()
	{
		cout <<"Buss no: "<< busno << endl;
		cout << "Seating capacity: "<<seatingcapacity << endl;
		cout << "Seats Reserved so far: "<<seatreservedsofar << endl;
		cout << "Passengers: " << endl;
		for (int i = 0; i < seatreservedsofar; i++)
		{
			pas[i].displaypasenger();
		}
		eng.displayengine();
	}
};
int main()
{ 
	string bn;
	int sc;
	string t;
	int h;
	string pname;
	char gender;
	cout << "Enter busno: ";
	cin >> bn;
	cout << "Enter seating capacity: ";
	cin >> sc;
	cout << "Enter engine type: ";
	cin >> t;
	cout << "Enter hp: ";
	cin >> h;
	bus x(bn,sc,0,0,t,h,nullptr );
	cout << "********BUS CREATED SUCCEESSFULLY********"<<endl;
	cout << "********Add passengers*********"<<endl;
	passenger p;
	char ch = 'y';
	for (int i = 0; i < sc&&(ch=='y'||ch=='Y'); i++)
	{
		cout << "Enter passenger name: ";
		cin >> pname;
		cout << "Enter passenger gender: ";
		cin >> gender;
		p.setname(pname);
		p.setgender(gender);
		x.reserveseat(p);
		cout << "******Seat reserved for " << pname << "*******" << endl;
		if (i<sc-1)
		{
			cout << "Ad another passenger (y/n): ";
			cin >> ch;
		}
	}
	cout << "All seats are reserved" << endl;
	x.display();
}