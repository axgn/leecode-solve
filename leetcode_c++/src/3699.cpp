#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
  int zigZagArrays(int n, int l, int r) {
    int k = r - l + 1;
    int MOD = 1'000'000'007;
    vector<int> f(k, 1);
    vector<int> f2(k, 1);
    for (int i = 0; i < n; i++) {
      vector<long long> sumf(k + 1);
      vector<long long> sumf2(k + 1);
      for (int j = 1; j <= k; j++) {
        sumf[j] = sumf[j - 1] + f[j - 1];
        sumf2[j] = sumf2[j - 1] + f2[j - 1];
      }
      for (int j = 0; j < k; j++) {
        f[j] = (sumf2[j]) % MOD;
        f2[j] = (sumf[k] - sumf[j + 1]) % MOD;
      }
      long long sum_f = reduce(f.begin(), f.end(), 0LL);
      long long sum_f2 = reduce(f2.begin(), f2.end(), 0LL);
      return (sum_f + sum_f2) % MOD;
    }
  };
  int main() {
    Solution s;
    cout << "" << "\n";
    return 0;
  }
