#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int numOfStrings(vector<string> &patterns, string word) {
    int cnt = 0;
    int n = patterns.size();
    for (int i = 0; i < n; i++) {
      if (word.contains(patterns[i])) {
        cnt++;
      }
    }
    return cnt;
  }
};
int main() {
  Solution s;
  static_assert(_LIBCPP_STD_VER >= 23);
  cout << "" << "\n";
  return 0;
}
