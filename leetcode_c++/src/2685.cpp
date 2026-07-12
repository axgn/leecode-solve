#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graphtable(n);
    vector<int> unionset(n);
    for (int i = 0; i < n; i++) {
      unionset[i] = i;
    }
    function<int(int)> find = [&](int value) {
      if (unionset[value] == value) {
        return value;
      }
      unionset[value] = find(unionset[value]);
      return unionset[value];
    };
    function<void(int, int)> Union = [&](int value1, int value2) {
      unionset[find(value1)] = find(value2);
    };
    for (auto &edge : edges) {
      int start = edge.front();
      int end = edge.back();
      graphtable[start].push_back(end);
      graphtable[end].push_back(start);
      Union(edge.front(), edge.back());
    }
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[find(i)]++;
    }
    for (int i = 0; i < n; i++) {
      int temp = cnt[find(i)];
      if (temp == -1) {
        continue;
      }
      if (temp - 1 != (int)graphtable[i].size()) {
        cnt[find(i)] = -1;
      }
    }
    int res = 0;
    for (auto &[k, v] : cnt) {
      if (v != -1) {
        res++;
      }
    }
    return res;
  }
};
class Solution2 {
public:
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    vector<vector<int>> g(n);
    for (auto &e : edges) {
      int x = e[0], y = e[1];
      g[x].push_back(y);
      g[y].push_back(x);
    }

    vector<int8_t> vis(n);
    int v, e;

    auto dfs = [&](this auto &&dfs, int x) -> void {
      v++;
      e += g[x].size();
      vis[x] = true;
      for (int y : g[x]) {
        if (!vis[y]) {
          dfs(y);
        }
      }
    };

    int ans = 0;
    for (int i = 0; i < g.size(); i++) {
      if (!vis[i]) {
        v = 0;
        e = 0;
        dfs(i);
        ans += e == v * (v - 1);
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
