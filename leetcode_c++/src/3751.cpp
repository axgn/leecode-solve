#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int totalWaviness(int num1, int num2) {
    int cnt = 0;
    for (int i = num1; i <= num2; i++) {
      int temp = i;
      int temp1 = -1, temp2 = -1, temp3 = -1;
      while (temp != 0) {
        temp3 = temp2;
        temp2 = temp1;
        temp1 = temp % 10;
        temp /= 10;
        if (temp3 == -1) {
          continue;
        }
        if ((temp1 < temp2 && temp2 > temp3) ||
            (temp1 > temp2 && temp2 < temp3)) {
          cnt++;
        }
      }
    }
    return cnt;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
