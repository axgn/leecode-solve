#include "leetcode.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    bool is_odd = false;
    ListNode *head2 = new ListNode(0);
    ListNode *temp2 = head2;
    ListNode *temp = head;
    while (temp->next != nullptr) {
      if (is_odd) {
        temp = temp->next;
      } else {
        head2->next = temp->next;
        temp->next = temp->next->next;
        head2 = head2->next;
      }
      is_odd = !is_odd;
    }
    temp->next = temp2->next;
    head2->next = nullptr;
    return head;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
