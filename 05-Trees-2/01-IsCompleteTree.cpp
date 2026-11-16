#include <cstddef>
#include <iostream>
#include <optional>
#include <queue>
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

TreeNode *buildTree(const std::vector<std::optional<int>> &values,
                    std::size_t index = 0) {
  if (index >= values.size() || !values[index])
    return nullptr;

  TreeNode *root = new TreeNode(*values[index]);
  root->left = buildTree(values, 2 * index + 1);
  root->right = buildTree(values, 2 * index + 2);
  return root;
}

bool isCompleteTree(const TreeNode *root) {
  if (!root)
    return true;

  std::queue<const TreeNode *> nodes;
  nodes.push(root);
  bool foundMissingChild = false;

  while (!nodes.empty()) {
    const TreeNode *node = nodes.front();
    nodes.pop();

    if (node->left) {
      if (foundMissingChild)
        return false;
      nodes.push(node->left);
    } else {
      foundMissingChild = true;
    }

    if (node->right) {
      if (foundMissingChild)
        return false;
      nodes.push(node->right);
    } else {
      foundMissingChild = true;
    }
  }

  return true;
}

int main() {
  TreeNode *tree1 = buildTree({1, 2, 3, 4, 5, 6});
  TreeNode *tree2 = buildTree({1, 2, 3, 4, std::nullopt, 6});

  std::cout << isCompleteTree(tree1) << '\n';
  std::cout << isCompleteTree(tree2) << '\n';

  delete tree1;
  delete tree2;
}
