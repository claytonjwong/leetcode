/*
 * 133. Clone Graph
 *
 * Q: https://leetcode.com/problems/clone-graph/
 * A: https://leetcode.com/problems/clone-graph/discuss/613748/Kt-Js-Py3-Cpp-DFS-%2B-BFS-via-Map
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node (int val) : val{val} {}
};

namespace DFS {
    class Solution {
    public:
        using Map = unordered_map<int, Node*>;
        Node* cloneGraph(Node* cur, Map&& m = {}) {
            if (!cur)
                return nullptr;
            if (m[cur->val])
                return m[cur->val];
            m[cur->val] = new Node(cur->val);
            for (auto adj: cur->neighbors)
                m[cur->val]->neighbors.push_back(cloneGraph(adj, move(m)));
            return m[cur->val];
        }
    };
}

namespace BFS {
    class Solution {
    public:
        using Map = unordered_map<int, Node*>;
        using Set = unordered_set<int>;
        using Queue = queue<Node*>;
        Node* cloneGraph(Node* start, Map m = {}) {
            if (!start)
                return nullptr;
            Queue q{{{ start }}};
            Set seen{ start->val };
            while (q.size()) {
                auto cur = q.front(); q.pop();
                m[cur->val] = m[cur->val] ? m[cur->val] : new Node(cur->val);
                for (auto adj: cur->neighbors) {
                    m[adj->val] = m[adj->val] ? m[adj->val] : new Node(adj->val);
                    m[cur->val]->neighbors.push_back(m[adj->val]);
                    if (seen.insert(adj->val).second)
                        q.push(adj);
                }
            }
            return m[start->val];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
