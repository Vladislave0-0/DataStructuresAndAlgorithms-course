#include <cstddef>
#include <functional>
#include <iostream>
#include <optional>
#include <queue>
#include <vector>

std::optional<int> kthSmallest(const std::vector<int> &values, std::size_t k) {
  if (k == 0 || k > values.size())
    return std::nullopt;

  std::priority_queue<int> largestOfSmallest;
  for (int value : values) {
    if (largestOfSmallest.size() < k) {
      largestOfSmallest.push(value);
    } else if (value < largestOfSmallest.top()) {
      largestOfSmallest.pop();
      largestOfSmallest.push(value);
    }
  }

  return largestOfSmallest.top();
}

std::optional<int> kthLargest(const std::vector<int> &values, std::size_t k) {
  if (k == 0 || k > values.size())
    return std::nullopt;

  std::priority_queue<int, std::vector<int>, std::greater<int>>
      smallestOfLargest;
  for (int value : values) {
    if (smallestOfLargest.size() < k) {
      smallestOfLargest.push(value);
    } else if (value > smallestOfLargest.top()) {
      smallestOfLargest.pop();
      smallestOfLargest.push(value);
    }
  }

  return smallestOfLargest.top();
}

int main() {
  std::vector<int> values = {7, 4, 6, 3, 9, 1};
  
  std::size_t k = 2;
  std::optional<int> smallest = kthSmallest(values, k);
  std::optional<int> largest = kthLargest(values, k);

  if (smallest && largest) {
    std::cout << k << "-й наименьший: " << *smallest << '\n';
    std::cout << k << "-й наибольший: " << *largest << '\n';
  }
}
