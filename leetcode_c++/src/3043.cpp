#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    int ans = 0;
    unordered_set<string> set_s;
    for (auto &v : arr1) {
      string temp = to_string(v);
      for (size_t i = 1; i <= temp.length(); i++) {
        set_s.insert(temp.substr(0, i));
      }
    }
    for (auto &v : arr2) {
      string temp = to_string(v);
      for (size_t i = 1; i <= temp.length(); i++) {
        if (set_s.contains(temp.substr(0, i))) {
          ans = max((int)i, ans);
        }
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
