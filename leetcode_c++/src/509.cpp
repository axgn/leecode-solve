#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int fib(int n) {
    if (n == 0) {
      return 0;
    }
    int f0 = 0;
    int f1 = 1;
    for (int i = 1; i < n; i++) {
      int temp = f1 + f0;
      f0 = f1;
      f1 = temp;
    }
    return f1;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
