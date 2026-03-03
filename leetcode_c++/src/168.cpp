#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string convertToTitle(int columnNumber) {
    string result = "";
    do {
      int i = (--columnNumber) % 26;
      result += 'A' + i;
      columnNumber /= 26;
    } while (columnNumber > 0);
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution s;
  string s1 = s.convertToTitle(701);
  cout << s1 << "\n";
  return 0;
}
