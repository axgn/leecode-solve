#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

// 使用最大值进行切段
class Solution1 {
  int maxProfit1(vector<int> &prices, int &min_pos, int &max_pos) {
    int min = 100000;
    int max = 0;
    int result = 0;
    int min_pos1 = 0;
    for (int i = 1; i < (int)prices.size(); i++) {
      if (prices[i] < prices[i - 1]) {
        max = prices[i - 1];
        int temp = max - min;
        if (result < temp) {
          max_pos = i - 1;
          min_pos = min_pos1;
          result = temp;
        }
      }
      if (prices[i - 1] < min) {
        min = prices[i - 1];
        min_pos1 = i - 1;
      }
    }
    int temp = prices[prices.size() - 1] - min;
    if (temp > result) {
      min_pos = min_pos1;
      max_pos = prices.size() - 1;
      result = temp;
    }
    return result;
  }

public:
  int maxProfit(vector<int> &prices) {
    int result = 0;
    int min_pos = -1, max_pos = -1;
    result = maxProfit1(prices, min_pos, max_pos);
    vector<int> prices1;
    for (int i = 0; i < (int)prices.size(); i++) {
      if (i != min_pos && i != max_pos) {
        prices1.push_back(prices[i]);
      }
    }
    int result2 = maxProfit1(prices1, min_pos, max_pos);
    return result + result2;
  }
};

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;
    for (int i = 1; i < n; ++i) {
      buy1 = max(buy1, -prices[i]);
      sell1 = max(sell1, buy1 + prices[i]);
      buy2 = max(buy2, sell1 - prices[i]);
      sell2 = max(sell2, buy2 + prices[i]);
    }
    return sell2;
  }
};

int main() {
  Solution s;
  vector<int> v = {3, 3, 5, 0, 0, 3, 1, 4};
  ranges::copy(v, ostream_iterator<int>(cout, " "));
  cout << '\n';
  int result = s.maxProfit(v);
  cout << result << "\n";
  return 0;
}
