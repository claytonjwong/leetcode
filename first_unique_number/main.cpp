/*
 * First Unique Number
 *
 * Q: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3313/
 * A: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3313/discuss/601774/Javascript-and-C++-solutions
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class FirstUnique {
public:
    using VI = vector<int>;
    FirstUnique(VI& A) {
        for (auto x: A)
            add(x);
    }
    void add(int x) {
        if (!set.insert(x).second) {
            dup.insert(x);
            return;
        }
        q.push(x);
    }
    int showFirstUnique() {
        while (!q.empty()) {
            auto x = q.front();
            if (dup.find(x) != dup.end())
                q.pop();
            else
                return x;
        }
        return -1;
    }
private:
    set<int> set, dup;
    queue<int> q;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
