#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    int x = 0, y = 0;
    int direction = 0;
    int max_val = 0;
    int n = commands.size();
    for (int i = 0; i < n; i++) {
      auto command = commands[i];
      if (command < 0) {
        if (command == -1) {
          direction = (direction + 1) % 4;
        } else {
          direction = (direction + 3) % 4;
        }
      } else {
        switch (direction) {
        case 0:
          y += command;
          break;
        case 1:
          x += command;
          break;
        case 2:
          y -= command;
          break;
        case 3:
          x -= command;
        }
      }
      max_val = max(max_val, x * x + y * y);
    }
    return max_val;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
