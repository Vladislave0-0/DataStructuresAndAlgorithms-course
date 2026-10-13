#include <iostream>
#include <stack>
#include <vector>

std::stack<int> sortArrayUsingStack(std::vector<int> arr) {
  std::stack<int> s;

  while (!arr.empty()) {
    int current = arr.back();
    arr.pop_back();

    while (!s.empty() && s.top() > current) {
      arr.push_back(s.top());
      s.pop();
    }

    s.push(current);
  }

  return s;
}

int main() {
  std::vector<int> v = {5, 1, 4, 2, 8, 3};

  std::cout << "before: ";
  for (int x : v)
    std::cout << x << " ";
  std::cout << std::endl;

  std::stack<int> sortedStack = sortArrayUsingStack(v);

  std::cout << "after: ";
  while (!sortedStack.empty()) {
    std::cout << sortedStack.top() << " ";
    sortedStack.pop();
  }
  std::cout << std::endl;
}