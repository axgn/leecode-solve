#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
  bool findSafeWalk(vector<vector<int>> &grid, int health) {
    int m = grid.size();
    int n = grid[0].size();
    vector<pair<int, int>> dire = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    deque<pair<int, int>> q;
    vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
    dis[0][0] = grid[0][0];
    q.push_back({0, 0});
    while (true) {
      auto [x, y] = q.front();
      q.pop_front();
      if (dis[x][y] >= health) {
        return false;
      }
      if (x == m - 1 && y == n - 1) {
        return true;
      }
      for (const auto &[dx, dy] : dire) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 &&
            dis[nx][ny] > dis[x][y] + grid[nx][ny]) {
          q.push_back({nx, ny});
          dis[nx][ny] = dis[x][y] + grid[nx][ny];
        } else if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                   grid[nx][ny] == 0 &&
                   dis[nx][ny] > dis[x][y] + grid[nx][ny]) {
          q.push_front({nx, ny});
          dis[nx][ny] = dis[x][y] + grid[nx][ny];
        }
      }
    }
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
