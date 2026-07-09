#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) -> bool {
           if (a.front() == b.front()) {
             return a.back() > b.back();
           }
           return a.front() < b.front();
         });
    int max_right = INT_MIN;
    int n = intervals.size();
    for (auto &subvec : intervals) {
      int right = subvec.back();
      if (right <= max_right) {
        n--;
      } else {
        max_right = right;
      }
    }
    return n;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
