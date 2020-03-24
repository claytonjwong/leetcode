/*
 * 71. Simplify Path
 *
 * Q1: https://leetcode.com/problems/simplify-path/
 * A1: https://leetcode.com/problems/simplify-path/discuss/549428/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path, string dir = {}, vector<string> stack = {}) {
        transform(path.begin(), path.end(), path.begin(), [](auto c) { return c == '/' ? ' ' : c; });
        for (istringstream stream{ path }; stream >> dir;)
            if (dir != "." && dir != "..")
                stack.push_back(dir);
            else if (dir == ".." && !stack.empty())
                stack.pop_back();
        stringstream stream;
        for (auto& dir: stack)
            stream << "/" << dir;
        string ans = stream.str();
        return ans.empty() ? "/" : ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
