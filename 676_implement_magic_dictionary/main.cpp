/*
 * 676. Implement Magic Dictionary
 *
 * Q: https://leetcode.com/problems/implement-magic-dictionary/
 * A: https://leetcode.com/problems/implement-magic-dictionary/discuss/682319/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class MagicDictionary {
    using Set = unordered_set<string>;
    Set dict;
public:
    void buildDict(vector<string> words) {
        dict = Set{ words.begin(), words.end() };
    }
    bool search(string word) {
        for (auto i{ 0 }; i < word.size(); ++i) {
            for (auto c{ 'a' }; c <= 'z'; ++c) {
                if (word[i] != c) {
                    auto cand{ word };
                    cand[i] = c;
                    if (dict.find(cand) != dict.end())
                        return true;
                }
            }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
