#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> result;
  int end;
  vector<int> temp;
  void backtrace(int start, int k) {
    if (k == 0) {
      result.push_back(temp);
      return;
    }
    for (int i = start; i <= end; i++) {
      temp.push_back(i);
      backtrace(i + 1, k - 1);
      temp.pop_back();
    }
  }

public:
  vector<vector<int>> combine(int n, int k) {
    end = n;
    backtrace(1, k);
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<int>> vv = s.combine(4, 1);
  for (auto &v : vv) {
    ranges::copy(v, ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
  return 0;
}
