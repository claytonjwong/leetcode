/*
 * 1381. Design a Stack With Increment Operation
 *
 * Q: https://leetcode.com/problems/design-a-stack-with-increment-operation/
 * A: https://leetcode.com/problems/design-a-stack-with-increment-operation/discuss/539695/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class CustomStack {
public:
    CustomStack(int maxSize) : cap{maxSize} {
    }
    void push(int x) {
        if (A.size() < cap)
            A.push_back(x);
    }
    int pop() {
        if (A.empty())
            return -1;
        auto res = A.back(); A.pop_back();
        return res;
    }
    void increment(int k, int val) {
        for (auto i = 0; i < k && i < A.size(); ++i)
            A[i] += val;
    }
private:
    vector<int> A;
    int cap;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
