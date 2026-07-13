#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    unordered_map<int, int> pos;
    for (int i = 0; i < (int)temp.size(); i++) {
      pos[temp[i]] = i;
    }
    for (auto &i : arr) {
      i = pos[i] + 1;
    }
    return arr;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
