#include <cstddef>
#include <iostream>
#include <queue>
#include <utility>
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

void mirrorTree(TreeNode *root) {
  if (!root)
    return;

  std::swap(root->left, root->right);

  mirrorTree(root->left);
  mirrorTree(root->right);
}

void printLevelOrder(const TreeNode *root) {
  if (!root)
    return;

  std::queue<const TreeNode *> nodes;
  nodes.push(root);

  while (!nodes.empty()) {
    const TreeNode *node = nodes.front();
    nodes.pop();

    std::cout << node->value << ' ';

    if (node->left)
      nodes.push(node->left);

    if (node->right)
      nodes.push(node->right);
  }

  std::cout << '\n';
}

int main() {
  TreeNode *root = buildTree({1, 2, 3, 4, 5, 6, 7});

  printLevelOrder(root);
  mirrorTree(root);
  printLevelOrder(root);

  delete root;
}
