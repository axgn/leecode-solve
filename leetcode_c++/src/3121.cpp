#include <algorithm>
#include <bit>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int numberOfSpecialChars(string word) {
    unordered_set<char> upper;
    unordered_set<char> lower_before;
    unordered_set<char> lower_after;
    int cnt = 0;
    for (auto &c : word) {
      if (islower(c)) {
        if (upper.contains(toupper(c))) {
          lower_after.insert(c);
        } else {
          lower_before.insert(c);
        }
      } else if (isupper(c)) {
        upper.insert(c);
      }
    }
    for (auto &v : lower_before) {
      if (upper.contains(toupper(v)) && !lower_after.contains(v)) {
        cnt++;
      }
    }
    return cnt;
  }
};

class Solution2 {
public:
  int numberOfSpecialChars(string word) {
    uint32_t upper = 0;
    uint32_t lower_before = 0;
    uint32_t lower_after = 0;
    int cnt = 0;
    for (auto &c : word) {
      if (islower(c)) {
        int temp = (1 << (c - 'a'));
        if (upper & temp) {
          lower_after |= temp;
        } else {
          lower_before |= temp;
        }
      } else if (isupper(c)) {
        upper |= 1 << (c - 'A');
      }
    }
    cnt = popcount(upper & lower_before & ~lower_after);
    return cnt;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
