/*
 
 Rank           Name            Score   Finish Time     Q1 (4)          Q2 (6)      Q3 (8)    Q4 (9)
 343 / 2554     claytonjwong    10      1:04:36         0:14:23  1      0:54:36  1
 
 Q1: https://leetcode.com/problems/non-decreasing-array/description/
 A1: https://leetcode.com/problems/non-decreasing-array/discuss/106835/Very-easy-to-understand-C++
 
 Q2: https://leetcode.com/problems/path-sum-iv/description/
 A2: https://leetcode.com/problems/path-sum-iv/discuss/132574/C++-vector-of-size-32
 */

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    bool checkPossibility(vector<int>& A) {
        auto i=is_sorted_until(A.begin(),A.end());
        if (i==A.end()) return true;
        int j=*i;
        *i=*prev(i);
        if (is_sorted(A.begin(),A.end())) return true;
        *prev(i)=*i=j;
        return is_sorted(A.begin(),A.end());
    }
};
*/

/*
class Solution {
public:
    int pathSum(vector<int>& A, vector<int> T=vector<int>(32,-1), int ans=0) {
        if (A.size()==1) return A[0]%10;
        for (auto k: A){
            int D=k/100,P=k%100/10,V=k%10,i=(1<<(D-1))-1+P-1;
            T[i]=V;
        }
        for (int i=31; i>0; --i){
            if (isLeaf(i,T))
                ans+=go(i,T);
        }
        return ans;
    }
private:
    int L(int i, vector<int>& T) {
        if (i>=15) return -1;
        return T[(i<<1)+1];
    }
    int R(int i, vector<int>& T) {
        if (i>=15) return -1;
        return T[(i<<1)+2];
    }
    bool isLeaf(int i, vector<int>& T) {
        if (T[i]==-1) return false;
        if (L(i,T)==-1 && R(i,T)==-1) return true;
        return false;
    }
    int go(int i, vector<int>& T) {
        if (i==0) return T[0];
        return T[i]+go(i%2==1 ? (i>>1) : (i>>1)-1, T);
    }
};
*/

class Solution {
public:
    int pathSum(vector<int>& A, vector<int> T=vector<int>(32,-1), int ans=0) {
        if (A.size()==1) return A[0]%10;
        for (auto k: A) T[(1<<((k/100)-1))-1+(k%100/10)-1]=k%10;
        for (int i=31; i>0; --i) if (isLeaf(i,T)) ans+=go(i,T);
        return ans;
    }
private:
    int L(int i, vector<int>& T) { if (i>=15) return -1; else return T[(i<<1)+1]; }
    int R(int i, vector<int>& T) { if (i>=15) return -1; else return T[(i<<1)+2]; }
    bool isLeaf(int i, vector<int>& T) {
        return (T[i]!=-1 && L(i,T)==-1 && R(i,T)==-1) ? true : false;
    }
    int go(int i, vector<int>& T) {
        return (i==0) ? T[0] : T[i]+go(i%2==1 ? (i>>1) : (i>>1)-1, T);
    }
};


int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    vector<int> A={1,2,3,4,5,5,4,3,2,1};
    cout << s.checkPossibility(A) << endl;
    */
    
    
    Solution s;
    vector<int> A={113};
    cout << s.pathSum(A) << endl;
    
    return 0;
}


