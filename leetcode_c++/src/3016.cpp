#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int minimumPushes(string word) {
    int cnt[26] = {0};
    for (auto &ch : word) {
      cnt[ch - 'a']++;
    }
    ranges::sort(cnt, greater());
    int res = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] == 0) {
        continue;
      }
      res += cnt[i] * (i / 8 + 1);
    }
    return res;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
