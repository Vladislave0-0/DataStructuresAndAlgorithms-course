#include <cstddef>
#include <iostream>
#include <optional>
#include <stack>
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

std::optional<int> kthSmallest(const TreeNode *root, std::size_t k) {
  if (k == 0)
    return std::nullopt;

  std::stack<const TreeNode *> nodes;
  const TreeNode *current = root;

  while (current || !nodes.empty()) {
    while (current) {
      nodes.push(current);
      current = current->left;
    }

    current = nodes.top();
    nodes.pop();
    if (--k == 0)
      return current->value;
    
    current = current->right;
  }

  return std::nullopt;
}

std::optional<int> kthLargest(const TreeNode *root, std::size_t k) {
  if (k == 0)
    return std::nullopt;

  std::stack<const TreeNode *> nodes;
  const TreeNode *current = root;

  while (current || !nodes.empty()) {
    while (current) {
      nodes.push(current);
      current = current->right;
    }

    current = nodes.top();
    nodes.pop();
    if (--k == 0)
      return current->value;
    current = current->left;
  }

  return std::nullopt;
}

int main() {
  TreeNode *bst = buildTree({8, 4, 12, 2, 6, 10, 14});
  std::optional<int> smallest = kthSmallest(bst, 3);
  std::optional<int> largest = kthLargest(bst, 2);

  if (smallest && largest) {
    std::cout << "3-й наименьший: " << *smallest << '\n';
    std::cout << "2-й наибольший: " << *largest << '\n';
  }

  delete bst;
}
