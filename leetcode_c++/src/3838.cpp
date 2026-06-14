#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string mapWordWeights(vector<string> &words, vector<int> &weights) {
    string res;
    for (auto &word : words) {
      int sum = 0;
      for (auto &a : word) {
        sum += weights[a - 'a'];
      }
      res.push_back('a' + (25 - (sum % 26)));
    }
    return res;
  }
};

int main() {
  vector<string> words = {"abcd", "def", "xyz"};
  vector<int> weights = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7,
                         8, 7, 10, 8,  9, 6, 9, 9, 8,  3, 7, 7, 2};
  Solution s;
  cout << s.mapWordWeights(words, weights) << "\n";
  return 0;
}
