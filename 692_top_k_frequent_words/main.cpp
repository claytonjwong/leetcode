/*
 * 692. Top K Frequent Words
 *
 * Q: https://leetcode.com/problems/top-k-frequent-words/
 * A: https://leetcode.com/problems/top-k-frequent-words/discuss/154012/C%2B%2B-solution-using-priority_queue
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Map = unordered_map<string, int>;
    using Pair = pair<string, int>;
    struct Comp {
        bool operator()(const Pair& a, const Pair& b) const {
            return a.second != b.second ? a.second < b.second : a.first > b.first;
        }
    };
    using Queue = priority_queue<Pair, vector<Pair>, Comp>;
    VS topKFrequent(VS& A, int K, Map m = {}, VS ans={}) {
        for (auto& word: A)
            ++m[word];
        Queue q{ m.begin(),m.end() };
        while (K--)
            ans.push_back(q.top().first), q.pop();
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
