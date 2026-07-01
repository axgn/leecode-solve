#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <ranges>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumSafenessFactor(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<pair<int, int>> points;
    vector<pair<int, int>> all;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          points.push_back({i, j});
          all.push_back({i, j});
        }
      }
    }
    while (!points.empty()) {
      vector<pair<int, int>> temp;
      for (auto &v : points) {
        int i = v.first;
        int j = v.second;
        pair<int, int> direction[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int k = 0; k < 4; k++) {
          int n_i = i + direction[k].first;
          int n_j = j + direction[k].second;
          if (n_i >= 0 && n_i <= n - 1 && n_j >= 0 && n_j <= m - 1 &&
              grid[n_i][n_j] == 0) {
            grid[n_i][n_j] = grid[i][j] + 1;
            temp.push_back({n_i, n_j});
            all.push_back({n_i, n_j});
          }
        }
      }
      points = std::move(temp);
    }
    auto id = [&](int i, int j) { return i * n + j; };
    vector<int> parent(n * m);
    for (int i = 0; i < n * m; i++) {
      parent[i] = i;
    }
    auto find = [&](auto &&find, int x) {
      if (parent[x] == x) {
        return x;
      }
      return parent[x] = find(parent[x]);
    };
    for (auto &[i, j] : views::reverse(all)) {
      
    }
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
