#include<iostream>
using namespace std;
template<class t>
class container
{
private:
	t data;
public:
	container() {};
	container(t a);
	t increase();
};
template<class t>
t container<t>::increase()
{
	return ++data;
}
template<class t>
container<t>::container(t a)
{
	data = a;
}

template<>
class container<char>
{
private:
	char data;
public:
	container() {};
	container(char a);
	char uppercase();
};\
template<>
container<char>::container(char a)
{
	data = a;
}
template<>
char container<char>::uppercase()
{
	if (!(data>'A'&&data<'Z'))
	{
		int a = data;
		data = a - 32;
	}
	return data;
}
int main()
{
	container<int> myint(7);
	container <char> mychar('j');
	cout << myint.increase() << endl;
	cout << mychar.uppercase() << endl;

}