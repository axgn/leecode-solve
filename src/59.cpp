#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  struct ACTION {
    int i;
    int j;
  };
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n));
    int value = 0;
    int i = 0, j = 0;
    result[i][j] = ++value;
    ACTION a = {.i = 0, .j = 1};
    while (true) {
      if (check_end(result, a, i, j)) {
        change_direct(a);
        if (check_end(result, a, i, j)) {
          break;
        }
      }
      i += a.i, j += a.j;
      result[i][j] = ++value;
    }

    return result;
  }

  void change_direct(ACTION &a) {
    if (a.j == -1) {
      a.j = 0, a.i = -1;
    } else if (a.j == 1) {
      a.j = 0, a.i = 1;
    } else if (a.i == -1) {
      a.j = 1, a.i = 0;
    } else if (a.i == 1) {
      a.j = -1, a.i = 0;
    }
  }

  bool check_end(vector<vector<int>> &is_arrived, const ACTION &a, int i,
                 int j) {
    int next_i = i + a.i, next_j = j + a.j;
    if (next_i < 0 || next_j < 0 || next_i >= (int)is_arrived.size() ||
        next_j >= (int)is_arrived[0].size()) {
      return true;
    }
    if (is_arrived[next_i][next_j] != 0) {
      return true;
    }
    return false;
  };
};

int main() {
  Solution s;
  vector<vector<int>> vv = s.generateMatrix(3);
  for (auto &v : vv) {
    ranges::copy(v, ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
  cout << "" << "\n";
  cout << "one" << endl;
  cout << "one" << endl;
  return 0;
}
