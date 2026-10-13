#include <iostream>
#include <stack>

bool isPalindrome(const std::string &str) {
  std::stack<char> s;

  for (auto ch : str)
    s.push(ch);

  for (auto ch : str) {
    if (ch != s.top())
      return false;

    s.pop();
  }

  return true;
}

int main() {
  std::string str1 = "a";
  std::cout << isPalindrome(str1) << std::endl;

  std::string str2 = "abba";
  std::cout << isPalindrome(str2) << std::endl;

  std::string str3 = "allla";
  std::cout << isPalindrome(str3) << std::endl;

  std::string str4 = "abcde";
  std::cout << isPalindrome(str4) << std::endl;
}
