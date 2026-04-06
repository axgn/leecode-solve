#include <vector>

using namespace std;

class Solution {
  static constexpr int MOD = 1'000'000'007;
  vector<long long> fact, invfact;

  long long qpow(long long a, long long b) {
    long long res = 1;
    while (b) {
      if (b & 1)
        res = res * a % MOD;
      a = a * a % MOD;
      b >>= 1;
    }
    return res;
  }

  void init(int n) {
    fact.resize(n + 1);
    invfact.resize(n + 1);

    fact[0] = 1;
    for (int i = 1; i <= n; i++)
      fact[i] = fact[i - 1] * i % MOD;

    invfact[n] = qpow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
      invfact[i] = invfact[i + 1] * (i + 1) % MOD;
  }

  long long C(int n, int k) {
    if (k < 0 || k > n)
      return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
  }

public:
  int countVisiblePeople(int n, int pos, int k) {
    init(n);
    return 2LL * C(n - 1, k) % MOD;
  }
};
