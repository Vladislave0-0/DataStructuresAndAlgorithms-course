#include <iostream>
#include <vector>

std::vector<std::vector<std::size_t>> pascalTriangle(std::size_t n) {
  std::vector<std::vector<std::size_t>> triangle;

  for (std::size_t i = 0; i < n; ++i) {
    auto &row = triangle.emplace_back(i + 1, 1);

    for (std::size_t j = 1; j < i; ++j) {
      const auto &prev = triangle[i - 1];
      row[j] = prev[j - 1] + prev[j];
    }
  }

  return triangle;
}

int main() {
  for (const auto &row : pascalTriangle(5)) {
    for (std::size_t j = 0; j < row.size(); ++j) {
      if (j > 0)
        std::cout << ' ';

      std::cout << row[j];
    }

    std::cout << '\n';
  }
}
