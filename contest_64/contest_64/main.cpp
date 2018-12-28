/*
 
 
 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res(A.size());
        unordered_map<int,int> m;
        for (int i=0; i<A.size(); ++i) m[B[i]]=i;
        for (int i=0; i<A.size(); ++i) res[i]=m[A[i]];
        return res;
    }
};


/*
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        string res;
        vector<bool> bs(S.size(),false);
        for (int i=0; i<S.size(); ++i){
            for (int j=0; j<words.size(); ++j){
                int sz=(int)words[j].size();
                if (i+sz-1 >= S.size()) continue;
                if (S.substr(i,sz)==words[j]) {
                    for (int k=i; k<i+sz; ++k)
                        bs[k]=true;
                }
            }
        }
        bool prev=false, curr=bs[0];
        if (bs[0]){
            res.push_back('<');
            res.push_back('b');
            res.push_back('>');
            
        }
        res.push_back(S[0]);
        for (int i=1; i<S.size(); ++i){
            prev=curr;
            curr=bs[i];
            if ((prev==false && curr==false) || (prev==true && curr==true)){
                res.push_back(S[i]);
            } else if (prev==false && curr==true){
                res.push_back('<');
                res.push_back('b');
                res.push_back('>');
                res.push_back(S[i]);
            } else if (prev==true && curr==false){
                res.push_back('<');
                res.push_back('/');
                res.push_back('b');
                res.push_back('>');
                res.push_back(S[i]);
            }
        }
        if (bs.back()){
            res.push_back('<');
            res.push_back('/');
            res.push_back('b');
            res.push_back('>');
        }
        return res;
    }
};
*/


/*
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        string res;
        bitset<500> bs;
        for (int i=0; i<S.size(); ++i)
            for (int j=0; j<words.size(); ++j)
                if (i+words[j].size()-1<S.size() && S.substr(i,words[j].size())==words[j])
                    for (int k=i; k<i+words[j].size(); ++k) bs[k]=true;
        bool prev=false, curr=bs[0];
        if (bs[0]) res.append("<b>");
        res.push_back(S[0]);
        for (int i=1; i<S.size(); ++i){
            prev=curr; curr=bs[i];
            if (prev==false && curr==true) res.append("<b>");
            if (prev==true && curr==false) res.append("</b>");
            res.push_back(S[i]);
        }
        if (S.size()>0 && bs[S.size()-1]) res.append("</b>");
        return res;
    }
};
*/

/*
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        string res;
        bitset<500> bs;
        for (int i=0; i<S.size(); ++i)
            for (int j=0; j<words.size(); ++j)
                if (i+words[j].size()-1<S.size() && S.substr(i,words[j].size())==words[j])
                    for (int k=i; k<i+words[j].size(); ++k) bs[k]=true;
        for (int i=0; i<S.size(); ++i)
            if (bs[i]){
                res.append("<b>");
                int start=i;
                while (i+1<S.size() && bs[i+1]) ++i;
                res.append(S.substr(start,i-start+1)+"</b>");
            }
            else
                res.push_back(S[i]);
        return res;
    }
};
*/


int main(int argc, const char * argv[]) {

    Solution s;
    
    vector<int> a { 1,2,3,4 };
    vector<int> b { 4,3,2,1 };
    
    auto res=s.anagramMappings(a, b);
    
    return 0;
}



