/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2025-9-13 18:58
 * @author: yikebaer·aizezi
 * @file: compute.cc
 * @brief: compute algorithm
*/
#include "compute.h"

int main() {
    uint32_t a, b, c;
    compute::Compute cpt_func;
    while (std::cin >> a >> b) {
        std::string method;
        std::cin >> method;
        compute::Compute cpt_func;

        cpt_func.compute_value(a, b, c, method);

        cpt_func.print_result(c);
    }

    return 0;
}
