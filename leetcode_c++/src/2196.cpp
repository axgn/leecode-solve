#include "leetcode.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> node_map;
    unordered_map<int, int> flag_map;
    for (auto &item : descriptions) {
      int parent = item[0];
      int child = item[1];
      int isLeft = item[2];
      TreeNode *tree_child, *tree_parent;
      if (!node_map.contains(child)) {
        tree_child = new TreeNode(child);
        node_map[child] = tree_child;
        flag_map[child] = 0;
      } else {
        tree_child = node_map[child];
        flag_map[child] = 0;
      }
      if (!node_map.contains(parent)) {
        tree_parent = new TreeNode(parent);
        node_map[parent] = tree_parent;
        flag_map[parent] = 1;
      } else {
        tree_parent = node_map[parent];
      }
      if (isLeft) {
        tree_parent->left = tree_child;
      } else {
        tree_parent->right = tree_child;
      }
    }
    for (auto &kv : flag_map) {
      if (kv.second == 1) {
        return node_map[kv.first];
      }
    }
    return nullptr;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
