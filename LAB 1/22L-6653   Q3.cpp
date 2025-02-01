#include <iostream>
#include <ostream>
using namespace std;
void func(int **arr, int rsize, int csize) {
  int ri = rsize / 2;
  int ci = csize / 2;
  cout << "Elements of middle row are:" << endl;
  for (int i = 0; i < csize; i++) {
    cout << arr[ri][i] << endl;
  }
  cout << "Elements of middle column are:" << endl;
  for (int i = 0; i < rsize; i++) {
    cout << arr[i][ci] << endl;
  }
}

void print(int **arr, int rsize, int csize) {
  for (int i = 0; i < csize; i++) {
    for (int j = 0; j < rsize; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }
}

int main() {
  int col = 0, row = 0;

  do {
    cout << "Enter number of rows of array" << endl;
    cin >> row;
  } while (row % 2 == 0);
  do {
    cout << "Enter number of columns of array" << endl;
    cin >> col;
  } while (col % 2 == 0);

  int **arr = new int *[row];

  for (int i = 0; i < row; i++) {
    arr[i] = new int[col];
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << "Enter " << i + 1 << j + 1 << " Element of matrix:";
      cin >> arr[i][j];
    }
  }

  print(arr, row, col);
  func(arr, row, col);

  for (int i = 0; i < row; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}
