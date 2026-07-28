#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  string smallestPalindrome(string s) {
    array<int, 26> cnt;
    for_each(s.begin(), s.end(), [&](char &c) { cnt[c - 'a']++; });
    string res;
    int temp = -1;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 2) {
        cnt[i] -= 1;
        temp = i;
      }
      int cnt1 = cnt[i] / 2;
      for (int j = 0; j < cnt1; j++) {
        res.push_back(i + 'a');
      }
    }
    string res2(res.size(),'0');
    reverse_copy(res.begin(), res.end(), res2.begin());
    if (temp != -1) {
      res.push_back(temp + 'a');
    }
    return res + res2;
  }
};
int main() {
  Solution s;
  s.smallestPalindrome("ababb");
  cout << "" << "\n";
  return 0;
}
