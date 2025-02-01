#include<iostream>
using namespace std;
void input(char*& sentence, int& size)
{
	cout << "Enter size: ";
	cin >> size;
	size++;
	sentence = new char[size];
	cout << "Enter sentence: ";
	cin.ignore();
	cin.getline(sentence, size);
}
void deallocation(char* sentence)
{
	delete[]sentence;
}
int words(char* sentence)
{
	int count = 0;
	int alphabets = 0;
	for (int i = 0; *(sentence + i) != '\0'; i++)
	{
		if (*(sentence + i) != ' ')
		{
			alphabets++;
		}
		if (*(sentence + i) == ' ')
		{
			if (alphabets > 2)
			{
				count++;
			}
			alphabets = 0;
		}
		if (*(sentence + (i + 1)) == '\0')
		{
			if (alphabets > 2)
			{
				count++;
			}
			alphabets = 0;
		}
	}
	return count;
}
char* arr(char* sentence, int size)
{
	char* array = new char[size];
	int alphabets = 0;
	int j = 0;
	int k = 0;
	for (int i = 0; *(sentence + i) != '\0'; i++)
	{
		if (*(sentence + i) != ' ')
		{
			alphabets++;
		}
		if (*(sentence + i) == ' ')
		{
			if (alphabets > 2)
			{
				while (j <= i)
				{
					*(array + k) = *(sentence + j);
					j++;
					k++;
				}
			}
			if (alphabets <= 2)
			{
				j = i + 1;
			}
			alphabets = 0;
		}
		if (*(sentence + (i + 1)) == '\0')
		{
			if (alphabets > 2)
			{
				while (j <= i)
				{
					*(array + k) = *(sentence + j);
					j++;
					k++;
				}
				*(array + k) = '\0';
			}
			alphabets = 0;
		}

	}
	return array;
}
int main()
{
	char* sentence = nullptr;
	int size;
	input(sentence, size);
	int word = words(sentence);
	cout << word << endl;
	char* a = arr(sentence, size);
	cout << a << endl;
	deallocation(sentence);
	deallocation(a);
}