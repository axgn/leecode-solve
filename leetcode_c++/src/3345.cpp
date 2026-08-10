#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int smallestNumber(int n, int t) {
    if (n % 10 == 0) {
      return n;
    }
    int end = n / 10;
    end = (end + 1) * 10;
    auto check = [&](int i) -> bool {
      int mul = 1;
      while (i != 0) {
        mul *= i % 10;
        i /= 10;
      }
      if (mul % t == 0) {
        return true;
      }
      return false;
    };
    for (int i = n; i < end; i++) {
      if (check(i)) {
        return i;
      }
    }
    return end;
  }
};
int main() {
  Solution s;
  s.smallestNumber(15, 3);
  cout << "" << "\n";
  return 0;
}
