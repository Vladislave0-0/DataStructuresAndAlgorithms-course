#include <iostream>
#include <vector>

std::size_t findLIS(const std::vector<int> &nums) {
  if (nums.empty())
    return 0;

  std::size_t current = 1;
  std::size_t max = 1;

  for (std::size_t i = 1, end = nums.size(); i < end; ++i) {
    if (nums[i - 1] < nums[i])
      ++current;
    else
      current = 1;

    max = std::max(max, current);
  }

  return max;
}
int main() {
  std::vector<int> nums = {3, 1, 4, 7, 2, 11, 9};
  std::cout << findLIS(nums) << std::endl;
}
