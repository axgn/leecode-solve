#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  char processStr(string s, long long k) {
    long long len = 0;
    for (auto &ch : s) {
      if (ch >= 'a' && ch <= 'z') {
        len += 1;
      }
      if (ch == '*' && len != 0) {
        len -= 1;
      }
      if (ch == '#') {
        len *= 2;
      }
    }
    char res = '.';
    if (k >= len) {
      return res;
    }
    for (auto it = s.rbegin(); it != s.rend(); it++) {
      if (*it >= 'a' && *it <= 'z') {
        if (k == len - 1) {
          res = *it;
          break;
        } else {
          len -= 1;
        }
      }
      if (*it == '*' && len != 0) {
        len += 1;
      }
      if (*it == '#') {
        len /= 2;
        if (k >= len) {
          k = k - len;
        }
      }
      if (*it == '%') {
        k = len - 1 - k;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.processStr("cd%#*#", 3) << "\n";
  return 0;
}
