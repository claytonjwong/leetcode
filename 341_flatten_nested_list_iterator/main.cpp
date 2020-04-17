/*
 * 341. Flatten Nested List Iterator
 *
 * Q: https://leetcode.com/problems/flatten-nested-list-iterator/
 * A: https://leetcode.com/problems/flatten-nested-list-iterator/discuss/582851/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <queue>

using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &A) {
        go(A);
    }
    int next() {
        auto i = q.front(); q.pop();
        return i;
    }
    bool hasNext() {
        return !q.empty();
    }
private:
    queue<int> q;
    void go(const vector<NestedInteger> &A) {
        for (auto x: A)
            if (x.isInteger())
                q.push(x.getInteger());
            else
                go(x.getList());
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
