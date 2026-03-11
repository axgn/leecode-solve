#include <array>
#include <vector>

using namespace std;


//二维dp不具有可行性
class Solution {
public:
  int numberOfStableArrays(int zero, int one, int limit) {
    const int MOD = 1'000'000'007;
    vector<vector<int>> f(zero + 1, vector<int>(one + 1));
    for (int i = 1; i <= min(limit, zero); i++) {
      f[i][0] = 1;
    }
    for (int j = 1; j <= min(limit, one); j++) {
      f[0][j] = 1;
    }
    for (int i = 1; i <= zero; i++) {
      for (int j = 1; j <= one; j++) {
        f[i][j] = ((long long)f[i - 1][j] + f[i][j - 1] +
                   (i > limit ? MOD - f[i - limit - 1][j] : 0) +
                   (j > limit ? MOD - f[i][j - limit - 1] : 0)) %
                  MOD;
      }
    }
    return f[zero][one] % MOD;
  }
};
