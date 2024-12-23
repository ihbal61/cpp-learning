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
    * Leetcode: 746
    * Algorithm complexity: O(n)
    * Space complexity: O(1)
    */
    int DpAlgo::min_cost_climbing_stairs(std::vector<int>& cost) {
        int n = cost.size();
        for (int i = 2; i < n; i++) {
            cost[i] += std::min(cost[i - 1], cost[i - 2]);
        }
        return std::min(cost[n - 1], cost[n - 2]);
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

    /*
    * Leetcode: 64
    * Algorithm complexity: O(m*n)
    * Space complexity: O(m*n)
    */
    int DpAlgo::min_path_sum(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }

    /*
    * Leetcode: 931
    * Algorithm complexity: O(m*n)
    * Space complexity: O(1)
    */
    int DpAlgo::min_falling_path_sum(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    grid[i][j] += std::min(grid[i - 1][j], grid[i - 1][j + 1]);
                } else if (j == n - 1) {
                    grid[i][j] += std::min(grid[i - 1][j], grid[i - 1][j - 1]);
                } else {
                    grid[i][j] += std::min(grid[i - 1][j], std::min(grid[i - 1][j - 1], grid[i - 1][j + 1]));
                }
            }
        }
        return *std::min_element(grid[m - 1].begin(), grid[m - 1].end());
    }

    /*
    * Leetcode: 120
    * Algorithm complexity: O(n^2)
    * Space complexity: O(1)
    */
    int DpAlgo::min_path_sum_triangle(std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; i++) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
        }
        for (int i = 2; i < n; i++) {
            for (int j = 1; j < i; j++) {
                triangle[i][j] += std::min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
        }
        return *std::min_element(triangle[n - 1].begin(), triangle[n - 1].end());
    }

    /*
    * Leetcode: 740
    * Algorithm complexity: O(n)
    * Space complexity: O(n)
    */
    int DpAlgo::delete_and_earn(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int max_val = *std::max_element(nums.begin(), nums.end());
        std::vector<int> sum(max_val + 1, 0);
        for (int i = 0; i < n; i++) {
            sum[nums[i]] += nums[i];
        }
        std::vector<int> dp(max_val + 1, 0);
        dp[1] = sum[1];
        for (int i = 2; i <= max_val; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + sum[i]);
        }
        return dp[max_val];
    }

    /*
    * Leetcode: 198
    * Algorithm complexity: O(n)
    * Space complexity: O(1)
    */
    int DpAlgo::rob(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        int first = nums[0], second = std::max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int temp = second;
            second = std::max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    /*
    * Leetcode: 213
    * Algorithm complexity: O(n)
    * Space complexity: O(1)
    */
    int DpAlgo::rob_2(std::vector<int>& nums) {
        // non recusive
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        int first = nums[0], second = std::max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            int temp = second;
            second = std::max(first + nums[i], second);
            first = temp;
        }
        int max_val = second;
        first = 0, second = nums[1];
        for (int i = 2; i < n; i++) {
            int temp = second;
            second = std::max(first + nums[i], second);
            first = temp;
        }
        return std::max(max_val, second);
    }

    /*
    * Leetcode: 337
    * Algorithm complexity: O(n)
    * Space complexity: O(1)
    */
    int DpAlgo::rob_3(TreeNode* root) {
        std::vector<int> res = rob_helper(root);
        return std::max(res[0], res[1]);
    }

    std::vector<int> DpAlgo::rob_helper(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        std::vector<int> left = rob_helper(root -> left);
        std::vector<int> right = rob_helper(root -> right);
        int rob = root -> val + left[0] + right[0];
        int not_rob = std::max(left[0], left[1]) + std::max(right[0], right[1]);
        return {not_rob, rob};
    }

    /*
    * Leetcode: 1137
    * Algorithm complexity: O(n)
    * Space complexity: O(1)
    */
    int DpAlgo::tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        int a = 0, b = 1, c = 1, d;
        for (int i = 3; i <= n; i++) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }

    /*
    * Leetcode: 62
    * Algorithm complexity: O(m*n)
    * Space complexity: O(m*n)
    */
    int DpAlgo::unique_paths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    /*
    * Leetcode: 63
    * Algorithm complexity: O(m*n)
    * Space complexity: O(m*n)
    */
    int DpAlgo::unique_paths_with_obstacles(std::vector<std::vector<int>>& obstacle_grid) {
        int m = obstacle_grid.size(), n = obstacle_grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        for (int i = 0; i < m && obstacle_grid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n && obstacle_grid[0][j] == 0; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacle_grid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }

    /*
    * Leetcode: 221
    * Algorithm complexity: O(m*n)
    * Space complexity: O(m*n)
    */
    int DpAlgo::maximal_square(std::vector<std::vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        int max_side = 0;
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            max_side = std::max(max_side, dp[i][0]);
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] - '0';
            max_side = std::max(max_side, dp[0][j]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    max_side = std::max(max_side, dp[i][j]);
                }
            }
        }
        return max_side * max_side;
    }

    /*
    * Leetcode: 409
    * Algorithm complexity: O(n^2)
    * Space complexity: O(n^2)
    */
    std::string DpAlgo::longest_palindrome(std::string s) {
        int n = s.size();
        if (n == 0) return "";

        // dp[i][j] 表示 s[i..j] 是否是回文
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        int start = 0, max_length = 1;

        // 所有长度为1的子串都是回文
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // 检查长度为2的子串
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                max_length = 2;
            }
        }

        // 检查长度大于2的子串
        for (int length = 3; length <= n; ++length) {
            for (int i = 0; i < n - length + 1; ++i) {
                int j = i + length - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    max_length = length;
                }
            }
        }

        return s.substr(start, max_length);
    }
    
    
}; // namespace dp_algo