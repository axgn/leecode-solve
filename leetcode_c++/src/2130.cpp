#include "leetcode.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution2 {
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

class Solution {
public:
  ListNode *findmidnode(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  ListNode *reverselist(ListNode *head) {
    ListNode *temp = nullptr;
    while (head) {
      ListNode *temp1 = head->next;
      head->next = temp;
      temp = head;
      head = temp1;
    }
    return temp;
  }
  ListNode *reverselist(ListNode *head, int left, int right) {
    int cnt = 0;
    ListNode *dummy = new ListNode(0, head);
    ListNode *cur = dummy;
    while (cur && cnt < left - 1) {
      cnt++;
      cur = cur->next;
    }
    ListNode *parent = cur;
    cur = cur->next;
    ListNode *temp = cur;
    cnt++;
    ListNode *prev = nullptr;
    while (cur && cnt < right - 1) {
      ListNode *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
      cnt++;
    }
    temp->next = cur;
    parent->next = prev;
    return dummy->next;
  }
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    int cnt = 0;
    ListNode *dummy = new ListNode(0, head);
    ListNode *cur = dummy;
    while (cur && cnt < left - 1) {
      cnt++;
      cur = cur->next;
    }
    ListNode *parent = cur;
    cur = cur->next;
    ListNode *temp = cur;
    cnt++;
    ListNode *prev = nullptr;
    while (cur && cnt <= right) {
      ListNode *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
      cnt++;
    }
    temp->next = cur;
    parent->next = prev;
    return dummy->next;
  }
  ListNode *reverselist(ListNode *head, ListNode *left, ListNode *right) {
    ListNode *temp = nullptr;
    while (head) {
      ListNode *temp1 = head->next;
      head->next = temp;
      temp = head;
      head = temp1;
    }
    return temp;
  }

  int pairSum(ListNode *head) {
    int max = INT_MIN;
    ListNode *mid = findmidnode(head);
    ListNode *node1 = reverselist(mid);
    ListNode *node2 = head;
    while (node1) {
      int val = node1->val + node2->val;
      if (val > max) {
        max = val;
      }
      node1 = node1->next;
      node2 = node2->next;
    }
    return max;
  }
};

int main() {
  Solution s;
  ListNode head(
      1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  s.reverseBetween(&head, 2, 4);
  cout << "" << "\n";
  return 0;
}
