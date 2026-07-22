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
    int odd_sum = (sum - n) / 2;
    int even_sum = odd_sum + n;
    auto gcd = [&](int a, int b) {
      while (a % b) {
        int temp = a % b;
        a = b;
        b = temp;
      }
      return b;
    };
    return gcd(odd_sum, even_sum);
  }
};
int main() {
  Solution s;
  cout << s.gcdOfOddEvenSums(5) << "\n";
  return 0;
}
