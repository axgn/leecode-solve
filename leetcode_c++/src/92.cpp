#include "leetcode.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    int cnt = 0;
    ListNode *temp = head;
    ListNode *headNode = new ListNode(-1, head);
    ListNode *tailNode = new ListNode(-1, nullptr);
    ListNode *begin = nullptr, *end = nullptr;
    while (temp->next != nullptr) {
      if (cnt == right) {
        end = temp;
      }
      cnt++;
      if (cnt == left) {
        begin = temp;
      }

      temp = temp->next;
    }
    return head;
  }
};

using namespace std;

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
