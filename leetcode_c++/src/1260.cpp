#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int mn = m * n;
    k = k % mn;

    for (int i = 0; i < k; i++) {
      int temp = grid[m - 1][n - 1];
      for (int j = m - 1; j >= 0; j--) {
        for (int l = n - 1; l >= 0; l--) {
          if (j == 0 && l == 0) {
            grid[j][l] = temp;
            continue;
          }
          if (l == 0) {
            grid[j][l] = grid[j - 1][n - 1];
            continue;
          }
          grid[j][l] = grid[j][l - 1];
        }
      }
    }
    return grid;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
