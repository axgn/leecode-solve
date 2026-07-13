#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> res;
    for (int i = 2; i < 10; i++) {
      for (int k = 1; k <= 10 - i; k++) {
        int num = 0;
        for (int j = k; j < k + i; j++) {
          num = num * 10 + j;
        }
        if (num >= low && num <= high) {
          res.push_back(num);
        }
      }
    }
    return res;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
