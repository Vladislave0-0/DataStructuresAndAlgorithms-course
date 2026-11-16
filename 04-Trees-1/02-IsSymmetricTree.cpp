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

bool isMirror(const TreeNode *left, const TreeNode *right) {
  if (!left || !right)
    return left == right;

  return left->value == right->value && isMirror(left->left, right->right) &&
         isMirror(left->right, right->left);
}

bool isSymmetric(const TreeNode *root) {
  return !root || isMirror(root->left, root->right);
}

int main() {
  TreeNode *tree1 = buildTree({1, 2, 2, 3, 4, 4, 3});
  std::cout << "Дерево " << (isSymmetric(tree1) ? "" : "не") << "симметрично\n";
  delete tree1;

  TreeNode *tree2 = buildTree({1, 2, 3});
  std::cout << "Дерево " << (isSymmetric(tree2) ? "" : "не") << "симметрично\n";
  delete tree2;
}
