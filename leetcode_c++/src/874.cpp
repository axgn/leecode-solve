#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
  unordered_set<int> sets;
  void initset(vector<vector<int>> &obstacles) {
    for (auto &v : obstacles) {
      sets.insert(v[0] * 40000 + v[1]);
    }
  }

public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    int x = 0, y = 0;
    int direction = 0;
    int max_val = 0;
    int n = commands.size();
    initset(obstacles);
    vector<function<void()>> v_func = {[&]() { y += 1; }, [&]() { x += 1; },
                                       [&]() { y -= 1; }, [&]() { x -= 1; }};
    for (int i = 0; i < n; i++) {
      auto command = commands[i];
      if (command < 0) {
        if (command == -1) {
          direction = (direction + 1) % 4;
        } else {
          direction = (direction + 3) % 4;
        }
      } else {
        for (int j = 0; j < command; j++) {
          v_func[direction]();
          if (sets.contains(x * 40000 + y)) {
            v_func[(direction + 2) % 4]();
            break;
          }
        }
      }
      max_val = max(max_val, x * x + y * y);
    }
    return max_val;
  }
};
int main() {
  Solution s;
  vector<vector<int>> vv = {{2, 4}};
  vector<int> v = {4, -1, 4, -2, 4};
  ranges::copy(v, ostream_iterator<int>(cout, " "));
  cout << '\n';
  for (auto &v : vv) {
    ranges::copy(v, ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
  s.robotSim(v, vv);
  return 0;
}
