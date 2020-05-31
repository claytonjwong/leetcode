/*
 * 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 *
 * Q: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
 * A: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/discuss/661630/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        using LL = long long;
        struct {
            int row{ 0 }, col{ 0 };
        } max;
        int maxArea(int M, int N, VI& row, VI& col) {
            row.push_back(0), row.push_back(M); sort(row.begin(), row.end());
            col.push_back(0), col.push_back(N); sort(col.begin(), col.end());
            for (auto i{ 1 }; i < row.size(); ++i) max.row = std::max(max.row, row[i] - row[i - 1]);
            for (auto j{ 1 }; j < col.size(); ++j) max.col = std::max(max.col, col[j] - col[j - 1]);
            return LL(max.row) * LL(max.col) % int(1e9 + 7);
        }
    };
}
namespace STL {
    class Solution {
    public:
        using VI = vector<int>;
        using LL = long long;
        struct {
            VI row, col;
        } max;
        int maxArea(int M, int N, VI& row, VI& col) {
            row.push_back(0), row.push_back(M); sort(row.begin(), row.end());
            col.push_back(0), col.push_back(N); sort(col.begin(), col.end());
            adjacent_difference(row.begin(), row.end(), back_inserter(max.row));
            adjacent_difference(col.begin(), col.end(), back_inserter(max.col));
            return LL(*max_element(max.row.begin() + 1, max.row.end())) * LL(*max_element(max.col.begin() + 1, max.col.end())) % int(1e9 + 7);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
