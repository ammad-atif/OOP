#include<iostream>
#include<conio.h>
using namespace std;
class animal
{
public:
	virtual string speak();
	
	virtual ~animal() { cout << "~Animal() called." << endl; }
};
 string animal::speak()
{
	string a = "speak() called.";
	return a;
}
class dog:public animal
{
public:
	string speak()
	{
		string a = "woof! ";
		return a;
	}
	~dog() { cout << "~Dog() called." << endl; }
};
class cat:public animal
{
public:
	string speak()
	{
		string a = "mew! ";
		return a;
	}
	~cat() { cout << "~Cat() called." << endl; }
};
class sheep:public animal
{
	public:
	string speak()
	{
		string a = "bleat! ";
		return a;
	}
	~sheep() { cout << "~sheep() called." << endl; }
};
class cow :public animal
{
public:
	string speak()
	{
		string a = "moo! ";
		return a;
	}
	~cow() { cout << "~cow() called." << endl; }
};
class horse :public animal
{
public:
	string speak()
	{
		string a = "neigh! ";
		return a;
	}
	~horse() { cout << "~horse() called." << endl; }
};
int main()
{
	int i = 0;
	const int size = 5;
	animal* myPets[size];
	while (i < size)
	{
		cout << "Press 1 for a Dog and 2 for a Cat." << endl;
		switch (_getch())
		{
		case '1':
			myPets[i] = new dog;
			cout << "Dog added at position " << i << endl << endl; i++;
			break;
		case '2':
			myPets[i] = new cat;
			cout << "Cat added at position " << i << endl << endl; i++;
			break;
		case'3':
			myPets[i] = new sheep;
			cout << "sheep added at position " << i << endl << endl; i++;
			break;
		case'4':
			myPets[i] = new cow;
			cout << "sheep added at position " << i << endl << endl; i++;
			break;
		case'5':
			myPets[i] = new horse;
			cout << "sheep added at position " << i << endl << endl; i++;
			break;
		default:
			cout << "Invalid input. Enter again." << endl << endl; 
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << myPets[i]->speak() << endl;
	}
	for (int i = 0; i < size; i++)
	{
		delete myPets[i];
	}
}