/*
 * 716. Max Stack
 *
 * Q: https://leetcode.com/problems/max-stack/
 * A: https://leetcode.com/problems/max-stack/discuss/600673/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class MaxStack {
public:
    void push(int x) {
        stack.push_back(x);
        if (max.empty() || max.back() <= x)
            max.push_back(x);
    }
    int pop() {
        auto x = stack.back(); stack.pop_back();
        if (!max.empty() && max.back() == x)
            max.pop_back();
        return x;
    }
    int top() {
        return stack.back();
    }
    int peekMax() {
        return max.back();
    }
    int popMax() {
        VI t; // temp
        auto x = max.back(); max.pop_back();
        while (stack.back() < x)
            t.push_back(stack.back()), stack.pop_back();
        stack.pop_back(); // pop corresponding x
        while (!t.empty())
            push(t.back()), t.pop_back();
        return x;
    }
private:
    using VI = vector<int>;
    VI stack, max;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
