#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> counts;
    vector<int> res{};
    for (auto &num : nums) {
      counts[num]++;
    }
    for (auto &count : counts) {
      if (count.second > n / 3) {
        res.push_back(count.first);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
