#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int minJumps(vector<int> &arr) {
    unordered_map<int, vector<int>> val_pos;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      val_pos[arr[i]].push_back(i);
    }
    vector<int8_t> vis(n);
    vector<int> travel{0};
    int cnt = -1;
    while (true) {
      auto temp = travel;
      travel.clear();
      cnt++;
      for (auto i : temp) {
        if (i == n - 1) {
          return cnt;
        }
        val_pos[arr[i]].push_back(i + 1);
        val_pos[arr[i]].push_back(i - 1);
        for (auto pos : val_pos[arr[i]]) {
          if (pos >= 0 && pos < n && vis[pos] != 1) {
            travel.push_back(pos);
            vis[pos] = 1;
          }
        }
        val_pos[arr[i]].clear();
      }
    }
  }
};

int main() {
  vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
  Solution s;
  cout << s.minJumps(arr) << "\n";
  return 0;
}
