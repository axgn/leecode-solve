#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <string>
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
    int result = 0;
    while (fast <= n - 1) {
      if (s[fast] == 'a') {
        cnt++;
      } else if (s[fast] == 'b') {
        cnt = cnt + (1LL << 16);
      } else if (s[fast] == 'c') {
        cnt = cnt + (1LL << 32);
      }
      while ((cnt & (MASK << 16)) && (cnt & (MASK << 32)) && (cnt & (MASK))) {
        if (s[slow] == 'a') {
          cnt--;
        } else if (s[slow] == 'b') {
          cnt = cnt - (1LL << 16);
        } else if (s[slow] == 'c') {
          cnt = cnt - (1LL << 32);
        }
        slow++;
      }
      result += slow;
      fast++;
    }
    return result;
  }
};

int main() {
  Solution s;
  string s1 = "bcaaa";
  cout << s.numberOfSubstrings(s1) << "\n";
  return 0;
}
