/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2025-9-13 18:58
 * @author: yikebaer·aizezi
 * @file: compute.h
 * @brief: compute algorithm
*/
#pragma once

#include <iostream> // 库，这里面提供了很多方法
#include <vector>
#include <string>
#include <algorithm>

namespace compute {

class Compute {
public:
    Compute() = default;
    ~Compute() = default;
public:
    template <typename T>
    void print_result(T& res) {
        std::cout << "The result is: "  << res << std::endl;
    }

    template <typename T>
    bool compute_value(T& a, T& b, T& res, const std::string& method) {
        if (method == "sum") {
            res = a + b;
        } else if (method == "multi") {
            res = a * b; 
        } else if (method == "divide") {
            res = a / b;
        } else if (method == "reduce") {
            res = a - b;
        } else {
            std::cerr << "error method type, please try again." << std::endl;
            return false;
        }
        return true;
    }

};

} // namespace compute


