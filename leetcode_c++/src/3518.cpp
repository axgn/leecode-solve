#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  string smallestPalindrome(string s, int k) {
    int n = s.size();
    int m = n / 2;

    int cnt[26]{};
    for (int i = 0; i < m; i++) {
      cnt[s[i] - 'a']++;
    }

    auto comb = [&](int n, int m) -> int {
      m = min(m, n - m);
      long long res = 1;
      for (int i = 1; i <= m; i++) {
        res = res * (n + 1 - i) / i;
        if (res >= k) {
          return k;
        }
      }
      return res;
    };

    auto perm = [&](int sz) -> int {
      long long res = 1;
      for (int c : cnt) {
        if (c == 0) {
          continue;
        }

        res *= comb(sz, c);
        if (res >= k) {
          return k;
        }

        sz -= c;
      }
      return res;
    };

    if (perm(m) < k) {
      return "";
    }

    string left_s(m, 0);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < 26; j++) {
        if (cnt[j] == 0) {
          continue;
        }
        cnt[j]--;
        int p = perm(m - i - 1);
        if (p >= k) {
          left_s[i] = 'a' + j;
          break;
        }
        k -= p;
        cnt[j]++;
      }
    }

    string ans = left_s;
    if (n % 2) {
      ans += s[n / 2];
    }
    ranges::reverse(left_s);
    return ans + left_s;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
