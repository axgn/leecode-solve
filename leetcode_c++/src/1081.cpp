#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  string smallestSubsequence(string s) {
    unordered_map<int, int> ch_map;
    ranges::for_each(s, [&](char c) { ch_map[c]++; });
    string ans;
    unordered_map<int, bool> in_ans;
    ranges::for_each(s, [&](char c) {
      ch_map[c]--;
      if (!in_ans[c]) {
        while (!ans.empty() && c < ans.back() && ch_map[ans.back()] > 0) {
          in_ans[ans.back()] = false;
          ans.pop_back();
        }
        ans.push_back(c);
        in_ans[c] = true;
      }
    });
    return ans;
  }
};
int main() {
  Solution s;
  s.smallestSubsequence("bcabc");
  cout << "" << "\n";
  return 0;
}
