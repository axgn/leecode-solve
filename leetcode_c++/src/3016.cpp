#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int minimumPushes(string word) {
    int cnt[26] = {0};
    for (auto& ch : word) {
      cnt[ch - 'a']++;
    }
    
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
