#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int reverseNum(int number) {
    int res = 0;
    while (number > 0) {
      int temp = number % 10;
      number /= 10;
      res = res * 10 + temp;
    }
    return res;
  }
  inline int abs(int a, int b) { return a > b ? a - b : b - a; }
  int mirrorDistance(int n) { return abs(n, reverseNum(n)); }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
