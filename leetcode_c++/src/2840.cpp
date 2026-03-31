#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkStrings(string s1, string s2) {
    unordered_map<char, int> count_s11, count_s12;
    unordered_map<char, int> count_s21, count_s22;
    for (int i = 0; i < s1.length(); i++) {
      if (i % 2 == 1) {
        count_s11[s1[i]]++;
      } else {
        count_s12[s1[i]]++;
      }
    }
    for (int i = 0; i < s2.length(); i++) {
      if (i % 2 == 1) {
        count_s21[s2[i]]++;
      } else {
        count_s22[s2[i]]++;
      }
    }
    return count_s11 == count_s21 && count_s12 == count_s22;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
