#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:
  string generateString(string str1, string str2) {
    int n1 = str1.length(), n2 = str2.length();
    int n3 = n1 + n2 - 1;
    string res(n3, 0);
    for (int i = 0; i < n1; i++) {
      if (str1[i] != 'T') {
        continue;
      }
      for (int j = 0; j < n2; j++) {
        char v = res[i + j];
        if (v != 0 && v != str2[j]) {
          return "";
        }
        res[i + j] = str2[j];
      }
    }
    string old_res = res;
    for (int i = 0; i < n3; i++) {
      if (res[i] == 0) {
        res[i] = 'a';
      }
    }
    for (int i = 0; i < n1; i++) {
      if (str1[i] != 'F') {
        continue;
      }
      if (string(res.begin() + i, res.begin() + i + n2) != str2) {
        continue;
      }
      bool ok = false;
      for (int j = i + n2 - 1; j >= i; j--) {
        if (old_res[j] == 0) {
          res[j] = 'b';
          ok = true;
          break;
        }
      }
      if (!ok) {
        return "";
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  cout << s.generateString("TFTF", "ab") << "\n";
  return 0;
}
