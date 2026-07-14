#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
  vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
                                    vector<vector<int>> &queries) {
    vector<int> set_no(n);
    int temp = nums[0];
    int no = 1;
    set_no[0] = no;
    for (int i = 0; i < n; i++) {
      if (nums[i] <= temp + maxDiff) {
        temp = nums[i];
        set_no[i] = no;
      } else {
        temp = nums[i];
        no++;
        set_no[i] = no;
      }
    }
    vector<bool> res;
    res.reserve(queries.size());
    for (auto &query : queries) {
      int start = query.front();
      int end = query.back();
      if (set_no[start] == set_no[end]) {
        res.push_back(true);
      } else {
        res.push_back(false);
      }
    }
    return res;
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 3};
  vector<vector<int>> queries = {{0, 0}, {0, 1}};
  s.pathExistenceQueries(2, nums, 1, queries);
  cout << "" << "\n";
  return 0;
}
