#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

std::size_t feedAnimals(std::vector<int> animals, std::vector<int> food) {
  std::sort(animals.begin(), animals.end());
  std::sort(food.begin(), food.end());

  std::size_t fed = 0;
  for (int portion : food) {
    if (fed < animals.size() && portion >= animals[fed])
      ++fed;
  }

  return fed;
}

int main() {
  std::vector<int> animals = {8, 2, 3, 2};
  std::vector<int> food = {1, 4, 3, 8};
  std::cout << feedAnimals(animals, food) << '\n';
}
