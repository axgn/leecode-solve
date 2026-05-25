#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution1 {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.length();
    vector<int8_t> vis(n);
    function<bool(int)> dfs = [&](int i) {
      bool res = false;
      vis[i] = 1;
      for (int j = i + minJump; j <= min(n - 1, i + maxJump); j++) {
        if (vis[j] != 0 || s[j] != '0') {
          continue;
        }
        if (j == n - 1) {
          return true;
        }
        res |= dfs(j);
      }
      return res;
    };
    return dfs(0);
  }
};

class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();
    vector<int8_t> f(n);
    vector<int> sum(n + 1);
    f[0] = true;
    sum[1] = 1;

    for (int j = 1; j < n; j++) {
      f[j] = j >= minJump && s[j] == '0' &&
             sum[j - minJump + 1] > sum[max(j - maxJump, 0)];
      sum[j + 1] = sum[j] + f[j];
    }

    return f[n - 1];
  }
};

int main() {
  Solution s;
  cout << s.canReach("01101110", 2, 3) << "\n";
  return 0;
}
