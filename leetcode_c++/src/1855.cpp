#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int maxDistance(vector<int> &nums1, vector<int> &nums2) {
    int ans = 0;
    int i = 0;
    for (int j = 0; j < nums2.size(); j++) {
      while (i < nums1.size() && nums1[i] > nums2[j]) {
        i++;
      }
      if (i == nums1.size()) {
        break;
      }
      ans = max(ans, j - i);
    }
    return ans;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
