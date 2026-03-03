#include <deque>
#include <iostream>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode()
      : val(0), left(nullptr), right(nullptr){} * TreeNode(int x)
      : val(x),
        left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// 用智能指针交换值。(不需要用智能指针，容器交换天然O(1))
class Solution {
public:
  int maxLevelSum(TreeNode *root) {
    int max = root->val;
    int max_idx = 1;
    deque<TreeNode *> temp;
    deque<TreeNode *> temp_next;
    temp.push_back(root);
    int idx = 0;
    while (temp.size() > 0) {
      int value = 0;
      idx += 1;
      while (!temp.empty()) {
        TreeNode *temp_node = temp.front();
        value += temp_node->val;
        if (temp_node->left) {
          temp_next.push_back(temp_node->left);
        }
        if (temp_node->right) {
          temp_next.push_back(temp_node->right);
        }
        temp.pop_front();
      }
      if (value > max) {
        max = value;
        max_idx = idx;
      }
      temp.swap(temp_next);
    }

    return max_idx;
  }
};

int main() {
  Solution s;
  TreeNode root;
  cout << s.maxLevelSum(&root) << "\n";
  return 0;
}
