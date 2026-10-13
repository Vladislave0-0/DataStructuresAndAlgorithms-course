#include <iostream>
#include <string>

bool isPalindrome(const std::string &str) {
  std::string::size_type left = 0;
  std::string::size_type right = str.size();

  while (left < right) {
    --right;
    if (str[left] != str[right])
      return false;
    ++left;
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
