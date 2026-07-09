#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  long long sumAndMultiply(int n) {
    long long x = 0;
    int p = 1;
    long long sum = 0;
    while (n != 0) {
      int temp = n % 10;
      n /= 10;
      if (temp == 0) {
        continue;
      }
      x += p * temp;
      p *= 10;
      sum += temp;
    }
    return x * sum;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
