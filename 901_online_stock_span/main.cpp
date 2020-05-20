/*
 * 901. Online Stock Span
 *
 * Q: https://leetcode.com/problems/online-stock-span/
 * A: https://leetcode.com/problems/online-stock-span/discuss/641213/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>;

using namespace std;

namespace BruteForce {
    class StockSpanner {
    public:
        int next(int price) {
            A.push_back(price);
            int i = A.size();
            while (0 <= i - 1 && A[i - 1] <= price) --i;
            return A.size() - i; // total count <= new price 🎯
        }
    private:
        vector<int> A;
    };
}

namespace Reduce {
    class StockSpanner {
    public:
        int next(int price) {
            A.push_back({ price, 1 });
            for (int n = A.size() - 1; 0 <= n - 1 && A[n - 1].first <= A[n].first; --n, A.pop_back()) {
                auto& [prePrice, preCount] = A[n - 1];
                auto& [curPrice, curCount] = A[n];
                prePrice  = curPrice; // overwrite lesser price with new price
                preCount += curCount; // accumulate total count <= new price
            }
            return A.back().second; // total count <= new price 🎯
        }
    private:
        vector<pair<int, int>> A;
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
