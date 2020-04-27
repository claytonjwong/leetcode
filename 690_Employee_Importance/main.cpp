/*
 * 690. Employee Importance
 *
 * Q: https://leetcode.com/problems/employee-importance/
 * A: https://leetcode.com/problems/employee-importance/discuss/599340/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Employee {
    int id, importance;
    vector<int> subordinates;
};

class Solution {
public:
    using Employees = vector<Employee*>;
    using Map = unordered_map<int, int>;
    int getImportance(Employees E, int id, Map m = {}) {
        for (auto i{ 0 }; i < E.size(); ++i)
            m[E[i]->id] = i;
        return go(E, m[id], m);
    }
private:
    int go(Employees& E, int i, Map& m) {
        auto sum = E[i]->importance;
        for (auto j: E[i]->subordinates)
            sum += go(E, m[j], m);
        return sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
