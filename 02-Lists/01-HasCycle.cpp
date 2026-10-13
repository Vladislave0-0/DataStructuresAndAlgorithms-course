#include <iostream>

struct Node {
  int val;
  Node *next;
  Node(int v) : val(v), next(nullptr) {}
};

Node *createCyclicList() {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n3;

  return n1;
}

Node *createLinearList() {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = nullptr;

  return n1;
}

bool hasCycle(Node *const head) {
  if (!head || !head->next)
    return false;

  Node *slow = head;
  Node *fast = head->next;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
      return true;
  }

  return false;
}

int main() {
  std::cout << (hasCycle(createCyclicList()) ? "В спике есть цикл"
                                             : "В спике нет цикла")
            << std::endl;

  std::cout << (hasCycle(createLinearList()) ? "В спике есть цикл"
                                             : "В спике нет цикла")
            << std::endl;
}
