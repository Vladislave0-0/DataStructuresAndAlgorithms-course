#include <algorithm>
#include <iostream>

long long minCopyTime(int copies, int x, int y) {
  if (copies <= 0)
    return 0;
  if (x <= 0 || y <= 0)
    return -1;

  const int firstCopy = std::min(x, y);
  const int remaining = copies - 1;
  long long left = 0;
  long long right = 1LL * remaining * firstCopy;

  while (left < right) {
    long long middle = left + (right - left) / 2;
    long long produced = middle / x + middle / y;

    if (produced >= remaining)
      right = middle;
    else
      left = middle + 1;
  }

  return firstCopy + left;
}

int main() {
  std::cout << minCopyTime(5, 1, 2) << '\n';
  std::cout << minCopyTime(1, 3, 5) << '\n';
}
