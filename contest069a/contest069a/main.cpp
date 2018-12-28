/*
 
 Rank           Name            Score   Finish Time     Q1 (2)    Q2 (5)    Q3 (7)    Q4 (7)
 132 / 2573     claytonjwong    14      0:47:47         0:01:56   0:08:04   0:47:47
 
 https://leetcode.com/contest/weekly-contest-69
 
 Q1: https://leetcode.com/problems/jewels-and-stones/description/
 A1: https://leetcode.com/problems/jewels-and-stones/discuss/137106/Straightforward-C++
 
 Q2: https://leetcode.com/problems/global-and-local-inversions/description/
 A2: https://leetcode.com/problems/global-and-local-inversions/discuss/137110/3-liner-Straightforward-C++-with-explanation
 
 Q3: https://leetcode.com/problems/sliding-puzzle/description/
 A3: https://leetcode.com/problems/sliding-puzzle/discuss/137108/Straightforward-C++-BFS
 
 */

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>

using namespace std;

/*
class Solution {
public:
    int numJewelsInStones(string J, string S, int ans=0) {
        unordered_set<char> jewel(J.begin(),J.end());
        for (auto c: S)
            if (jewel.find(c)!=jewel.end())
                ++ans;
        return ans;
    }
};
*/

/*
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i=0,N=(int)A.size(); i<N; ++i){
            if (abs(A[i]-i) > 1 ) return false;
        }
        return true;
    }
};
*/

class Solution {
    map<int,set<int>> m{
        {0,{1,3}},{1,{0,2,4}},{2,{1,5}},{3,{0,4}},{4,{1,3,5}},{5,{2,4}},
    };
    unordered_set<string> v;
public:
    int slidingPuzzle(vector<vector<int>>& B) {
        string s=to_string(B[0][0])+to_string(B[0][1])+to_string(B[0][2])+
                 to_string(B[1][0])+to_string(B[1][1])+to_string(B[1][2]);
        queue<string> q({s});
        for (int depth=0; !q.empty(); ++depth){
            int N=(int)q.size();
            while (N--){
                auto curr=q.front(); q.pop();
                if (curr=="123450")
                    return depth;
                int i=(int)curr.find('0');
                for (auto j: m[i]){
                    string next(curr);
                    swap(next[i],next[j]);
                    if (v.insert(next).second)
                        q.push(next);
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> B{
        {3,2,4,},
        {1,5,0,},
    };
    Solution s;
    cout << s.slidingPuzzle(B) << endl;
    return 0;
}

