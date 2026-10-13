#include <iostream>

struct Node {
  int val;
  Node *next;
  Node(int v) : val(v), next(nullptr) {}
};

Node *createList(const std::initializer_list<int> &vals) {
  Node dummy(0);
  Node *tail = &dummy;
  for (int v : vals) {
    tail->next = new Node(v);
    tail = tail->next;
  }
  return dummy.next;
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

Node *mergeSortedLists(Node *head1, Node *head2) {
  Node dummy(0);
  Node *tail = &dummy;

  while (head1 && head2) {
    if (head1->val <= head2->val) {
      tail->next = head1;
      head1 = head1->next;
    } else {
      tail->next = head2;
      head2 = head2->next;
    }

    tail = tail->next;
  }

  tail->next = head1 ? head1 : head2;

  return dummy.next;
}

int main() {
  Node *list1 = createList({3, 6, 8});
  Node *list2 = createList({4, 7, 9, 11});

  std::cout << "list1: ";
  printList(list1);
  std::cout << "list2: ";
  printList(list2);

  Node *merged = mergeSortedLists(list1, list2);

  std::cout << "merged: ";
  printList(merged);
  deleteList(merged);
}
