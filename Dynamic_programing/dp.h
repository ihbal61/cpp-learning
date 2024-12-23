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

namespace dp_algo {

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
private:

};

}; // namespace dp_algo