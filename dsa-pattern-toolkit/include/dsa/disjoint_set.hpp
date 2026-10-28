#pragma once

#include <cstddef>
#include <numeric>
#include <stdexcept>
#include <vector>

namespace dsa {

// Disjoint-set union with path compression and union by size.
// Amortized time per operation: O(alpha(n)); space: O(n).
class DisjointSet {
public:
    explicit DisjointSet(std::size_t n) : parent_(n), size_(n, 1), components_(n) {
        std::iota(parent_.begin(), parent_.end(), std::size_t{0});
    }

    std::size_t find(std::size_t x) {
        check_index(x);
        if (parent_[x] != x) parent_[x] = find(parent_[x]);
        return parent_[x];
    }

    // Returns true only if two previously separate components were merged.
    bool unite(std::size_t a, std::size_t b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size_[a] < size_[b]) {
            const std::size_t tmp = a;
            a = b;
            b = tmp;
        }
        parent_[b] = a;
        size_[a] += size_[b];
        --components_;
        return true;
    }

    std::size_t component_size(std::size_t x) { return size_[find(x)]; }
    std::size_t components() const noexcept { return components_; }

private:
    std::vector<std::size_t> parent_;
    std::vector<std::size_t> size_;
    std::size_t components_;

    void check_index(std::size_t x) const {
        if (x >= parent_.size()) throw std::out_of_range("DSU index out of range");
    }
};

}  // namespace dsa
