#include <initializer_list>
#include <iostream>

int integerSqrt(int number) {
  if (number < 0)
    return -1;

  int left = 0;
  int right = number;
  int answer = 0;

  while (left <= right) {
    int middle = left + (right - left) / 2;
    long long square = 1LL * middle * middle;

    if (square <= number) {
      answer = middle;
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }

  return answer;
}

int main() {
  for (int number : {0, 1, 8, 16, 27})
    std::cout << "sqrt(" << number << ") = " << integerSqrt(number) << '\n';
}
