#include <iostream>
#include <string>
#include <unordered_map>

char findExtraLetter(const std::string &a, const std::string &b) {
  std::unordered_map<char, int> counts;

  for (char ch : b)
    ++counts[ch];
  for (char ch : a)
    --counts[ch];

  for (char ch : b) {
    if (counts[ch] > 0)
      return ch;
  }

  return '\0';
}

int main() {
  std::cout << findExtraLetter("uio", "oeiu") << '\n';
  std::cout << findExtraLetter("bbb", "bbbb") << '\n';
}
