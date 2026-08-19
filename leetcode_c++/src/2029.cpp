#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  bool stoneGameIX(vector<int> &stones) {
    int cnt[3] = {0};
    ranges::for_each(stones, [&](int i) { cnt[i % 3]++; });
    int min1 = min(cnt[1], cnt[2]);
    auto CountRound = [&](int a) {
      int round;
      int temp = a - min1;
      if (temp > 0) {
        round = min1 * 2 + min(2, temp);
      } else {
        round = a * 2 - 1;
      }
      round += cnt[0];
      if (a == 0) {
        round = 0;
      }
      return round;
    };
    int round1 = CountRound(cnt[1]);
    int round2 = CountRound(cnt[2]);
    return (round1 < stones.size() && round1 % 2) ||
           (round2 < stones.size() && round2 % 2);
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
