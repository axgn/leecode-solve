#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<int, int> cnt;
  int indexs[26];
  void set_cnt(const string &str) {
    for (auto &ch : str) {
      cnt[ch - 'a']++;
    }
  }
  void set_indexs(const int i) {
    for (int j = 0; j < 26; j++) {
      indexs[j] = cnt[(j - i + 26) % 26];
    }
  }

public:
  int lengthAfterTransformations(string s, int t, vector<int> &nums) {
    int result = s.length();
    set_cnt(s);
    int divide = pow(10, 9) + 7;
    for (int i = 0; i < t; i++) {
      set_indexs(i % 26);
      for (int j = 0; j < 26; j++) {
        for (int k = 1; k < nums[j]; k++) {
          result = (result + indexs[j]) % divide;
          int temp = ((i - k + 26) % 26);
          cnt[(j - temp + 26) % 26] =
              (cnt[(j - temp + 26) % 26] + indexs[j]) % divide;
        }
      }
    }
    return result;
  }
};
static constexpr int L = 26;
static constexpr int mod = 1000000007;

struct Mat {
  Mat() { memset(a, 0, sizeof(a)); }
  Mat(const Mat &that) {
    for (int i = 0; i < L; ++i) {
      for (int j = 0; j < L; ++j) {
        a[i][j] = that.a[i][j];
      }
    }
  }
  Mat &operator=(const Mat &that) {
    if (this != &that) {
      for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j) {
          a[i][j] = that.a[i][j];
        }
      }
    }
    return *this;
  }

  int a[L][L];
};

Mat operator*(const Mat &u, const Mat &v) {
  Mat w;
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < L; ++j) {
      for (int k = 0; k < L; ++k) {
        w.a[i][j] = (w.a[i][j] + (long long)u.a[i][k] * v.a[k][j]) % mod;
      }
    }
  }
  return w;
}

Mat I() {
  Mat w;
  for (int i = 0; i < L; ++i) {
    w.a[i][i] = 1;
  }
  return w;
}

Mat quickmul(const Mat &x, int y) {
  Mat ans = I(), cur = x;
  while (y) {
    if (y & 1) {
      ans = ans * cur;
    }
    cur = cur * cur;
    y >>= 1;
  }
  return ans;
}

class Solution2 {
public:
  int lengthAfterTransformations(string s, int t, vector<int> &nums) {
    Mat T;
    for (int i = 0; i < 26; ++i) {
      for (int j = 1; j <= nums[i]; ++j) {
        T.a[(i + j) % 26][i] = 1;
      }
    }
    Mat res = quickmul(T, t);
    int ans = 0;
    vector<int> f(26);
    for (char ch : s) {
      ++f[ch - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        ans = (ans + (long long)res.a[i][j] * f[j]) % mod;
      }
    }
    return ans;
  }
};
int main() {
  Solution2 s;
  string str = "c";
  vector<int> nums = {1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int result = s.lengthAfterTransformations(str, 26, nums);
  cout << result;
  return 0;
}
