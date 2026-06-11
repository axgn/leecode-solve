#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumCost(vector<int> &cost) {
    sort(cost.begin(), cost.end(), [](int a, int b) -> bool { return a > b; });
    int n = cost.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (i % 3 != 2) {
        sum += cost[i];
      }
    }
    return sum;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
