#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string processStr(string s) {
    string res;
    for (auto &ch : s) {
      if (ch == '*') {
        if (!res.empty()) {
          res.pop_back();
        }
      } else if (ch == '#') {
        res += res;
      } else if (ch == '%') {
        ranges::reverse(res);
      } else {
        res.push_back(ch);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
