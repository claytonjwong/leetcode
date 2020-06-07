/*
 * 1472. Design Browser History
 *
 * Q: https://leetcode.com/problems/design-browser-history/
 * A: https://leetcode.com/problems/design-browser-history/discuss/674419/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <queue>

using namespace std;

class BrowserHistory {
    deque<string> url;
    int i = 0;
public:
    BrowserHistory(string homepage) : url{ homepage } {
    }
    void visit(string next) {
        while (i)
            url.pop_front(), --i;
        url.push_front(next);
    }
    string back(int steps) {
        while (steps-- && i + 1 < url.size())
            ++i;
        return url[i];
    }
    string forward(int steps) {
        while (steps-- && 0 <= i - 1)
            --i;
        return url[i];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
