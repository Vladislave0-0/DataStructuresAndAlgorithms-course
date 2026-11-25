#include <iostream>
#include <limits>
#include <vector>

int coinChange(std::vector<std::size_t> coins, std::size_t amount) {
  if (amount < 0)
    return -1;

  const auto inf = std::numeric_limits<std::size_t>::max();
  std::vector<std::size_t> dp(amount + 1, inf);
  dp[0] = 0;

  for (int i = 1; i <= amount; ++i) {
    for (std::size_t coin : coins) {
      if (coin <= i && dp[i - coin] != inf)
        dp[i] = std::min(dp[i], dp[i - coin] + 1);
    }
  }

  if (dp[amount] == inf)
    return -1;

  return static_cast<int>(dp[amount]);
}

int main() {
  std::vector<std::size_t> coins = {1, 2, 5};
  int max = 10;

  for (int amount = 1; amount <= max; ++amount) {
    std::cout << "Для amount = " << amount << " нужно "
              << coinChange(coins, amount) << " монет" << '\n';
  }
}
