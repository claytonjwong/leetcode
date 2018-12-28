/*
 
 https://leetcode.com/contest/weekly-contest-68
 
 Rank           Name            Score   Finish Time     Q1 (2)    Q2 (5)      Q3 (4)      Q4 (5)
 325 / 2592     claytonjwong    11      1:03:44         0:05:06   0:25:01    0:58:44 *1
 
 
 Q1: https://leetcode.com/problems/toeplitz-matrix/description/
 A1: https://leetcode.com/problems/toeplitz-matrix/discuss/113424/4-liner-C++
 
 Q2: https://leetcode.com/problems/reorganize-string/description/
 A2: https://leetcode.com/problems/reorganize-string/discuss/113426/C++-priority_queue-with-explanation-(EASY-to-understand)
 
 Q3: https://leetcode.com/problems/max-chunks-to-make-sorted/description/
 A3: https://leetcode.com/problems/max-chunks-to-make-sorted/discuss/127797/C++-priority-queue
 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

/*
 // AC
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& A) {
        for (int M=(int)A.size(),N=(int)A[0].size(),i=1; i<M; ++i)
            for (int j=1; j<N; ++j)
                if (A[i-1][j-1]!=A[i][j]) return false;
        return true;
    }
};
*/

/*
 // AC
class Solution{
public:
    string reorganizeString(string S){
        unordered_map<char,int> m;
        for (const auto& c: S) ++m[c];
        priority_queue<pair<char,int>,vector<pair<char,int>>,Comp> q(m.begin(), m.end());
        ostringstream os;
        while(q.size() > 1){
            auto a=q.top(); q.pop();
            auto b=q.top(); q.pop();
            os << a.first << b.first;
            if (--a.second) q.push(a);
            if (--b.second) q.push(b);
        }
        if (q.size()==1 && q.top().second==1){
            os << q.top().first;
            q.pop();
        }
        return q.empty() ? os.str() : "";
    }
private:
    class Comp {
    public:
        bool operator()(const pair<char,int>& lhs, const pair<char,int>& rhs) const {
            return lhs.second < rhs.second;
        }
    };
};
*/

/*
 // wrong answer [2,0,1]
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int cnt=0;
        auto itr=A.rbegin();
        do {
            ++cnt;
            itr=is_sorted_until(itr,A.rend());
        } while ( itr != A.rend() );
        return cnt;
    }
};
 */

/*
 // AC set
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int cnt=0;
        unordered_set<int> missing,found;
        for (int i=0; i<A.size(); ++i){
            found.insert(A[i]);
            if (found.find(i)==found.end())
                missing.insert(i);
            else
            {
                for (auto x: found)
                    missing.erase(x);
            }
            if (missing.empty())
                ++cnt;
        }
        return cnt;
    }
};
 */

// AC pq
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int cnt=0;
        priority_queue<int,vector<int>,cmp> V;
        for (int i=0; i<A.size(); ++i){
            V.push(A[i]);
            if (i >= V.top())
                ++cnt;
        }
        return cnt;
    }
private:
    struct cmp {
        bool operator()(const int& lhs, const int& rhs) const {
            return lhs < rhs;
        }
    };
};

int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    vector<vector<int>> A={
        //{1,2,3,4},{5,1,2,3},{9,5,1,2},
        {1,2},{2,2},
    };
    cout << s.isToeplitzMatrix(A) << endl;
    */
    
    /*
    Solution s;
    while (true){
        cout << "s: ";
        string S;
        cin >> S;
        cout << "output: " << s.reorganizeString(S) << endl << endl;
    }
    */
    
    
    Solution s;
    vector<int> A={1,0,2,3,4};
    cout << s.maxChunksToSorted(A) << endl;
    
     
    return 0;
}
