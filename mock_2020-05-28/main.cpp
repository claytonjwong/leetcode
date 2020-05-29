/*
 * Random Set- Phone Interview
 * Completed May 28, 2020 7:18 AM
 * Time Spent: 11 minutes 51 seconds
 * Time Allotted: 1 hour 30 minutes
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 46. Permutations
 *
 * Q: https://leetcode.com/problems/permutations/
 * A: https://leetcode.com/problems/permutations/discuss/657552/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        VVI permute(VI& A, VVI ans = {}) {
            sort(A.begin(), A.end());
            do {
                ans.push_back({ A.begin(), A.end() });
            } while (next_permutation(A.begin(), A.end()));
            return ans;
        }
    };
}

/*
 * 208. Implement Trie (Prefix Tree)
 *
 * Q: https://leetcode.com/problems/implement-trie-prefix-tree/
 * A: https://leetcode.com/problems/implement-trie-prefix-tree/discuss/631834/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
    class Trie {
    public:
        Trie() : root{ make_shared<Node>() } {
        }
        void insert(string word) {
            NodePtr cur{ root };
            for (auto c: word) {
                if (cur->children.find(c) == cur->children.end())
                    cur->children[c] = make_shared<Node>();
                cur = cur->children[c];
            }
            cur->isEnd = true;
        }
        bool find(string& word, bool prefix = false) {
            NodePtr cur{ root };
            for (auto c: word) {
                if (cur->children.find(c) == cur->children.end())
                    return false;
                cur = cur->children[c];
            }
            return prefix ? true : cur->isEnd;
        }
        bool search(string word) {
            return find(word);
        }
        bool startsWith(string prefix) {
            return find(prefix, true);
        }
    private:
        struct Node;
        using NodePtr = shared_ptr<Node>;
        using Map = unordered_map<char, NodePtr>;
        struct Node {
            Map children;
            bool isEnd = false;
        };
        NodePtr root;
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
