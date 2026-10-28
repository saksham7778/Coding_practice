#include <iostream>
#include <vector>
#include "dsa/prefix_sum.hpp"

int main() {
    const std::vector<int> values{1, 2, 3, -2, 2};
    std::cout << dsa::count_subarrays_with_sum(values, 3) << '\n';
}
