#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

struct TreeNode {
  int value;
  int balance_factor;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int v)
      : value(v), balance_factor(0), left(nullptr), right(nullptr) {}

  TreeNode(const TreeNode &) = delete;
  TreeNode &operator=(const TreeNode &) = delete;

  ~TreeNode() {
    delete left;
    delete right;
  }
};

TreeNode *buildTree(const std::vector<int> &values, std::size_t index = 0) {
  if (index >= values.size())
    return nullptr;

  TreeNode *root = new TreeNode(values[index]);
  root->left = buildTree(values, 2 * index + 1);
  root->right = buildTree(values, 2 * index + 2);
  return root;
}

int fillBalanceFactors(TreeNode *root) {
  if (!root)
    return 0;

  int leftHeight = fillBalanceFactors(root->left);
  int rightHeight = fillBalanceFactors(root->right);
  root->balance_factor = leftHeight - rightHeight;
  return 1 + std::max(leftHeight, rightHeight);
}

void printBalanceFactors(const TreeNode *root) {
  if (!root)
    return;

  printBalanceFactors(root->left);
  std::cout << root->value << ": " << root->balance_factor << '\n';
  printBalanceFactors(root->right);
}

int main() {
  TreeNode *root = buildTree({8, 4, 12, 2, 6, 10, 14});
  fillBalanceFactors(root);
  printBalanceFactors(root);
  delete root;
}
