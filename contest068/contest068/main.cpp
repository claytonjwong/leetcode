/*
 
 https://leetcode.com/contest/weekly-contest-68
 
 Rank       Name            Score	Finish Time 	Q1 (2)      Q2 (5)      Q3 (4)          Q4 (5)      Q5 (12)
 838 / 2592	claytonjwong 	6       1:12:18         0:08:55                 1:07:18  1
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>


using namespace std;

/*
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
        for (int c=1; c<m[0].size(); ++c)
            for (int r=(int)m.size()-1; r>0; --r)
                if (m[r-1][c-1]!=m[r][c]) return false;
        return true;
    }
};
*/

#include <sstream>
#include <queue>
#include <unordered_map>

class Solution{
public:
    string reorganizeString(string S){
        unordered_map<char,int> m;
        for (const auto& c: S) ++m[c];
        priority_queue<pair<char,int>,vector<pair<char,int>>,Comp> q(m.begin(), m.end());
        stringstream ss;
        while(q.size() > 1){
            auto a=q.top(); q.pop();
            auto b=q.top(); q.pop();
            ss << a.first << b.first;
            --a.second; --b.second;
            if (a.second) q.push(a);
            if (b.second) q.push(b);
        }
        if (q.size()==1 && q.top().second==1 && q.top().first != ss.str().back()){
            ss << q.top().first;
            q.pop();
        }
        return q.empty() ? ss.str() : "";
    }
private:
    class Comp {
    public:
        bool operator()(const pair<char,int>& lhs, const pair<char,int>& rhs){
            return lhs.second < rhs.second;
        }
    };
};

/*
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int seed=0,cnt=0;
        set<int> visited;
        for (int i=0; i<A.size(); ++i){
            visited.insert(A[i]);
            if (A[i]==seed){
                ++cnt;
                seed=1+*max_element(visited.begin(), visited.end());
            }
        }
        return cnt;
    }
};
 */

/*
 
 Input:
 [1,4,3,6,0,7,8,2,5]
  0 1 2 3 4 5 6 7 8
 Output:
 3
 Expected:
 1
 
 
 */

/*
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int cnt=0;
        set<int> v;
        for (int i=0; i<A.size(); ++i){
            v.insert(A[i]);
            if (setContains(v, i)) ++cnt;
        }
        return cnt;
    }
private:
    bool setContains(const set<int> &v, int n){
        for (int i=0; i<=n; ++i) if (v.find(i)==v.end()) return false;
        return true;
    }
};
*/

/*
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int cnt=0;
        set<int> v;
        for (int i=(int)A.size(); i>=0; --i){
            v.insert(A[i]);
            if (*v.begin()==i) ++cnt;
        }
        return cnt;
    }
};
*/

int main(int argc, const char * argv[]) {

    /*
    Solution s;
    vector<vector<int>> m
    {   {0,2,3,4},
        {5,1,2,3},
        {9,5,1,2}};
    cout << s.isToeplitzMatrix(m) << endl;
    */
    
    /*
    Solution s;
    string S;
    while(cin>>S) cout << s.reorganizeString(S) << endl;
    */
    /*
    Solution s;
    string S="vvvlo";
    cout << s.reorganizeString(S) << endl;
    */
    
    /*
    //vector<int> v { 1,4,3,6,0,7,8,2,5 };
    vector<int> v{1,0,2,3,4};
    Solution s;
    
    cout << s.maxChunksToSorted(v) << endl;
    */
    
    Solution s;
    while(true){
        string str;
        cout << "s: "; cin >> str;
        cout << s.reorganizeString(str) << endl;
    }
    
    return 0;
}



