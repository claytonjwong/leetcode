/*
 
 Q: https://leetcode.com/problems/open-the-lock/description/
 
 A: https://leetcode.com/problems/open-the-lock/discuss/126567/Concise-C++-BFS-(-EASY-to-understand-)-with-explanation
 
 */

#include <iostream>
#include <queue>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& de, string t) {
        queue<string> q({"0000"});
        unordered_set<string> v({q.front()}),x(de.begin(),de.end());
        for (int d=0,N=(int)q.size(); !q.empty(); ++d,N=(int)q.size()){
            while (N--){
                auto curr=q.front(); q.pop();
                if (x.count(curr)) continue;
                if (curr==t) return d;
                for (auto nei: next(curr)){
                    if (v.count(nei)) continue;
                    q.push(nei);
                    v.insert(nei);
                }
            }
        }
        return -1;
    }
private:
    vector<string> next(const string& s){
        vector<string> res;
        for (int i=0; i<s.size(); ++i){
            int up=stoi(s.substr(i,1))+1,dn=stoi(s.substr(i,1))-1;
            if (up==10) up=0; // 9 -> 0
            if (dn==-1) dn=9; // 0 -> 9
            res.emplace_back(s.substr(0,i)+to_string(up)+s.substr(i+1));
            res.emplace_back(s.substr(0,i)+to_string(dn)+s.substr(i+1));
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<string> de={"8887","8889","8878","8898","8788","8988","7888","9888"};
    string t="8888";
    auto r=s.openLock(de, t);
    
    cout << endl << endl << "R: " << r << endl;
    
    return 0;
}



