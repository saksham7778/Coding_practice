#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

namespace dsa {

// Returns the maximum sum among all contiguous windows of width k.
// Time: O(n); auxiliary space: O(1).
// Throws std::invalid_argument if k is zero or larger than values.size().
template <typename T>
long long max_fixed_window_sum(const std::vector<T>& values, std::size_t k) {
    if (k == 0 || k > values.size()) {
        throw std::invalid_argument("window width must be in [1, values.size()]");
    }

    long long window_sum = 0;
    for (std::size_t i = 0; i < k; ++i) {
        window_sum += static_cast<long long>(values[i]);
    }
    long long best = window_sum;

    for (std::size_t right = k; right < values.size(); ++right) {
        window_sum += static_cast<long long>(values[right]);
        window_sum -= static_cast<long long>(values[right - k]);
        if (window_sum > best) best = window_sum;
    }
    return best;
}

}  // namespace dsa
