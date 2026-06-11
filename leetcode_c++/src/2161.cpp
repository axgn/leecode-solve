#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> pivotArray(vector<int> &nums, int pivot) {
    int n = nums.size();
    vector<int> res(n);
    vector<int> res2(n);
    int i = 0;
    int k = 0;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (nums[j] < pivot) {
        res[i] = nums[j];
        i++;
      } else if (nums[j] == pivot) {
        cnt++;
      } else {
        res2[k] = nums[j];
        k++;
      }
    }
    while (cnt--) {
      res[i++] = pivot;
    }
    while (k--) {
      res[i + k] = res2[k];
    }
    return res;
  };
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
