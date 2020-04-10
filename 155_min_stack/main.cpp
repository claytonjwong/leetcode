/*
 * 155. Min Stack
 *
 * Q: https://leetcode.com/problems/min-stack/
 * A: https://leetcode.com/problems/min-stack/discuss/572580/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
    void push(int x) {
        s.push_back(x);
        if (min.empty() || x <= min.back())
            min.push_back(x);
    }
    void pop() {
        if (top() == min.back())
            min.pop_back();
        s.pop_back();
    }
    int top() {
        return s.back();
    }
    int getMin() {
        return min.back();
    }
private:
    vector<int> s, min;
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
