#include <iostream>
#include <string>

bool isSubsequence(const std::string &a, const std::string &b) {
  std::string::size_type i = 0;
  std::string::size_type j = 0;

  while (i < a.length() && j < b.length()) {
    if (a[i] == b[j])
      ++i;

    ++j;
  }

  return i == a.length();
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
