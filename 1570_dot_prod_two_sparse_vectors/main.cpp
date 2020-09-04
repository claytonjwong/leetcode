/*
 * 1570. Dot Product of Two Sparse Vectors
 *
 * Q: https://leetcode.com/problems/dot-product-of-two-sparse-vectors/
 * A: https://leetcode.com/problems/dot-product-of-two-sparse-vectors/discuss/826785/Javascript-Python3-C%2B%2B-Zip-%2B-Map-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

namespace procedural {
    class SparseVector {
        using VI = vector<int>;
        VI A;
    public:
        SparseVector(VI& A) : A{ A } {}
        int operator[](int i) { return A[i]; }
        int dotProduct(SparseVector& B) {
            auto sum{ 0 };
            for (auto i{ 0 }; i < A.size(); ++i)
                sum += A[i] * B[i];
            return sum;
        }
    };
}

namespace functional {
    class SparseVector {
        using VI = vector<int>;
        VI A;
    public:
        SparseVector(VI& A) : A{ A } {}
        int operator[](int i) { return A[i]; }
        int dotProduct(SparseVector& B) {
            return accumulate(A.begin(), A.end(), 0, [i = -1, &B](auto sum, auto x) mutable { return sum + x * B[++i]; });
        }
    };
}

namespace optimized {
    class SparseVector {
    public:
        using VI = vector<int>;
        using Map = unordered_map<int, int>;
        Map m;
        SparseVector(VI& A) {
            for (auto i{ 0 }; i < A.size(); ++i)
                if (A[i]) m[i] = A[i];
        }
        int dotProduct(SparseVector& other) {
            auto sum{ 0 };
            for (auto [i, x]: m)
                sum += x * other.m[i];
            return sum;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
