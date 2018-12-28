/*
 
 55. Jump Game
 
 Q: https://leetcode.com/problems/jump-game/description/
 A: https://leetcode.com/problems/jump-game/discuss/143388/2-liner-C++-(-EASY-to-understand-)-via-iterative-refactoring
 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 // TLE
class Solution {
public:
    bool canJump(vector<int>& A, unordered_set<int> reach={0}) {
        int N=(int)A.size();
        for (int i=0; i<N; ++i){
            if (reach.find(i)==reach.end()) continue;
            for (int j=i; j<=i+A[i]; ++j)
                reach.insert(j);
            if (reach.find(N-1)!=reach.end())
                return true;
        }
        return reach.find(N-1)!=reach.end();
    }
};
 */

/*
 // AC
class Solution {
public:
    bool canJump(vector<int>& A, int reach=0) {
        for (int i=0,N=(int)A.size(); i<N; ++i){
            if (i>reach)
                return false;
            int next=i+A[i];
            if (next>=reach){
                reach=next;
                if (N-1<=reach)
                    return true;
            }
        }
        return false;
    }
};
*/

/*
 // AC
class Solution {
public:
    bool canJump(vector<int>& A, int reach=0) {
        for (int i=0,N=(int)A.size(); i<N; ++i){
            if (i>reach) return false;
            reach=max(reach,i+A[i]);
            if (N-1<=reach) return true;
        }
        return false;
    }
};
*/

/*
 // AC
class Solution {
public:
    bool canJump(vector<int>& A, int reach=0) {
        for (int i=0,N=(int)A.size(); i<=reach && i<N; ++i)
            if (N-1<=(reach=max(reach,i+A[i]))) return true;
        return false;
    }
};
*/


class Solution {
public:
    bool canJump(vector<int>& A, int reach=0) {
        for (int i=0; i<=reach && i<(int)A.size(); reach=max(reach,i+A[i]),++i);
        return A.size()<=reach+1;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<int> A{0,0};
    cout << s.canJump(A) << endl;
    
    return 0;
}

