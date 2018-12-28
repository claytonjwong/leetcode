/*
 
 https://leetcode.com/contest/weekly-contest-80/ranking
 
 Rank           Name            Score       Finish Time     Q1 (4)      Q2 (4)    Q3 (6)    Q4 (8)
 752 / 2570     claytonjwong     8          0:44:16         0:24:34     0:44:16
 
 
 Q1: https://leetcode.com/problems/most-common-word/discuss/123868/Concise-C++-using-unordered_map-and-stringstrream
 Q2: https://leetcode.com/problems/linked-list-components/discuss/123870/Straightforward-C++-with-explanation
 Q3: https://leetcode.com/problems/ambiguous-coordinates/discuss/124166/Straightforward-C++-(-EASY-to-understand-)
 Q4: https://leetcode.com/problems/race-car/discuss/124312/Straightforward-C++-BFS-solution-with-Explanation
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

/*
class Solution {
public:
    string mostCommonWord(string p, vector<string>& x) {
        unordered_map<string,int> m;
        unordered_set<string> b(x.begin(),x.end());
        for_each(p.begin(),p.end(),[](char& c){
            c=isalpha(c) ? tolower(c) : ' ';
        });
        int cnt=0;
        string s,ans;
        stringstream ss(p);
        while (ss >> s){
            if (!b.count(s) && ++m[s] > cnt){
                ans=s;
                cnt=m[s];
            }
        }
        return ans;
    }
};
*/

/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val{x}, next{nullptr} {}
};
                           
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int cnt=0;
        unordered_set<int> S(G.begin(),G.end());
        for (auto itr=head; itr!=nullptr; itr=itr->next)
            if (S.count(itr->val) && (itr->next==nullptr || !S.count(itr->next->val)))
                ++cnt;
        return cnt;
    }
};
*/

/*
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> ans;
        S=S.substr(1,S.size()-2);
        int N=(int)S.size();
        for (int i=1; i<N; ++i){
            string a=S.substr(0,i),b=S.substr(i,N-i);
            vector<string> cx=getCoords(a),cy=getCoords(b);
            for (auto& x: cx)
                for (auto& y: cy)
                    ans.push_back("("+x+", "+y+")");
        }
        return ans;
    }
private:
    vector<string> getCoords(const string& s){
        int N=(int)s.size();
        if (N==1) return {s};
        vector<string> res;
        if (isValid(s)) res.push_back(s);
        for (int i=1; i<N; ++i){
            string a=s.substr(0,i),b=s.substr(i,N-i),c=(a+"."+b);
            if (isValid(c)) res.push_back(c);
        }
        return res;
    }
    bool isValid(const string& s){
        
        if (s[0]=='0' && s[1]=='0') return false; // begin with 00...
        if (s[0]=='0' && s[1]!='.') return false; // begin with 0X...
        if (s.find('.')!=string::npos && s.back()=='0') return false; // end with .XXX0

        int i=(int)s.size()-1; // end with .000...
        while (i>0 && s[i]=='0') --i;
        if (s[i]=='.') return false;
        
        return true;
    }
};
*/


// P=position, S=speed
#define P first
#define S second
class Solution {
public:
    int racecar(int T) {
        queue<pair<int,int>> q({make_pair(0,1)});
        unordered_set<pair<int,int>, hash> v({q.front()});
        for (int d=0,N=(int)q.size(); true; ++d,N=(int)q.size()){
            while (N--){
                auto x=q.front(); q.pop();
                if (x.P==T) return d;
                auto A=make_pair(x.P + x.S,x.S * 2);
                if (!v.count(A) && abs(A.P - T) < T){ // prune A by position
                    q.push(A);
                    v.insert(A);
                }
                auto R=make_pair(x.P,(x.S > 0) ? -1 : 1);
                if (!v.count(R)){
                    q.push(R);
                    v.insert(R);
                }
            }
        }
        return -1;
    }
private:
    struct hash {
        inline size_t operator()(const pair<int,int>& x) const { return x.P*100000+x.S; }
    };
};

int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    vector<string> banned={"hit"};
    auto r=s.mostCommonWord("Bob. hit a ball, the hit BALL flew far after it was hit.", banned);
    */
    
    /*
    
    ListNode *head=new ListNode(0);
    head->next=new ListNode(1);
    head->next->next=new ListNode(2);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(4);
    
    
    vector<int> G={0, 3, 1, 4};
    Solution s;
    auto r=s.numComponents(head, G);
    
    */
    
    /*
    Solution s;
    auto r=s.ambiguousCoordinates("(100)");
    */
    
    Solution s;
    auto r=s.racecar(3);
    
    
    return 0;
}


