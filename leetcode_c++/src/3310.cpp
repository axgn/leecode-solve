#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations) {
    vector<unordered_set<int>> callIn(n);
    for (int i = 0; i < invocations.size(); i++) {
      int start = invocations[i].front();
      int end = invocations[i].back();
      callIn[start].insert(end);
    }
    vector<uint8_t> vis(n);
    function<void(int)> dfs = [&](int k) -> void {
      vis[k] = true;
      for (auto &val : callIn[k]) {
        if (vis[val]) {
          continue;
        }
        dfs(val);
      }
    };
    dfs(k);
    bool isremove = true;
    for (int i = 0; i < n; i++) {
      if (vis[i]) {
        continue;
      }
      for (auto &val : callIn[i]) {
        if (vis[val]) {
          isremove = false;
          break;
        }
      }
      if (!isremove) {
        break;
      }
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (isremove) {
        if (!vis[i]) {
          res.push_back(i);
        }
      } else {
        res.push_back(i);
      }
    }
    return res;
  }
};
class Solution2 {
public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations) {

    vector<vector<int>> graph(n);

    for (auto &e : invocations) {
      graph[e[0]].push_back(e[1]);
    }

    vector<bool> vis(n);

    function<void(int)> dfs = [&](int x) {
      vis[x] = 1;
      for (int y : graph[x]) {
        if (!vis[y])
          dfs(y);
      }
    };

    dfs(k);

    bool remove = true;

    for (auto &inv : invocations) {
      int from = inv.front();
      int to = inv.back();
      if (!vis[from] && vis[to]) {
        remove = false;
        break;
      }
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {
      if (!remove || !vis[i])
        ans.push_back(i);
    }

    return ans;
  }
};
int main() {
  Solution s;
  vector<vector<int>> v = {{1, 2}, {0, 2}, {3, 4}, {0, 1}};
  s.remainingMethods(5, 0, v);
  cout << "" << "\n";
  return 0;
}
