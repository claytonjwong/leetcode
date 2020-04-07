/*
 * 1169. Invalid Transactions
 *
 * Q: https://leetcode.com/problems/invalid-transactions/
 * A: https://leetcode.com/problems/invalid-transactions/discuss/566994/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    struct Trans {
        string name, city;
        int time, amount;
        string toString() {
            stringstream ss; ss << name << "," << time << "," << amount << "," << city;
            return ss.str();
        }
    };
    using VS = vector<string>;
    using Set = unordered_set<string>;
    VS invalidTransactions(VS& T, vector<Trans> A = {}, Set set = {}, VS ans = {}) {
        int N = T.size();
        auto getTrans = [](string t) {
            transform(t.begin(), t.end(), t.begin(), [](auto c) { return c == ',' ? ' ' : c; });
            stringstream ss; ss << t;
            Trans trans; ss >> trans.name >> trans.time >> trans.amount >> trans.city;
            return trans;
        };
        transform(T.begin(), T.end(), back_inserter(A), [&](auto& t) { return getTrans(t); });
        for (auto& trans: A)
            if (trans.amount > 1000)
                set.insert(trans.toString()); // amount exceeds 1000 ❌
        for (auto i{ 0 }; i < N; ++i)
            for (auto j{ 0 }; j < N; ++j)
                if (i != j && A[i].name == A[j].name && A[i].city != A[j].city && abs(A[i].time - A[j].time) <= 60)
                    set.insert(A[i].toString()), // A[i] and A[j] occur within 60 minutes of each other ❌
                    set.insert(A[j].toString());
        return { set.begin(), set.end() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
