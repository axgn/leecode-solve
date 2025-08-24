#include <bits/stdc++.h>
#include <cstddef>
#include <vector>

using namespace std;
class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    vector<int> min_v(triangle.back().size());
    min_v[0] = triangle[0][0];
    for (size_t i = 1; i < triangle.size(); i++) {
      min_v[i] = triangle[i][i] + min_v[i - 1];
      for (size_t j = i - 1; j > 0; j--) {
        min_v[j] = min(min_v[j], min_v[j - 1]) + triangle[i][j];
      }
      min_v[0] = triangle[i][0] + min_v[0];
    }
    int result = min_v[0];
    for (size_t i = 1; i < min_v.size(); i++) {
      if (min_v[i] < result) {
        result = min_v[i];
      }
    }
    return result;
  }
};
int main() {
  Solution s;
  vector<vector<int>> vv = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  cout << s.minimumTotal(vv) << endl;
  return 0;
}
