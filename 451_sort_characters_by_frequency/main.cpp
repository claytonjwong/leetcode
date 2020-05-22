/*
 * 451. Sort Characters By Frequency
 *
 * Q: https://leetcode.com/problems/sort-characters-by-frequency/
 * A: https://leetcode.com/problems/sort-characters-by-frequency/discuss/645813/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace std;

namespace ComparisonSort {
    class Solution {
    public:
        using Map = unordered_map<char, int>;
        using Bucket = map<int, string, greater<int>>;
        string frequencySort(string s, Map m = {}, Bucket bucket = {}, string ans = {}) {
            for (auto c: s)
                ++m[c];
            for (auto [c, cnt]: m)
                bucket[cnt].push_back(c);
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                auto [cnt, chars] = tie(it->first, it->second);
                for (auto c: chars)
                    fill_n(back_inserter(ans), cnt, c);
            }
            return ans;
        }
    };
}

namespace CountingSort {
    class Solution {
    public:
        using Map = unordered_map<char, int>;
        using Bucket = unordered_map<int, string>;
        string frequencySort(string s, Map m = {}, Bucket bucket = {}, string ans = {}) {
            int N = s.size();
            for (auto c: s)
                ++m[c];
            for (auto [c, cnt]: m)
                bucket[cnt].push_back(c);
            for (auto cnt{ N }; 0 <= cnt; --cnt)
                for (auto c: bucket[cnt])
                    fill_n(back_inserter(ans), cnt, c);
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
