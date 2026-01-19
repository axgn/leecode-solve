#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> set;
    for (auto &i : nums) {
      set.emplace(i);
    }
    int max = 0;
    for (auto i : set) {
      if (!set.contains(i - 1)) {
        int value = 1;
        while (set.contains(++i)) {
          value++;
        }
        if (value > max) {
          max = value;
        }
      }
    }
    return max;
  }
};

int main() {
  Solution s;
  vector<int> v = {100, 4, 200, 1, 3, 2};
  ranges::copy(v, ostream_iterator<int>(cout, " "));
  cout << "\n";
  int result = s.longestConsecutive(v);
  cout << result << "\n";
  return 0;
}
