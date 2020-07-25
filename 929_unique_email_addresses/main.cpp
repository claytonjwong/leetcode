/*
 * 929. Unique Email Addresses
 *
 * Q: https://leetcode.com/problems/unique-email-addresses/
 * A: https://leetcode.com/problems/unique-email-addresses/discuss/186655/Concise-C%2B%2B
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Set = unordered_set<string>;
    int numUniqueEmails(VS& A, Set unique = {}) {
        for (auto& email: A) {
            auto pivot = email.find('@');
            auto user = email.substr(0, pivot),
                 domain = email.substr(pivot + 1);
            user.erase(remove_if(user.begin(), user.end(), [](auto c) { return c == '.'; }), user.end());
            auto i = user.find('+');
            if (i != string::npos)
                user = user.substr(0, i);
            unique.insert(user + '@' + domain);
        }
        return unique.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
