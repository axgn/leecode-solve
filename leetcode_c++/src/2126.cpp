#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  bool asteroidsDestroyed(int mass, vector<int> &asteroids) {
    sort(asteroids.begin(), asteroids.end());
    int64_t res = mass;
    for (auto &v : asteroids) {
      if (v <= res) {
        res += v;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
