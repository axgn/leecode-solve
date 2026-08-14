#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumLengthSubstring(string s) {
    int n = s.size();
    unordered_map<int, int> cnt;
    int left = 0, right = 0;
    int max_length = 0;

    for (; right < n; right++) {
      cnt[s[right]]++;
      while (cnt[s[right]] > 2) {
        cnt[s[left]]--;
        left++;
      }
      if (right - left > max_length) {
        max_length = right - left;
      }
    }
    return max_length + 1;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
