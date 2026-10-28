#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "dsa/binary_search.hpp"
#include "dsa/disjoint_set.hpp"
#include "dsa/prefix_sum.hpp"
#include "dsa/sliding_window.hpp"
#include "dsa/sliding_window_maximum.hpp"

namespace {
int failures = 0;

void expect(bool condition, const std::string& name) {
    if (condition) {
        std::cout << "[PASS] " << name << '\n';
    } else {
        std::cerr << "[FAIL] " << name << '\n';
        ++failures;
    }
}

template <typename Fn>
void expect_throws(const std::string& name, const Fn& fn) {
    try {
        fn();
        expect(false, name);
    } catch (const std::invalid_argument&) {
        expect(true, name);
    }
}
}  // namespace

int main() {
    expect(dsa::count_subarrays_with_sum(std::vector<int>{1, 2, 3, -2, 2}, 3) == 4,
           "prefix sum: target count including negative values");
    expect(dsa::count_subarrays_with_sum(std::vector<int>{}, 0) == 0,
           "prefix sum: empty input");
    expect(dsa::count_subarrays_with_sum(std::vector<int>{0, 0, 0}, 0) == 6,
           "prefix sum: repeated zero prefixes");

    expect(dsa::max_fixed_window_sum(std::vector<int>{-5, -2, -7}, 2) == -7,
           "fixed window: all-negative values");
    expect_throws("fixed window: reject zero width", [] {
        (void)dsa::max_fixed_window_sum(std::vector<int>{1, 2}, 0);
    });

    expect(dsa::lower_bound_index(std::vector<int>{1, 2, 2, 4}, 2) == 1,
           "binary search: duplicates");
    expect(dsa::lower_bound_index(std::vector<int>{1, 3, 5}, 6) == 3,
           "binary search: target after all values");
    expect(dsa::lower_bound_index(std::vector<int>{}, 1) == 0,
           "binary search: empty input");

    dsa::DisjointSet dsu(5);
    expect(dsu.components() == 5, "DSU: initial component count");
    expect(dsu.unite(0, 1), "DSU: first merge succeeds");
    expect(!dsu.unite(1, 0), "DSU: duplicate merge is detected");
    dsu.unite(1, 2);
    expect(dsu.component_size(0) == 3 && dsu.components() == 3,
           "DSU: component size and count");

    expect(dsa::sliding_window_maximum(std::vector<int>{1, 3, -1, -3, 5, 3, 6, 7}, 3) ==
               std::vector<int>({3, 3, 5, 5, 6, 7}),
           "monotonic deque: standard example");
    expect(dsa::sliding_window_maximum(std::vector<int>{4, 4, 4}, 1) ==
               std::vector<int>({4, 4, 4}),
           "monotonic deque: window width one");

    if (failures != 0) {
        std::cerr << failures << " test(s) failed\n";
        return 1;
    }
    std::cout << "All tests passed.\n";
    return 0;
}
