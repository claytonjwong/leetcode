/*
 
 https://leetcode.com/contest/weekly-contest-87
 
 Rank         Name            Score   Finish Time     Q1 (3)        Q2 (5)       Q3 (5)      Q4 (8)
 769 / 3029   claytonjwong    13      1:47:54         0:12:50  *1   0:40:34  2   1:22:54  2
 
 Q1: https://leetcode.com/problems/backspace-string-compare/description/
 A1: https://leetcode.com/problems/backspace-string-compare/discuss/135604/Straightforward-C++
 
 Q2: https://leetcode.com/problems/longest-mountain-in-array/description/
 A2: https://leetcode.com/problems/longest-mountain-in-array/discuss/135623/Straightforward-C++-with-explanation
 
 Q3: https://leetcode.com/problems/hand-of-straights/description/
 A3: https://leetcode.com/problems/hand-of-straights/discuss/135634/Straightforward-C++-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return process(S)==process(T);
    }
private:
    const string process(const string& in){
        string out;
        for (auto c: in)
            if (c=='#' && !out.empty())
                out.pop_back();
            else if (isalpha(c))
                out.push_back(c);
        return out;
    }
};
*/

/*
class Solution {
public:
    int longestMountain(vector<int>& A, int ans=0) {
        for (int k=1,i=k,j=k,N=(int)A.size(); k<N-1; ++k,i=k,j=k){
            while (i>0 && A[i-1]<A[i]) --i;
            while (j<N-1 && A[j]>A[j+1]) ++j;
            if (!(i==j || i==k || j==k))
                ans=max(ans,j-i+1);
        }
        return ans;
    }
};
*/


class Solution {
public:
    bool isNStraightHand(vector<int>& A, int W, unordered_set<int> V={}) {
        sort(A.begin(),A.end());
        for (int i=0,k=1,N=(int)A.size(); i<N; ++i,k=1){
            if (!V.insert(i).second) continue; // continue if already visisted
            for (int j=i+1; k<W && j<N; ++j)
                if (V.find(j)==V.end() && A[j]==A[i]+k){
                    ++k;
                    V.insert(j);
                }
            if (k!=W) return false;
        }
        return true;
    }
};



int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    string S="y#fo##f", T="y#f#o##f";
    cout << s.backspaceCompare(S,T) << endl;
    */
    
    /*
     
     y#fo##f
     y#f#o##f
     
     */
    
    /*
    Solution s;
    vector<int> A{0,1,2,3,4,5,4,3,2,1,0};
    //vector<int> A{2,1,4,7,3,2,5};
    //vector<int> A{2,2,1};
    //vector<int> A{2,2,2};
    //vector<int> A{2,3};
    cout << s.longestMountain(A) << endl;
    */
    
    
    Solution s;
    //vector<int> hand{1,2,3,6,2,3,4,7,8}; int W=3;
    //vector<int> hand{1,2,3,4,5}; int W=4;
    vector<int> hand{2,1}; int W=2;
    cout << s.isNStraightHand(hand, W) << endl;
    
    
    return 0;
}



