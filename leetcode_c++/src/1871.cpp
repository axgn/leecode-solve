#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.length();
    vector<int8_t> vis(n);
    function<bool(int)> dfs = [&](int i) {
      bool res = true;
      for (int j = i + minJump; j <= i + maxJump; j++) {
        if (vis[j] != 0) {
          continue;
        }
        vis[j] = 1;
        dfs(j);
      }
      return res;
    };
    return dfs(0);
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
