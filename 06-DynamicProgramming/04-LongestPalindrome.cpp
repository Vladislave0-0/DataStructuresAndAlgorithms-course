#include <iostream>
#include <string>

std::string longestPalindrome(const std::string &s) {
  std::string::size_type bestStart = 0;
  std::string::size_type bestLength = 0;

  const auto expand = [&](std::string::size_type left,
                          std::string::size_type right) {
    while (left > 0 && right < s.size() && s[left - 1] == s[right]) {
      --left;
      ++right;
    }

    const auto length = right - left;
    if (length > bestLength) {
      bestStart = left;
      bestLength = length;
    }
  };

  for (std::string::size_type i = 0; i < s.size(); ++i) {
    expand(i, i + 1);
    expand(i + 1, i + 1);
  }

  return s.substr(bestStart, bestLength);
}

int main() {
  const std::string examples[] = {"babad", "cbbd", "abcd", "abbacfgh"};

  for (const auto &s : examples)
    std::cout << s << " --> " << longestPalindrome(s) << '\n';
}
