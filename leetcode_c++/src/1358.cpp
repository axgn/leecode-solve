#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int numberOfSubstrings(string s) {
    int fast = 0;
    int slow = 0;
    int n = s.length();
    unsigned long long cnt = 0;
    constexpr uint64_t MASK = 0xffffLL;
    while (slow <= n - 1) {
      while (cnt & (MASK << 16) && cnt & (MASK << 32) && cnt & (MASK)) {
        if (s[fast] == 'a') {
          cnt++;
        } else if (s[fast] == 'b') {

        } else {
          cnt;
        }
        fast++;
      }
    }
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
