#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int uniqueXorTriplets(vector<int> &nums) {
    unordered_set<int> two;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        two.insert(nums[i] ^ nums[j]);
      }
    }

    unordered_set<int> result;
    for (auto& v : two) {
      for (int j = 0; j < n; j++) {
        result.insert(v ^ nums[j]);
      }
    }

    return result.size();
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
