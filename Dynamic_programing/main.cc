/*
 * demo for dynamic programming
 */
#include <iostream>
#include "dp.h"

using namespace dp_algo;


int main() {
    int n;
    std::cin >> n;
    std::vector<int> prices(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }
    DpAlgo dp_algo;
    std::cout << "max profit with one transaction: " << dp_algo.max_profit(prices) << std::endl;
    std::cout << "max profit with cooldown: " << dp_algo.max_profit_with_cooldown(prices) << std::endl;
    std::cout << "max profit with fee: " << dp_algo.max_profit_with_fee(prices, 2) << std::endl;
    return 0;
}