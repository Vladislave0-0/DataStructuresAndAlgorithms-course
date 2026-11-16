#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}

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

std::size_t minDepth(const TreeNode *root) {
  if (!root)
    return 0;

  if (!root->left && !root->right)
    return 1;

  if (root->left && root->right)
    return 1 + std::min(minDepth(root->left), minDepth(root->right));

  if (root->left)
    return 1 + minDepth(root->left);

  return 1 + minDepth(root->right);
}

int main() {
  TreeNode *root = buildTree({8, 9, 11, 7, 16, 3, 1});
  std::cout << "min depth: " << minDepth(root) << '\n';
  delete root;
}
