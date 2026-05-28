#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int numberOfSpecialChars(string word) {
    unordered_set<char> set_c;
    unordered_set<char> res;
    for (auto &c : word) {
      if (islower(c) && set_c.contains(toupper(c))) {
        res.insert(c);
      }
      if (isupper(c) && set_c.contains(tolower(c))) {
        res.insert(tolower(c));
      }
      set_c.insert(c);
    }
    return res.size();
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
