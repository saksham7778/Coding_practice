#pragma once

#include <cstddef>
#include <deque>
#include <stdexcept>
#include <vector>

namespace dsa {

// Returns the maximum value for each contiguous window of width k.
// Time: O(n); space: O(k).
template <typename T>
std::vector<T> sliding_window_maximum(const std::vector<T>& values, std::size_t k) {
    if (k == 0 || k > values.size()) {
        throw std::invalid_argument("window width must be in [1, values.size()]");
    }
    std::deque<std::size_t> candidates;
    std::vector<T> result;
    result.reserve(values.size() - k + 1);

    for (std::size_t i = 0; i < values.size(); ++i) {
        while (!candidates.empty() && candidates.front() + k <= i) {
            candidates.pop_front();
        }
        while (!candidates.empty() && values[candidates.back()] <= values[i]) {
            candidates.pop_back();
        }
        candidates.push_back(i);
        if (i + 1 >= k) result.push_back(values[candidates.front()]);
    }
    return result;
}

}  // namespace dsa
