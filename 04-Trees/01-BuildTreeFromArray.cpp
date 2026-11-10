#include <cstddef>
#include <iostream>
#include <string>
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

TreeNode *buildTree(const std::vector<int> &vals, std::size_t idx = 0) {
  if (idx >= vals.size())
    return nullptr;

  TreeNode *root = new TreeNode(vals[idx]);
  root->left = buildTree(vals, 2 * idx + 1);
  root->right = buildTree(vals, 2 * idx + 2);

  return root;
}

void printTree(const TreeNode *root, const std::string &prefix = "",
               bool isLast = true, bool isRoot = true) {
  if (!root)
    return;

  if (isRoot)
    std::cout << root->value;
  else
    std::cout << prefix << (isLast ? "└── " : "├── ") << root->value;
  std::cout << '\n';

  std::string childPrefix = prefix;
  if (!isRoot)
    childPrefix += isLast ? "    " : "│   ";

  if (root->left && root->right) {
    printTree(root->left, childPrefix, false, false);
    printTree(root->right, childPrefix, true, false);
  } else if (root->left) {
    printTree(root->left, childPrefix, true, false);
  } else if (root->right) {
    printTree(root->right, childPrefix, true, false);
  }
}

int main() {
  std::vector<int> vals = {8, 9, 11, 7, 16, 3, 1};
  TreeNode *root = buildTree(vals);

  printTree(root);

  delete root;
}
