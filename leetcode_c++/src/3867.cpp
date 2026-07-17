#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  long long gcdSum(vector<int> &nums) {
    int max = INT_MIN;
    int n = nums.size();
    vector<int> prefixGcd(n);
    auto gcd = [](int a, int b) -> int {
      while (a % b) {
        int temp = a % b;
        a = b;
        b = temp;
      }
      return b;
    };
    for (int i = 0; i < n; i++) {
      max = nums[i] > max ? nums[i] : max;
      prefixGcd[i] = gcd(max, nums[i]);
    }
    sort(prefixGcd.begin(), prefixGcd.end());
    int n2 = prefixGcd.size();
    long long sum = 0;
    for (int i = 0; i < n2 / 2; i++) {
      sum += gcd(prefixGcd[i], prefixGcd[n2 - 1 - i]);
    }
    return sum;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
