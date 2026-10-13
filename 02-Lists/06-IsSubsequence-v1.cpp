#include <iostream>
#include <queue>

bool isSubsequence(const std::string &a, const std::string &b) {
  std::queue<char> q;

  for (auto ch : a)
    q.push(ch);

  for (auto ch : b) {
    if (q.front() == ch)
      q.pop();
  }

  return q.size() == 0;
}

int main() {
  std::string a1 = "abd";
  std::string b1 = "uabqd";
  std::cout << isSubsequence(a1, b1) << std::endl;

  std::string a2 = "abd";
  std::string b2 = "uaqd";
  std::cout << isSubsequence(a2, b2) << std::endl;

  std::string a3 = "a";
  std::string b3 = "aa";
  std::cout << isSubsequence(a3, b3) << std::endl;
}
