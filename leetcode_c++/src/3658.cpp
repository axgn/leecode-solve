#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int gcdOfOddEvenSums(int n) {
    int temp = 2 * n;
    int sum = temp * (temp + 1) / 2;
    int odd_sum = (sum - 4) / 2;
    int even_sum = odd_sum + 4;
    auto gcd = [&]() {
      while (even_sum / odd_sum) {
        int temp = even_sum % odd_sum;
      }
    };
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
