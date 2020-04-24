/*
 * 146. LRU Cache
 *
 * Q: https://leetcode.com/problems/lru-cache/
 * A: https://leetcode.com/problems/lru-cache/discuss/595305/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity)
            : cap{capacity} {}
    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        q.remove(key);
        q.push_front(key);
        return m[key];
    }
    void put(int key, int val) {
        q.remove(key);
        while (q.size() >= cap) {
            auto del = q.back(); q.pop_back();
            m.erase(del);
        }
        q.push_front(key);
        m[key] = val;
    }
private:
    int cap;
    list<int> q;
    unordered_map<int, int> m;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
