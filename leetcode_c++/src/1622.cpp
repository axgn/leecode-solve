#include <iostream>
#include <vector>

class Fancy {
  std::vector<long long> vec;
  long long add;
  long long mul;
  static constexpr long long Mod = 1'000'000'007;

  long long pow(long long x, int n) {
    long long res = 1;
    for (; n; n /= 2) {
      if (n % 2) {
        res = res * x % Mod;
      }
      x = x * x % Mod;
    }
    return res;
  }

public:
  Fancy() : vec(), add(0), mul(1) {}

  void append(int val) {
    vec.push_back((val - add + Mod) * pow(mul, Mod - 2) % Mod);
  }

  void addAll(int inc) { add = (add + inc) % Mod; }

  void multAll(int m) {
    mul = (m * mul) % Mod;
    add = (m * add) % Mod;
  }

  int getIndex(int idx) {
    if (idx >= vec.size()) {
      return -1;
    }
    return (vec[idx] * mul + add) % Mod;
  }
};

int main(int argc, const char **argv) {
  Fancy *obj = new Fancy();
  obj->append(2);
  obj->append(3);
  obj->append(4);
  obj->append(5);
  obj->addAll(3);
  obj->multAll(3);
  int param_4 = obj->getIndex(0);

  std::cout << param_4 << std::endl;
  return 0;
}
