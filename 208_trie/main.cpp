/*
 * 208. Implement Trie (Prefix Tree)
 *
 * Q: https://leetcode.com/problems/implement-trie-prefix-tree/
 * A: https://leetcode.com/problems/implement-trie-prefix-tree/discuss/631834/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    unordered_map<char, shared_ptr<Node>> children;
    bool isEnd = false;
};
class Trie {
public:
    Trie() : _root{make_shared<Node>()} {}
    void insert(string word) {
        auto cur{ _root };
        for (auto c: word) {
            if (cur->children.find(c) == cur->children.end())
                cur->children[c] = make_shared<Node>();
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }
    bool search(string word) {
        return _find(word, false);
    }
    bool startsWith(string word) {
        return _find(word, true);
    }
private:
    shared_ptr<Node> _root;
    bool _find(string& word, bool isPrefix) {
        auto cur{ _root };
        for (auto c: word) {
            if (cur->children.find(c) == cur->children.end())
                return false;
            cur = cur->children[c];
        }
        return isPrefix ? true : cur->isEnd;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
