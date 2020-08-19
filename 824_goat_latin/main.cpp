/*
 * 824. Goat Latin
 *
 * Q: https://leetcode.com/problems/goat-latin/
 * A: https://leetcode.com/problems/goat-latin/discuss/128096/3-liner-C%2B%2B
 */

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string toGoatLatin(string words, string s = {}, int i = 0, string vowels = "aeiouAEIUO", ostringstream os = ostringstream()) {
        istringstream is{ words };
        while (is >> s){
            if (vowels.find(s[0]) == string::npos)
                s = s.substr(1) + s[0];
            os << s << "ma", fill_n(ostream_iterator<char>(os), ++i, 'a'), os << (0 < is.tellg() ? " " : "");
        }
        return os.str();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
