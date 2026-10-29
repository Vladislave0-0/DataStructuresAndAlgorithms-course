#include <array>
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using Frequencies = std::array<std::size_t, 256>;

struct FrequenciesHash {
  std::size_t operator()(const Frequencies &counts) const {
    std::size_t hash = 0;
    for (std::size_t count : counts)
      hash = hash * 131 + count + 1;
    return hash;
  }
};

std::vector<std::vector<std::string>>
groupAnagrams(const std::vector<std::string> &words) {
  std::unordered_map<Frequencies, std::size_t, FrequenciesHash> groupIndex;
  std::vector<std::vector<std::string>> groups;

  for (const std::string &word : words) {
    Frequencies counts{};
    for (unsigned char ch : word)
      ++counts[ch];

    auto found = groupIndex.find(counts);
    if (found == groupIndex.end()) {
      groupIndex.emplace(counts, groups.size());
      groups.push_back({word});
    } else {
      groups[found->second].push_back(word);
    }
  }

  return groups;
}

int main() {
  std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};

  for (const auto &group : groupAnagrams(words)) {
    for (const std::string &word : group)
      std::cout << word << ' ';
    std::cout << '\n';
  }
}
