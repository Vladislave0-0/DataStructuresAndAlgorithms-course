#include <iostream>
#include <vector>

void printVector(const std::vector<int> &v) {
  for (int num : v)
    std::cout << num << " ";

  std::cout << std::endl;
}

void mergeSortedArrays(std::vector<int> &v1, const std::vector<int> &v2) {
  int p1 = static_cast<int>(v1.size()) - static_cast<int>(v2.size()) - 1;
  int p2 = static_cast<int>(v2.size()) - 1;
  int p3 = static_cast<int>(v1.size()) - 1;

  while (p1 >= 0 && p2 >= 0) {
    if (v1[p1] > v2[p2]) {
      v1[p3--] = v1[p1--];
    } else {
      v1[p3--] = v2[p2--];
    }
  }

  while (p2 >= 0)
    v1[p3--] = v2[p2--];
}

int main() {
  std::vector<int> v1 = {1, 4, 5, 7, 0, 0, 0, 0, 0};
  std::vector<int> v2 = {1, 2, 3, 6, 9};
  mergeSortedArrays(v1, v2);
  printVector(v1);

  std::vector<int> v3 = {8, 9, 0, 0, 0, 0, 0};
  std::vector<int> v4 = {1, 2, 3, 4, 5};
  mergeSortedArrays(v3, v4);
  printVector(v3);
}
