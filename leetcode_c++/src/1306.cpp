#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  bool canReach(vector<int> &arr, int start) {
    int n = arr.size();
    vector<int> vis(n);
    function<bool(int)> dfs = [&](int i) {
      if (i < 0 || i > n - 1 || vis[i] != 0) {
        return false;
      }
      vis[i] = 1;
      if (arr[i] == 0) {
        return true;
      }
      return dfs(i + arr[i]) || dfs(i - arr[i]);
    };
    return dfs(start);
  }
};

int main() {
  Solution s;
  auto arr = vector<int>{0, 3, 0, 6, 3, 3, 4};
  cout << s.canReach(arr, 6) << "\n";
  return 0;
}
