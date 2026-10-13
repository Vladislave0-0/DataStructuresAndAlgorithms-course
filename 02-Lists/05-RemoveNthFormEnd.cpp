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

Node *removeNthFormEnd(Node *const head, const int N) {
  if (!head || N <= 0)
    return head;

  Node dummy(-1);
  dummy.next = head;

  Node *slow = &dummy;
  Node *fast = &dummy;

  for (int i = 0; i < N; ++i) {
    if (!fast->next)
      return head;

    fast = fast->next;
  }

  while (fast->next) {
    slow = slow->next;
    fast = fast->next;
  }

  Node *removed = slow->next;
  slow->next = removed->next;
  delete removed;

  return dummy.next;
}

int main() {
  std::vector<int> lens = {0, 1, 2, 5};
  std::vector<int> Ns = {1, 2, 10};

  for (auto len : lens) {
    for (auto N : Ns) {
      Node *list = createList(len);
      std::cout << "before: ";
      printList(list);

      std::cout << "N = " << N << "\n" << "after: ";
      list = removeNthFormEnd(list, N);
      printList(list);
      deleteList(list);

      std::cout << "\n";
    }

    std::cout << "\n";
  }
}
