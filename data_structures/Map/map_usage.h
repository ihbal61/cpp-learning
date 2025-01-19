/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2025-01-19 15:50
 * @author: yikebaer·aizezi
 * @file: map_usage.h
 * @brief: 九坤投资笔试题之一
*/
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <climits>
#include <stdexcept>


namespace map_usage {

class TradeBook {
public:
    TradeBook() = default;
    ~TradeBook() = default;

    void update(int timestamp, int price);
    int current();
    int highest();
    int lowest();

private:
    std::map<int, int> book;
    int highest_price = INT_MIN;
    int lowest_price = INT_MAX;
};

} // namespace map_usage