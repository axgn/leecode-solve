#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> result;
    vector<int> next = newInterval;
    bool placed = false;
    for (int i = 0; i < (int)intervals.size(); i++) {
      vector<int> &it = intervals[i];
      if (it[1] < next[0]) {
        result.push_back(it);
        continue;
      }
      if (it[0] > next[1]) {
        if (!placed) {
          result.push_back(next);
          placed = true;
        }
        result.push_back(it);
        continue;
      }
      next[0] = min(next[0], it[0]);
      next[1] = max(next[1], it[1]);
    }
    if (!placed) {
      result.push_back(next);
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<int>> vv = {{1, 3}, {6, 9}};
  vector<int> newInterval = {2, 5};
  vv = s.insert(vv, newInterval);
  for (auto &v : vv) {
    ranges::copy(v, ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
  return 0;
}
