#include <deque>
#include <iostream>

bool isPalindrome(const std::string &str) {
  std::deque<char> d;

  for (auto ch : str)
    d.push_back(ch);

  while (d.size() > 1) {
    if (d.back() != d.front())
      return false;

    d.pop_back();
    d.pop_front();
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
