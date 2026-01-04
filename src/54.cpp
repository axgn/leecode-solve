#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  struct ACTION {
    int i;
    int j;
  };
  vector<int> spiralOrder(vector<vector<int>> &matrix) {

    vector<int> result;
    vector<vector<int>> is_arrived(matrix.size(),
                                   vector<int>(matrix[0].size(), 0));
    int i = 0, j = 0;
    is_arrived[i][j] = 1;
    ACTION a = {.i = 1, .j = 0};
    while (check_end(is_arrived, a, i, j)) {
      i += a.i, j += a.j;
      is_arrived[i][j] = 1;
      result.push_back(matrix[i][j]);
    }
    return result;
  }

  void change_direct(ACTION &a) {
    if (a.i == -1) {

    } else if (a.i == 1) {

    } else if (a.j == -1) {

    } else if (a.j == 1) {
    }
  }

  bool check_end(vector<vector<int>> &is_arrived, const ACTION &a, int i,
                 int j) {
    int next_i = i + a.i, next_j = j + a.j;
    if (next_i < 0 || next_j < 0 || next_i > (int)is_arrived.size() ||
        next_j > (int)is_arrived[0].size()) {
      return false;
    }
    if (is_arrived[next_i][next_j] == 1) {
      return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<vector<int>> vv = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (auto &v : vv) {
    ranges::copy(v, ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
  cout << "" << "\n";
  vector<int> v = s.spiralOrder(vv);
  ranges::copy(v, ostream_iterator<int>(cout, " "));
  return 0;
}
