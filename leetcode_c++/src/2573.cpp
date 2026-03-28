#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string findTheString(vector<vector<int>> &lcp) {
    int n = lcp.size();
    string res(n, 0);
    int i = 0;
    auto f = [&](int c) {
      for (int j = i; j < n; j++) {
        if (lcp[i][j]) {
          res[j] = c;
        }
      }
      while (i < n && res[i] != 0) {
        i++;
      }
      if (i == n) {
        return;
      }
    };
    for (int c = 'a'; c <= 'z'; c++) {
      f(c);
    }
    if (i < n) {
      return "";
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        int actual_lcp;
        if (res[i] != res[j]) {
          actual_lcp = 0;
        } else if (i == n - 1 || j == n - 1) {
          actual_lcp = 1;
        } else {
          actual_lcp = lcp[i + 1][j + 1] + 1;
        }

        if (lcp[i][j] != actual_lcp) {
          return "";
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> a{{1, 2, 3}};
  s.findTheString(a);
  cout << "" << "\n";
  return 0;
}
