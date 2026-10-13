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

Node *reverseLinkedList(Node *head) {
  Node *prev = nullptr;
  Node *current = head;

  while (current != nullptr) {
    Node *next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  return prev;
}

int main() {
  std::vector<int> lens = {0, 1, 2, 5};

  for (auto len : lens) {
    Node *list = createList(len);
    printList(list);
    list = reverseLinkedList(list);
    printList(list);
    deleteList(list);
  }
}
