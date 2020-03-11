/*
 * 1376. Time Needed to Inform All Employees
 *
 * Q: https://leetcode.com/problems/time-needed-to-inform-all-employees/
 * A: https://leetcode.com/problems/time-needed-to-inform-all-employees/discuss/534379/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    using VI = vector<int>;
//    using Map = unordered_map<int, VI>;
//    int numOfMinutes(int N, int root, VI& parent, VI& cost, Map adj = {}) {
//        for (auto i = 0; i < N; ++i)
//            if (parent[i] > -1)
//                adj[parent[i]].push_back(i);
//        return go(root, cost, adj);
//    }
//private:
//    int go(int i, VI& cost, Map& adj, int max = 0) {
//        for (auto j: adj[i])
//            max = std::max(max, cost[i] + go(j, cost, adj));
//        return max;
//    }
//};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
