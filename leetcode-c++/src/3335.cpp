#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
  unordered_map<char, int> cnt;
  void set_cnt(const string &str) {
    for (auto &ch : str) {
      cnt[ch]++;
    }
  }

public:
  int lengthAfterTransformations(string s, int t) {
    int result = s.length();
    set_cnt(s);
    int divide = pow(10, 9) + 7;
    for (int i = 0; i < t; i++) {
      int index = cnt['z' - i % 26] % divide;
      result = (result + index) % divide;
      int temp = ((i + 25) % 26);
      cnt['z' - temp] = (cnt['z' - temp] + index) % divide;
    }
    return result;
  }
};
int main() {
  Solution s;
  string str = "z";
  int result = s.lengthAfterTransformations(str, 26);
  cout << result;
  return 0;
}
