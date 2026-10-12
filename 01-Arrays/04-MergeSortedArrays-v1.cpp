#include <cstddef>
#include <iostream>
#include <vector>

void printVector(const std::vector<int> &v) {
  for (int num : v)
    std::cout << num << " ";

  std::cout << std::endl;
}

std::vector<int> mergeSortedArrays(const std::vector<int> &v1,
                                   const std::vector<int> &v2) {
  std::size_t i = 0;
  std::size_t j = 0;

  std::vector<int> v;
  v.reserve(v1.size() + v2.size());

  while (i < v1.size() && j < v2.size()) {
    if (v1[i] < v2[j]) {
      v.push_back(v1[i++]);
    } else {
      v.push_back(v2[j++]);
    }
  }

  while (i < v1.size())
    v.push_back(v1[i++]);

  while (j < v2.size())
    v.push_back(v2[j++]);

  return v;
}

int main() {
  std::vector<int> v1 = {1, 4, 5, 7};
  std::vector<int> v2 = {1, 2, 3, 6, 9};

  std::vector<int> v = mergeSortedArrays(v1, v2);
  printVector(v);
}
