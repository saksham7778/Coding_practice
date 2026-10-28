#pragma once

#include <cstddef>
#include <vector>

namespace dsa {

// Returns the first index i such that sorted[i] >= target, or sorted.size().
// Precondition: sorted is sorted in nondecreasing order.
// Time: O(log n); space: O(1).
template <typename T>
std::size_t lower_bound_index(const std::vector<T>& sorted, const T& target) {
    std::size_t left = 0;
    std::size_t right = sorted.size();  // half-open interval [left, right)
    while (left < right) {
        const std::size_t mid = left + (right - left) / 2;
        if (sorted[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

}  // namespace dsa
