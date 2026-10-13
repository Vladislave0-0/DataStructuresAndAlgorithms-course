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

Node *removeElementByVal(Node *const head, const int val) {
  Node dummy(-1);
  dummy.next = head;

  Node *cur = head;
  Node *prev = &dummy;

  while (cur) {
    if (cur->val == val) {
      Node *removed = cur;
      cur = cur->next;
      prev->next = cur;
      delete removed;
    } else {
      prev = cur;
      cur = cur->next;
    }
  }

  return dummy.next;
}

int main() {
  std::vector<int> lens = {0, 1, 2};
  std::vector<int> vals = {0, 1, 2};

  for (auto len : lens) {
    for (auto val : vals) {
      Node *list = createList(len);
      std::cout << "before: ";
      printList(list);

      std::cout << "del = " << val << "\n" << "after: ";
      list = removeElementByVal(list, val);
      printList(list);
      deleteList(list);

      std::cout << "\n";
    }

    std::cout << "\n";
  }
}
