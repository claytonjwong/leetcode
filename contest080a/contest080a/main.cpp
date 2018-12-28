/*
 
 Rank       Name                    Score       Finish Time     Q1 (4)      Q2 (4)      Q3 (6)      Q4 (8)
 3 / 2570   claytonjwong Virtual    22          0:47:40         0:05:40     0:16:14     0:36:32     0:47:40
 
https://leetcode.com/contest/weekly-contest-80/ranking
 
 */



#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

/*
class Solution {
public:
    string mostCommonWord(string p, vector<string>& x) {
        string s,ans;
        for (auto& c: p) c=isalpha(c) ? tolower(c) : ' ';
        istringstream is(p);
        unordered_map<string,int> m;
        unordered_set<string> b(x.begin(),x.end());
        int cnt=0;
        while (is >> s){
            if (!b.count(s) && cnt < ++m[s]){
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
    ListNode* next;
    ListNode(int v) : val{v}, next{nullptr} {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int cnt=0;
        unordered_set<int> S(G.begin(),G.end());
        for (auto itr=head; itr!=nullptr; itr=itr->next){
            if ((S.count(itr->val) && itr->next==nullptr) || (itr->next && S.count(itr->val) && !S.count(itr->next->val)))
                ++cnt;
        }
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
        vector<string> coords;
        int N=(int)s.size();
        if (isValid(s)) coords.push_back(s);
        for (int i=1; i<N; ++i){
            string a=s.substr(0,i),b=s.substr(i,N-i),c=(a+"."+b);
            if (isValid(c)) coords.push_back(c);
        }
        return coords;
    }
    bool isValid(const string& s){
        if (s.size() < 2) return true;
        if (s[0]=='0' && s[1]!='.') return false;
        if (s.find('.')!=string::npos && s.back()=='0') return false;
        return true;
    }
};

*/

#define P first
#define S second
class Solution {
public:
    int racecar(int T) {
        queue<pair<int,int>> q({make_pair(0,1)});
        unordered_set<pair<int,int>,hash> v({q.front()});
        for (int d=0; true; ++d){
            int N=(int)q.size();
            while (N--){
                auto x=q.front(); q.pop();
                if (x.P==T) return d;
                auto A=make_pair(x.P+x.S,x.S*2),R=make_pair(x.P,x.S > 0 ? -1 : 1);
                if (!v.count(A) && abs(A.P-T)<T){
                    q.push(A);
                    v.insert(A);
                }
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
        size_t operator()(const pair<int,int>& x) const { return x.first*100000+x.second; }
    };
};

int main(int argc, const char * argv[]) {

/*
    Solution s;
    string p="Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned={"hit"};
    auto r=s.mostCommonWord(p, banned);
 */
    
    /*
    Solution s;
    ListNode* head=new ListNode(0);
    head->next=new ListNode(1);
    head->next->next=new ListNode(2);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(4);
    vector<int> G={0,2,4};
    auto r=s.numComponents(head, G);
*/
    
    /*
    Solution s;
    auto r=s.ambiguousCoordinates("(123)");
    */
    
    Solution s;
    auto r=s.racecar(6);
    
    return 0;
}
