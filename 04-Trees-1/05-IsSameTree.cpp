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

bool isSameTree(const TreeNode *first, const TreeNode *second) {
  if (!first || !second)
    return first == second;

  return first->value == second->value &&
         isSameTree(first->left, second->left) &&
         isSameTree(first->right, second->right);
}

int main() {
  TreeNode *tree = buildTree({1, 2, 3, 4});
  TreeNode *tree_cmp1 = buildTree({1, 2, 3, 4});
  TreeNode *tree_cmp2 = buildTree({1, 2, 3});
  TreeNode *tree_cmp3 = buildTree({1, 2, 3, 5});

  std::cout << isSameTree(tree, tree_cmp1) << '\n';
  std::cout << isSameTree(tree, tree_cmp2) << '\n';
  std::cout << isSameTree(tree, tree_cmp3) << '\n';

  delete tree;
  delete tree_cmp1;
  delete tree_cmp2;
  delete tree_cmp3;
}
