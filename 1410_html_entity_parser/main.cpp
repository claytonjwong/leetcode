/*
 * 1410. HTML Entity Parser
 *
 * Q: https://leetcode.com/problems/html-entity-parser/
 * A: https://leetcode.com/problems/html-entity-parser/discuss/574892/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Map = unordered_map<string, char>;
    string entityParser(string text, int i = -1, int j = -1, string ans = {}) {
        Map map{{"&quot;",'"'},{"&apos;",'\''},{"&amp;",'&'},{"&gt;",'>'},{"&lt;",'<'},{"&frasl;",'/'}};
        for (auto k{ 0 }; k < text.size(); ++k) {
            auto c = text[k];
            ans.push_back(c);
            if (c == '&') i = k;
            if (c == ';') j = k;
            if (i < j) {
                auto N = int(ans.size()) - (j - i + 1); // N == |text[i..j]| (+1 for i..j inclusive)
                auto T = ans.substr(N); // target 🎯
                if (map.find(T) != map.end()) {
                    ans = ans.substr(0, N); // remove text[i..j]
                    ans.push_back(map[T]); // add corresponding html entity
                }
                i = j = -1;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
