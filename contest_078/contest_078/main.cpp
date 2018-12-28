/*
 
 Rank           Name            Score   Finish Time     Q1 (5)      Q2 (5)    Q3 (7)    Q4 (9)
 334 / 3074     claytonjwong    10      0:47:20         0:47:20     0:27:51
 
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 // AC
class Solution {
public:
    int expressiveWords(string S, vector<string>& w) {
        int cnt=0,M=(int)S.size();
        vector<bool> ext(M,false);
        for (int i=2; i<M; ++i)
            if (S[i-2]==S[i-1] && S[i-1]==S[i])
                ext[i-2]=ext[i-1]=ext[i]=true;
        for (int k=0,i=0,j=0; k<w.size(); ++k,i=0,j=0){
            int N=(int)w[k].size();
            while (i<M && j<N){
                if (S[i]!=w[k][j]) break;
                while (i<M && j<N && S[i]==w[k][j]){ ++i; ++j; }
                while (i<M && i>1 && ext[i] && S[i]==w[k][j-1]) ++i;
            }
            if (i==M && j==N) ++cnt;
        }
        return cnt;
    }
};
*/





/*
 // AC
#include <unordered_map>
#include <sstream>
 
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> m;
        for (auto& cpd: cpdomains){
            stringstream ss; int cnt=0; string dom;
            ss << cpd;
            ss >> cnt >> dom;
            m[dom]+=cnt;
            for (auto i=dom.find('.'); i!=string::npos; i=dom.find('.'), m[dom]+=cnt)
                dom=dom.substr(i+1,dom.size()-i-1);
        }
        vector<string> res;
        for (auto& x: m) res.push_back(to_string(x.second) + " " + x.first);
        return res;
    }
};
*/



/*
 // AC, but ran out of time
#include <unordered_map>

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int turn=0,XOR=0;
        unordered_map<int,int> m;
        for (auto num: nums){
            ++m[num];
            XOR^=num;
        }
        if (XOR==0) return true;
        while (true){
            bool found=false;
            for (auto x: m){
                int num=x.first,newXOR=num^XOR;
                if (newXOR){ // move found, remove num, update ongoing XOR, switch turns
                    found=true;
                    if (--m[num]==0) m.erase(num);
                    XOR=newXOR;
                    turn^=1; // Alice is 0 and Bob is 1
                    break;
                }
            }
            if (!found) break; // no move found which results in non-zero XOR
        }
        return turn==1; // if it is Bob's turn, Alice wins
    }
};
*/


// AC
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int XOR=0;
        for (auto num: nums) XOR^=num;
        return XOR==0 || nums.size()%2==0;
    }
};


int main(int argc, const char * argv[]) {

    /*
    Solution s;
    
    string str="heeellooo";
    vector<string> words={"hello", "hi", "helo"};
    
    //string str="zzzzzyyyyy";
    //vector<string> words={"zzyy","zy","zyy"};
    
    auto r=s.expressiveWords(str,words);
    */
    
    /*
    Solution s;
    //vector<string> cpd={"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> cpd={"9001 discuss.leetcode.com"};
    auto r=s.subdomainVisits(cpd);
    */
    
    
    Solution s;
    vector<int> nums { 1,2,1 };
    auto r=s.xorGame(nums);
    
    
    return 0;
}
