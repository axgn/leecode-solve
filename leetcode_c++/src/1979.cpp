#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
  int findGCD(vector<int> &nums) {
    int min = *min_element(nums.begin(), nums.end());
    int max = *max_element(nums.begin(), nums.end());
    return gcd(max, min);
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
