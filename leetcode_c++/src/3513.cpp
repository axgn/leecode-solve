#include <bit>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
      size_t n = nums.size();
      return n <= 2? n : (1 << bit_width(n));
    }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
