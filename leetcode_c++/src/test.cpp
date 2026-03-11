#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << setprecision(16) << 8.0 - 1.1 << endl;
  cout << setprecision(16) << 2.0 - 1.1 << endl;
  int a = 10;
  int b = 5;
  int arr[2][5]{{2, 3, 3, 4, 5}, {2, 3, 3, 3, 3}};
  a = b, b = a;
  const int c = a;
  string s = "c";
  char d = 'c';

  cout << a << b << endl;
}
