/*
 * 1506. Find Root of N-Ary Tree
 *
 * Q: https://leetcode.com/problems/find-root-of-n-ary-tree/
 * A: https://leetcode.com/problems/find-root-of-n-ary-tree/discuss/729168/Kt-Js-Py3-Cpp-O(N)-%2B-O(1)-memory-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node {
    int val;
    vector<Node*> children;
};

namespace Naive {
    class Solution {
    public:
        using Nodes = vector<Node*>;
        using Set = unordered_set<Node*>;
        Node* findRoot(Nodes A, Set children = {}) {
            for (auto it: A)
                for (auto child: it->children)
                    children.insert(child);
            A.erase(remove_if(A.begin(), A.end(), [&](auto it) { return children.find(it) != children.end(); }), A.end());
            return A.front();
        }
    };
}
namespace MemOpt {
    class Solution {
    public:
        using Nodes = vector<Node*>;
        Node* findRoot(Nodes A, int x = 0) {
            for (auto it: A) {
                x ^= it->val;
                for (auto child: it->children)
                    x ^= child->val;
            }
            A.erase(remove_if(A.begin(), A.end(), [=](auto it) { return x != it->val; }), A.end());
            return A.front();
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
