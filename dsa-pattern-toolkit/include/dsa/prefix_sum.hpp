#pragma once

#include <cstddef>
#include <unordered_map>
#include <vector>

namespace dsa {

// Returns the number of contiguous subarrays whose sum equals target.
// Expected time: O(n); space: O(n). Supports negative values.
template <typename T>
long long count_subarrays_with_sum(const std::vector<T>& values, long long target) {
    std::unordered_map<long long, long long> frequency;
    frequency[0] = 1;
    long long prefix = 0;
    long long answer = 0;

    for (const T value : values) {
        prefix += static_cast<long long>(value);
        const auto it = frequency.find(prefix - target);
        if (it != frequency.end()) {
            answer += it->second;
        }
        ++frequency[prefix];
    }
    return answer;
}

}  // namespace dsa
