#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
  int maxActiveSectionsAfterTrade(string s) {
    vector<pair<int, int>> v;
    for (auto &value : s) {
      if (v.size() == 0) {
        v.push_back({value, 1});
        continue;
      }
      if (value == v.back().first) {
        v.back().second++;
      } else {
        v.push_back({value, 1});
      }
    }
    int max = INT_MIN;
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].first == '1') {
        res += v[i].second;
        if (i > 0 && i < v.size() - 1) {
          int temp = v[i - 1].second + v[i + 1].second;
          max = temp > max ? temp : max;
        }
      }
    }
    res += max > 0 ? max : 0;
    return res;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
