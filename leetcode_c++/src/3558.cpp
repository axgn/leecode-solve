#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int assignEdgeWeights(vector<vector<int>> &edges) {
    int n = edges.size() + 1;
    int MOD = 1000'000'000 + 7;
    vector<vector<int>> g(n + 1);
    for (auto &item : edges) {
      g[item.front()].push_back(item.back());
      g[item.back()].push_back(item.front());
    }
    auto dfs = [&](this auto &&dfs, int u, int father) -> int {
      int depth = 1;
      for (auto &v : g[u]) {
        if (v != father) {
          depth = max(dfs(v, u) + 1, depth);
        }
      }
      return depth;
    };

    int depth = dfs(1, 0);
    int res = 1;
    for (int i = 0; i < depth - 2; i++) {
      res = (res << 1) % MOD;
    }
    return res;
  }
};

int main() {
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
  Solution s;
  cout << s.assignEdgeWeights(edges) << "\n";
  return 0;
}
