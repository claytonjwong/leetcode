/*
 * 133. Clone Graph
 *
 * Q: https://leetcode.com/problems/clone-graph/
 * A: https://leetcode.com/problems/clone-graph/discuss/613748/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node (int val) : val{val} {}
};

namespace Concise {
    class Solution {
    public:
        using Map = unordered_map<Node*, Node*>;
        Node* cloneGraph(Node* node, Map&& m = {}) {
            if (!node)
                return nullptr;
            if (m.find(node) != m.end())
                return m[node];
            m[node] = new Node(node->val);
            for (auto nei: node->neighbors)
                m[node]->neighbors.push_back(cloneGraph(nei, move(m)));
            return m[node];
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        Node* cloneGraph(Node* node) {
            return node ? go(node) : nullptr;
        }
    private:
        using Map = unordered_map<int, Node*>;
        Node* go(Node* node, Map&& seen = {}) {
            if (seen.find(node->val) != seen.end())
                return seen[node->val];
            auto copy = new Node(node->val);
            seen[node->val] = copy;
            for (auto nei: node->neighbors)
                copy->neighbors.push_back(go(nei, move(seen)));
            return copy;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
