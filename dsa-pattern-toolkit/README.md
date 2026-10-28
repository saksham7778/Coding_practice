# DSA Pattern Toolkit

A small, tested C++17 reference library for reusable data-structure and algorithm patterns. Each implementation aims to explain its invariant, document complexity, and include edge-case tests.

> Status: initial project scaffold. The implementations below are examples, not a claim of broad adoption or production readiness.

## Included patterns

- Prefix sums and subarray-sum counting with a frequency map
- Fixed-size sliding window
- Binary search for the first element not less than a target
- Disjoint-set union (union by size + path compression)
- Monotonic deque for sliding-window maximum

## Build and test

Requirements: CMake 3.16+, a C++17 compiler, and CTest.

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Example

```cpp
#include <iostream>
#include <vector>
#include "dsa/prefix_sum.hpp"

int main() {
    const std::vector<int> values{1, 2, 3, -2, 2};
    std::cout << dsa::count_subarrays_with_sum(values, 3) << '\n';
}
```

## Design principles

1. Prefer small, composable functions with explicit preconditions.
2. State time and space complexity.
3. Test empty input, duplicates, negative values, and boundary cases where relevant.
4. Keep examples and tests deterministic.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md). Issues and pull requests that improve correctness, explanations, portability, or tests are welcome.

## License

MIT; see [LICENSE](LICENSE).
