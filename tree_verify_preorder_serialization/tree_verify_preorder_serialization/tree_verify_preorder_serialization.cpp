/*
 
 331. Verify Preorder Serialization of a Binary Tree
 
 Q: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
 A: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/discuss/144673/Straightforward-C++-(-EASY-to-understand-)-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder, string tok="", vector<string> s={}) {
        istringstream is(preorder);
        while (getline(is,tok,',')){
            s.emplace_back(std::move(tok));
            for (int N=(int)s.size(); N>2 && s[N-3]!="#" && s[N-2]=="#" && s[N-1]=="#"; N=(int)s.size())
                s.resize(N-2),s.back()="#";
        }
        return s.size()==1 && s.back()=="#";
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    string preorder="9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << preorder << ": " << s.isValidSerialization(preorder) << endl;
    
    return 0;
}
