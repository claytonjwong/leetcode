/*
 * 380. Insert Delete GetRandom O(1)
 *
 * Q: https://leetcode.com/problems/insert-delete-getrandom-o1/
 * A: https://leetcode.com/problems/insert-delete-getrandom-o1/discuss/683603/Javascript-and-C%2B%2B-solutions\
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

namespace Set {
    class RandomizedSet {
        using Set = unordered_set<int>;
        using VI = vector<int>;
        Set S;
    public:
        bool insert(int val) {
            return S.insert(val).second;
        }
        bool remove(int val) {
            if (S.find(val) != S.end()) {
                S.erase(val);
                return true;
            }
            return false;
        }
        int getRandom() {
            VI A = { S.begin(), S.end() };
            return A[rand() % A.size()];
        }
    };
}

namespace MapArray {
    class RandomizedSet {
        using Map = unordered_map<int, int>; // value -> index
        using VI = vector<int>;
        Map m;
        VI A;
    public:
        bool insert(int x) {
            if (m.find(x) != m.end())
                return false;
            A.push_back(x);
            m[x] = A.size() - 1;
            return true;
        }
        bool remove(int x) {
            if (m.find(x) == m.end())
                return false;
            auto i = m[x]; // value x exists at A[i]
            m.erase(x); // "erase" mapping to removed value x
            swap(A[i], A.back()), A.pop_back(); // erase A[i] in O(1) via swap/pop back
            m[A[i]] = i; // update mapped index for the element which replaced A[i]
            return true;
        }
        int getRandom() {
            return A[rand() % A.size()];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
