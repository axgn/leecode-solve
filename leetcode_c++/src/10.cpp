#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {

public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector vis(n + 1, vector<int8_t>(m + 1));

    auto dfs = [&](this auto &&dfs, int i, int j) -> bool {
      if (j == m) {
        return i == n;
      }

      if (vis[i][j]) {
        return false;
      }
      vis[i][j] = true;

      bool is_match = i < n && (p[j] == '.' || p[j] == s[i]);

      if (j + 1 < m && p[j + 1] == '*') {
        return dfs(i, j + 2) || (is_match && dfs(i + 1, j));
      }

      return is_match && dfs(i + 1, j + 1);
    };

    return dfs(0, 0);
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
