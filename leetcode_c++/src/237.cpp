#include "leetcode.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
class Solution {
public:
  void deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
