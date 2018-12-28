/*
 
 Q: https://leetcode.com/problems/add-bold-tag-in-string/description/
 A: https://leetcode.com/problems/add-bold-tag-in-string/discuss/130341/Straightforward-C++-using-bitset-to-track-bold-char-indexes
 
 */


#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_set>

using namespace std;

/*
class Solution {
public:
    string addBoldTag(string s, vector<string>& d) {
        bitset<1000> b;
        string ans;
        for (auto& w: d){
            auto pos=s.find(w);
            while (pos!=string::npos){
                for (int i=pos; i<pos+w.size(); ++i)
                    b[i]=1;
                pos=s.find(w,pos+1);
            }
        }
        bool bold=false;
        for (int i=0; i<s.size(); ++i){
            if (!bold && b[i]){
                ans.append("<b>");
                bold=true;
            }
            if (bold && !b[i]){
                ans.append("</b>");
                bold=false;
            }
            ans.push_back(s[i]);
        }
        return bold ? ans + "</b>" : ans;
    }
};
 */

class Solution {
public:
    string addBoldTag(string s, vector<string>& d) {
        bitset<1000> b;
        string ans;
        for (auto& w: d){
            auto pos=s.find(w);
            while (pos!=string::npos){
                for (int i=pos; i<pos+w.size(); ++i)
                    b[i]=1;
                pos=s.find(w,pos+1);
            }
        }
        for (int i=0,j=i+1,N=(int)s.size(); i<N; i=j){
            j=i+1;
            if (b[i]){
                while (j<N && b[j]) ++j;
                ans.append("<b>"+s.substr(i,j-i)+"</b>");
            } else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    string str="qrzjsorbkmyzzzvoqxefvxkcwtpkhzbakuufbpgdkykmojwuennrjeciqvvacpzrrczfhxnsmginzwinzihpomxtmweyyzzmgcoiupjnidphvzlnxtcogufozlenjfvokztghwckzyvmktduqkizixzxpanjwrdeudjyftxksjgdklwxrhmudhrtemuvelykqaafzlqmennttkighcdxfozdcoqkyshhajipnsdrljrnlwmyjuwxsebpqm";
    vector<string> dict = {"qr","zj","so","rb","km","yz","zz","vo","qx","ef","vx","kc","wt","pk"};
    auto r=s.addBoldTag(str, dict);
    cout << r << endl;
    
    return 0;
}


