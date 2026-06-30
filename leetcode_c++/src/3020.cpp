#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumLength(vector<int> &nums) {
    unordered_map<long long, int> v_map;
    int res = INT_MIN;
    for (auto &v : nums) {
      v_map[v]++;
    }
    for (auto &kv : v_map) {
      long long temp = kv.first;
      int cnt = 0;
      if (temp == 1) {
        continue;
      }
      while (v_map.contains(temp)) {
        if (v_map[temp] == 1) {
          cnt++;
          break;
        }
        cnt++;
        temp = temp * temp;
      }
      cnt = 2 * cnt - 1;
      res = cnt > res ? cnt : res;
    }
    int temp = v_map[1] % 2 ? v_map[1] : v_map[1] - 1;
    return res > temp ? res : temp;
  }
};

int main() {
  Solution s;
  vector<int> num = {48841,  358801,    28561, 18974736,  4356,     221,
                     358801, 599,       13,    4356,      66,       48841,
                     28561,  815730721, 13,    815730721, 18974736, 66,
                     169,    599,       169,   221};
  cout << s.maximumLength(num) << "\n";
  return 0;
}
