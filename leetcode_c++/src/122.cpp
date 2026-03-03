#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

// 使用最大值进行切段
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int min = 100000;
    int max = 0;
    int result = 0;
    for (int i = 1; i < (int)prices.size(); i++) {
      if (prices[i] < prices[i - 1]) {
        max = prices[i - 1];
        int temp = max - min;
        if (temp > 0) {
          result += temp;
          min = 100000;
        }
      }
      if (prices[i - 1] < min) {
        min = prices[i - 1];
      }
    }
    int temp = prices[prices.size() - 1] - min;
    if (temp > 0) {
      result += temp;
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<int> v = {7, 2, 5, 3, 6, 4, 1, 9, 8};
  ranges::copy(v, ostream_iterator<int>(cout, " "));
  cout << '\n';
  int result = s.maxProfit(v);
  cout << result << "\n";
  return 0;
}
