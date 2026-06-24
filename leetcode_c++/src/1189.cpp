#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> text_map;
    for (auto &ch : text) {
      text_map[ch]++;
    }
    return min({text_map['b'], text_map['a'], text_map['l'] / 2,
                text_map['o'] / 2, text_map['n']});
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
