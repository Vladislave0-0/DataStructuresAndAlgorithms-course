#include <iostream>
#include <vector>

struct Node {
  int val;
  Node *next;
  Node(int v) : val(v), next(nullptr) {}
};

Node *createList(int length) {
  Node *head = nullptr;
  Node **tail = &head;

  for (int i = 0; i < length; ++i) {
    *tail = new Node(i + 1);
    tail = &((*tail)->next);
  }

  return head;
}

void deleteList(Node *head) {
  while (head) {
    Node *next = head->next;
    delete head;
    head = next;
  }
}

void printList(const Node *head) {
  while (head) {
    std::cout << head->val;
    head = head->next;

    if (head)
      std::cout << ' ';
  }

  std::cout << '\n';
}

Node *middleNode(Node *const head) {
  Node *slow = head;
  Node *fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

int main() {
  std::vector<int> lens = {0, 1, 2, 5, 10};

  for (auto len : lens) {
    Node *list = createList(len);
    std::cout << "list: ";
    printList(list);

    std::cout << "middle: ";
    Node *mid = middleNode(list);
    std::cout << (mid ? mid->val : -1) << "\n\n";
    deleteList(list);
  }
}
