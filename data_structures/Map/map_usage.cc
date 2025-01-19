/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2025-01-19 15:50
 * @author: yikebaer·aizezi
 * @file: map_usage.cc
 * @brief: Ubiquant interview questions
*/

#include "map_usage.h"

namespace map_usage {

void TradeBook::update(int timestamp, int price) {
    // 如果已有该时间戳的交易，首先检查是否影响最高价或最低价
    if (book.find(timestamp) != book.end()) {
        int old_price = book[timestamp];
        book.erase(timestamp);

        // 只有在价格是最高或最低时，才需要重新计算
        if (old_price == highest_price) {
            highest_price = INT_MIN;
            for (const auto& pairs : book) {
                highest_price = std::max(highest_price, pairs.second);
            }
        } 
        if (old_price == lowest_price) {
            lowest_price = INT_MAX;
            for (const auto& pairs : book) {
                lowest_price = std::min(lowest_price, pairs.second);
            }
        }
    }

    // 更新或插入新的交易价格
    book[timestamp] = price;

    // 更新历史最高最低价格
    if (price > highest_price) {
        highest_price = price;
    } 
    if (price < lowest_price) {
        lowest_price = price;
    }
}

int TradeBook::current() {
    if (book.empty()) {
        throw std::runtime_error("No trade yet");
    }
    std::cout << "null" << std::endl;
    return book.rbegin()->second;
}

int TradeBook::highest() {
    if (highest_price == INT_MIN) {
        throw std::runtime_error("No trade yet");
    }
    return highest_price;
}

int TradeBook::lowest() {
    if (lowest_price == INT_MAX) {
        throw std::runtime_error("No trade yet");
    }
    return lowest_price;
}

} // namespace map_usage