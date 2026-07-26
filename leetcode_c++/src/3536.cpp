#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int maxProduct(int n) {
    int max = 0, max2 = 0;
    while (n > 0) {
      int temp = n % 10;
      n /= 10;
      if (temp >= max) {
        max2 = max;
        max = temp;
      } else if (temp >= max2) {
        max2 = temp;
      }
    }
    return max * max2;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
