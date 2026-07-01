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
    while (slow <= n - 1) {
      while (!(cnt & (MASK << 16)) || !(cnt & (MASK << 32)) ||
             !(cnt & (MASK))) {
        if (fast > n - 1) {
          break;
        }
        if (s[fast] == 'a') {
          cnt++;
        } else if (s[fast] == 'b') {
          cnt = cnt + (1LL << 16);
        } else if (s[fast] == 'c') {
          cnt = cnt + (1LL << 32);
        }
        fast++;
      }
      result += n - fast + 1;
      while ((cnt & (MASK << 16)) && (cnt & (MASK << 32)) && (cnt & (MASK))) {
        if (slow > n - 1) {
          break;
        }
        if (s[slow] == 'a') {
          cnt--;
        } else if (s[slow] == 'b') {
          cnt = cnt - (1LL << 16);
        } else if (s[slow] == 'c') {
          cnt = cnt - (1LL << 32);
        }
        slow++;
      }
      if (fast > n - 1) {
        break;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  string s1 = "abcabc";
  cout << s.numberOfSubstrings(s1) << "\n";
  return 0;
}
