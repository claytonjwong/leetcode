/*
 * 1032. Stream of Characters
 *
 * Q: https://leetcode.com/problems/stream-of-characters/
 * A: https://leetcode.com/problems/stream-of-characters/discuss/807725/Javascript-Python3-C%2B%2B-Trie-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

using namespace std;

class StreamChecker {
    struct TrieNode;
    using Map = unordered_map<char, shared_ptr<TrieNode>>;
    struct TrieNode {
        Map children;
        bool isEnd{ false };
    };
    shared_ptr<TrieNode> root;
    vector<shared_ptr<TrieNode>> cand;
public:
    using VS = vector<string>;
    StreamChecker(VS& A) : root{ make_shared<TrieNode>() } {
        for (auto& word: A) {
            auto cur{ root };
            for (auto c: word)
                cur = cur->children.find(c) != cur->children.end() ? cur->children[c] : cur->children[c] = make_shared<TrieNode>();
            cur->isEnd = true;
        }
    }
    bool query(char c) {
        cand.erase(  // 🚫 remove candidate nodes which do not have child c
        remove_if(cand.begin(), cand.end(), [=](auto node) {
                return node->children.find(c) == node->children.end();
            }), cand.end());
        for (auto& node: cand)
            node = node->children[c];
        if (root->children.find(c) != root->children.end())
            cand.push_back(root->children[c]);
        return any_of(cand.begin(), cand.end(), [](auto node) { return node->isEnd; });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
