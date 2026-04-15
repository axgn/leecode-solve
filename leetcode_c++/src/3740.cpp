#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumDistance(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < n; i++) {
      map[nums[i]].push_back(i);
    }
    int res = INT32_MAX;
    for (auto &v : map) {
      vector<int> &value = v.second;
      int n = value.size();
      if (n >= 3) {
        for (int i = 0; i < n - 2; i++) {
          int temp = (value[i + 2] - value[i]);
          if (temp < res) {
            res = temp;
          }
        }
      }
    }
    if (res == INT_MAX) {
      return -1;
    }
    return res * 2;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
