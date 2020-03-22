/*
 * 1390. Four Divisors
 *
 * Q: https://leetcode.com/problems/four-divisors/
 * A: https://leetcode.com/problems/four-divisors/discuss/547865/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Set = unordered_set<int>;
    int sumFourDivisors(VI& A, int sum = 0) {
        auto getDivisors = [](auto x, Set divs = {}) {
            for (auto i{ 1 }; i <= sqrt(x); ++i)
                if (x % i == 0)
                    divs.insert(i),
                    divs.insert(x / i);
            return divs;
        };
        for (auto x: A) {
            auto divs = getDivisors(x);
            if (divs.size() == 4)
                sum += accumulate(divs.begin(), divs.end(), 0);
        }
        return sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
