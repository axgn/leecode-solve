#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int closestTarget(vector<string> &words, string target, int startIndex) {
    int n = words.size();
    for (int i = 0; i <= n / 2; i++) {
      if (words[(startIndex + i) % n] == target) {
        return i;
      }
      if (words[(startIndex - i + n) % n] == target) {
        return i;
      }
    }
    return -1;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
