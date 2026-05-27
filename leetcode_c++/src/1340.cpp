#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int maxJumps(vector<int> &arr, int d) {
    int n = arr.size();
    vector<int> memo(n);
    function<int(int)> dfs = [&](int i) -> int {
      int &res = memo[i];
      if (res != 0) {
        return res;
      }
      res = 1;
      for (int j = i + 1; j <= min(n - 1, i + d) && arr[j] < arr[i]; j++) {
        res = max(res, dfs(j) + 1);
      }
      for (int j = i - 1; j >= max(0, i - d) && arr[j] < arr[i]; j--) {
        res = max(res, dfs(j) + 1);
      }
      return res;
    };
    int ans = 1;
    for (int i = 0; i < n; i++) {
      int temp = dfs(i);
      if (temp > ans) {
        ans = temp;
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
