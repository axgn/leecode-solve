#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minTimeToReach(vector<vector<int>> &moveTime) {
    int result = 0;
    
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<int>> vv = {{0, 4}, {4, 4}};
  int num = s.minTimeToReach(vv);
  for (auto &v : vv) {
    ranges::copy(v, ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
  cout << num << endl;
  return 0;
}
