#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
