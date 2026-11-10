#include <cstddef>
#include <iostream>
#include <vector>

long long minMaxProduct(const std::vector<int> &vals) {
  if (vals.empty())
    return 0;

  std::size_t minIdx = 0;
  while (2 * minIdx + 1 < vals.size())
    minIdx = 2 * minIdx + 1;

  std::size_t maxIdx = 0;
  while (2 * maxIdx + 2 < vals.size())
    maxIdx = 2 * maxIdx + 2;

  return 1LL * vals[minIdx] * vals[maxIdx];
}

int main() {
  std::vector<int> bst = {8, 4, 12, 2, 6, 10, 14};
  std::cout << "product: " << minMaxProduct(bst) << '\n';
}
