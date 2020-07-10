/*
 * 430. Flatten a Multilevel Doubly Linked List
 *
 * Q: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 * A: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/615199/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int val, Node* prev, Node* next, Node* child) : val{ val }, prev{ prev }, next{ next }, child{ child } {}
};

namespace Iterative {
    class Solution {
    public:
        Node* flatten(Node* head, vector<Node*> stack = {}) {
            auto sentinel = new Node(-1, nullptr, head, nullptr);
            auto pre = sentinel,
                 cur = sentinel->next;
            while (cur || stack.size()) {
                if (!cur) { // ⭐️ done exploring level, link tail node of this level to next node of level above 👆
                    cur = stack.back(); stack.pop_back(); // next node of level above 🤔
                    pre->next = cur; // 🔗 tail node of previous level 👉 next node of current level
                    cur->prev = pre; // 🔗 tail node of previous level 👈 next node of current level
                }
                if (cur->child) { // start exploring level below 👇, store next node of current level 🤔
                    if (cur->next)
                        stack.push_back(cur->next);
                    cur->next = cur->child; // 🔗 current node 👉 child of current node
                    cur->child->prev = cur; // 🔗 current node 👈 child of current node
                    cur->child = nullptr; // 🚫 remove child to flatten list
                }
                pre = cur;
                cur = cur->next;
            }
            return head;
        }
    };
}

namespace Recursive {

}
class Solution {
public:
    Node* flatten(Node* head) {
        if (head)
            go(head);
        return head;
    }
private:
    Node* go(Node* node) {
        auto cur = node,
             pre = cur;
        while (cur) {
            auto next = cur->next;
            if (!cur->child) {
                pre = cur, cur = cur->next;
                continue;
            }
            cur->child->prev = cur, cur->next = cur->child; // head of child list
            auto last = go(cur->child);
            if (next)
                next->prev = last, last->next = next; // tail of child list
            cur->child = nullptr;
            pre = cur = last;
        }
        return pre; // return the tail
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
