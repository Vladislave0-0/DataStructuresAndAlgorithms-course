#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

void printVector(const std::vector<int> &v) {
  for (int num : v)
    std::cout << num << " ";

  std::cout << std::endl;
}

void reverseArray(std::vector<int> &v, int l, int r) {
  while (l < r)
    std::swap(v[l++], v[r--]);
}

void shiftArray(std::vector<int> &v, std::size_t k) {
  if (v.empty())
    return;

  k %= v.size();
  if (k == 0)
    return;

  reverseArray(v, 0, v.size() - 1);
  reverseArray(v, 0, k - 1);
  reverseArray(v, k, v.size() - 1);
}

int main() {
  std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};

  shiftArray(v1, 3);
  printVector(v1);
}
