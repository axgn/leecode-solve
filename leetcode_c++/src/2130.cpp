#include "leetcode.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int pairSum(ListNode *head) {
    int cnt = 0;
    ListNode *temp = head;
    vector<int> v(100000);
    while (temp) {
      v[cnt] = temp->val;
      temp = temp->next;
      cnt++;
    }
    int max = INT_MIN;
    for (int i = 0; i < cnt / 2; i++) {
      int sum = v[i] + v[cnt - i - 1];
      if (sum > max) {
        max = sum;
      }
    }
    return max;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
