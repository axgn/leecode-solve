#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int maxIceCream(vector<int> &costs, int coins) {
    vector<int> cnt(100001);
    int min = INT_MAX;
    int max = INT_MIN;
    for (auto &cost : costs) {
      cnt[cost]++;
      min = cost < min ? cost : min;
      max = cost > max ? cost : max;
    }
    int cream_cnt = 0;
    for (int i = min; i <= max; i++) {
      if (cnt[i] > 0) {
        int temp = coins / i;
        if (cnt[i] >= temp) {
          cream_cnt += temp;
          break;
        }
        coins -= cnt[i] * i;
        cream_cnt += cnt[i];
      }
    }
    return cream_cnt;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
