#include <iostream>
using namespace std;
void fullsalary(int *s, int *b) { *s = *s + *b; }
int main() {
  int salary;
  int bonus;
  int *s = &salary;
  int *b = &bonus;
  cout << "Enter salary:  " << endl;
  cin >> salary;
  cout << "Enter bonus:  " << endl;
  cin >> bonus;
  fullsalary(s, b);
  cout << "Full salary is:" << endl << *s;
}
