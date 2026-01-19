#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
    int result = 0;
    return result;
  }
};
int main() {
  Solution s;
  vector<vector<int>> matrix = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  int a = s.minPathSum(matrix);
  cout << a << "\n";
  vector<vector<int>> dp(0, vector<int>(1));
  for (auto i : dp) {
    cout << i[0];
  }
  return 0;
}
