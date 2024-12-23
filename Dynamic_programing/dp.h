/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2024-12-23 14:28
 * @author: yikebaer·aizezi
 * @file: dp.h
 * @brief: dp algorithm
*/
#ifndef DP_H
#define DP_H
#endif // DP_H

#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include "../Data_structures/TreeNode/TreeNode.h"

namespace dp_algo {

using namespace tree_algo;

class DpAlgo {
public:
    DpAlgo();
    ~DpAlgo();
public:
    int fibonacci(int n);
    int climb_stairs(int n);
    int max_profit(std::vector<int>& prices);
    int max_profit_with_cooldown(std::vector<int>& prices);
    int max_profit_with_fee(std::vector<int>& prices, int fee);
    int max_profit_with_k_transaction(std::vector<int>& prices, int k);
    int max_profit_with_2_transaction(std::vector<int>& prices);
    int min_path_sum(std::vector<std::vector<int>>& grid);
    int min_falling_path_sum(std::vector<std::vector<int>>& grid);
    int delete_and_earn(std::vector<int>& nums);
    int rob(std::vector<int>& nums);
    int rob_2(std::vector<int>& nums);
    int rob_3(TreeNode* root);
private:
    std::vector<int> rob_helper(TreeNode* root);

};

}; // namespace dp_algo