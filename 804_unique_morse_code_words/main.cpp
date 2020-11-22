/*
 * 804. Unique Morse Code Words
 *
 * Q: https://leetcode.com/problems/unique-morse-code-words/
 * A: https://leetcode.com/problems/unique-morse-code-words/discuss/120682/Kt-Js-Py3-Cpp-Seen
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Set = unordered_set<string>;
    int uniqueMorseRepresentations(VS& A, Set seen = {}) {
        VS m{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for (auto& word: A) {
            string encoded;
            for (auto c: word)
                encoded.append(m[c - 'a']);
            seen.insert(encoded);
        }
        return seen.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
