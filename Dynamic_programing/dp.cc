/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2024-12-23 14:28
 * @author: yikebaer·aizezi
 * @file: dp.cc
 * @brief: dp algorithm
*/
#include "dp.h"

namespace dp_algo {
    // 构造函数定义
    DpAlgo::DpAlgo() {
        // 构造函数的实现逻辑
    }

    // 析构函数定义
    DpAlgo::~DpAlgo() {
        // 析构函数的实现逻辑
    }
    /*
    * Leetcode: 126
    * Algorithm complexity: O(n)
    * Space complexity: O(1)
    */
    int DpAlgo::fibonacci(int n) {
        if (n <= 1) {
            return n;
        }
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

    /*
    * Leetcode: 70
    * Algorithm complexity: O(n)
    * Space complexity: O(1)
    */
    int DpAlgo::climb_stairs(int n) {
        if (n <= 2) {
            return n;
        }
        int a = 1, b = 2, c;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

    /*
    * Leetcode: 121
    * Algorithm complexity: O(n)
    * Space complexity: O(1)
    */
    int DpAlgo::max_profit(std::vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        int min_price = prices[0], max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            max_profit = std::max(max_profit, prices[i] - min_price);
            min_price = std::min(min_price, prices[i]);
        }
        return max_profit;
    }

    /*
    * Leetcode: 309
    * Algorithm complexity: O(n)
    * Space complexity: O(1)
    */
    int DpAlgo::max_profit_with_cooldown(std::vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        int buy = -prices[0], sell = 0, cooldown = 0;
        for (int i = 1; i < n; i++) {
            int prev_buy = buy;
            buy = std::max(buy, cooldown - prices[i]);
            cooldown = sell;
            sell = std::max(sell, prev_buy + prices[i]);
        }
        return sell;
    }

    /*
    * Leetcode: 714
    * Algorithm complexity: O(n)
    * Space complexity: O(1)
    */
    int DpAlgo::max_profit_with_fee(std::vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        int buy = -prices[0], sell = 0;
        for (int i = 1; i < n; i++) {
            buy = std::max(buy, sell - prices[i]);
            sell = std::max(sell, buy + prices[i] - fee);
        }
        return sell;
    }

    /*
    * Leetcode: 188
    * Algorithm complexity: O(nk)
    * Space complexity: O(k)
    */
    int DpAlgo::max_profit_with_k_transaction(std::vector<int>& prices, int k) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        if (k >= n / 2) {
            int max_profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    max_profit += prices[i] - prices[i - 1];
                }
            }
            return max_profit;
        }
        std::vector<int> buy(k, INT_MIN), sell(k, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                buy[j] = std::max(buy[j], j == 0 ? -prices[i] : sell[j - 1] - prices[i]);
                sell[j] = std::max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k - 1];
    }

    /*
    * Leetcode: 123
    * Algorithm complexity: O(n)
    * Space complexity: O(1)
    */
    int DpAlgo::max_profit_with_2_transaction(std::vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        int buy1 = -prices[0], sell1 = 0, buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; i++) {
            buy1 = std::max(buy1, -prices[i]);
            sell1 = std::max(sell1, buy1 + prices[i]);
            buy2 = std::max(buy2, sell1 - prices[i]);
            sell2 = std::max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }

}; // namespace dp_algo