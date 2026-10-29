#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<std::size_t> twoSum(const std::vector<int> &numbers, int target) {
  std::unordered_map<long long, std::size_t> seen;

  for (std::size_t i = 0; i < numbers.size(); ++i) {
    long long needed = static_cast<long long>(target) - numbers[i];
    auto found = seen.find(needed);
    if (found != seen.end())
      return {found->second, i};

    seen.emplace(numbers[i], i);
  }

  return {};
}

int main() {
  std::vector<int> numbers = {3, 2, 4};
  std::vector<std::size_t> indices = twoSum(numbers, 6);

  if (indices.empty())
    std::cout << "Пара не найдена\n";
  else
    std::cout << indices[0] << ' ' << indices[1] << '\n';
}
