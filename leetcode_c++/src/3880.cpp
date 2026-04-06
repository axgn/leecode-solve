#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int minAbsoluteDifference(vector<int> &nums) {
    int n = nums.size();
    int min = 50000;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 1) {
        for (int j = i + 1; j < n; j++) {
          if (nums[j] == 2) {
            int temp = j - i;
            if (temp < min) {
              min = temp;
            }
            break;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] == 2) {
        for (int j = i + 1; j < n; j++) {
          if (nums[j] == 1) {
            int temp = j - i;
            if (temp < min) {
              min = temp;
            }
            break;
          }
        }
      }
    }
    if (min == 50000) {
      return -1;
    }
    return min;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
