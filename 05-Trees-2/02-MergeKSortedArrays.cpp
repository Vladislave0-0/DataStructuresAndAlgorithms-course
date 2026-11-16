#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>

struct HeapEntry {
  int value;
  std::size_t arrIdx;
  std::size_t elemtIdx;
};

struct GreaterValue {
  bool operator()(const HeapEntry &first, const HeapEntry &second) const {
    return first.value > second.value;
  }
};

std::vector<int>
mergeKSortedArrays(const std::vector<std::vector<int>> &arrays) {
  std::priority_queue<HeapEntry, std::vector<HeapEntry>, GreaterValue> minHeap;
  std::size_t totalElems = 0;

  for (std::size_t i = 0, end = arrays.size(); i < end; ++i) {
    totalElems += arrays[i].size();

    if (!arrays[i].empty())
      minHeap.push({arrays[i][0], i, 0});
  }

  std::vector<int> merged;
  merged.reserve(totalElems);

  while (!minHeap.empty()) {
    HeapEntry smallest = minHeap.top();
    minHeap.pop();
    merged.push_back(smallest.value);

    std::size_t nextIndex = smallest.elemtIdx + 1;
    if (nextIndex < arrays[smallest.arrIdx].size()) {
      minHeap.push(
          {arrays[smallest.arrIdx][nextIndex], smallest.arrIdx, nextIndex});
    }
  }

  return merged;
}

int main() {
  std::vector<std::vector<int>> arrays = {{1, 4, 7}, {2, 5}, {}, {3, 6, 9}};
  std::vector<int> merged = mergeKSortedArrays(arrays);

  for (int value : merged)
    std::cout << value << ' ';
  std::cout << '\n';
}
