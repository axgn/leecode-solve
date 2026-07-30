#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int minimumPushes(string word) {
    int n = word.size();
    int k = n / 8;
    return (4 * k + (n % 8)) * (k + 1);
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
