#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graphtable(n);
    for (auto &edge : edges) {
      int start = edge.front();
      int end = edge.back();
      graphtable[start].push_back(end);
      graphtable[end].push_back(start);
    }
    vector<int> unionset;
    function<int(int)> find = [&](int value) {
      if (unionset[value] == value) {
        return value;
      }
      unionset[value] = find(unionset[value]);
      return unionset[value];
    };
    function<void(int, int)> Union = [&](int value1, int value2) {
      unionset[value1] = find(value2);
    };
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
