#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int maxDistance(vector<int> &colors) {
    int n = colors.size();
    int c1 = colors[0];
    int c2 = colors[n - 1];
    if (c1 != c2) {
      return n - 1;
    }
    int i = 1;
    while (colors[i] == c1) {
      i++;
    }
    int j = n - 2;
    while (colors[j] == c1) {
      j--;
    }
    int temp1 = n - 1 - i;
    int temp2 = j - 0;
    return temp1 > temp2 ? temp1 : temp2;
  }
};

int main() {
  Solution s;
  vector<int> colors = {1, 3, 1};
  s.maxDistance(colors);
  cout << "" << "\n";
  return 0;
}
