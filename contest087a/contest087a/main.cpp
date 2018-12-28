/*
 
 Rank       Name            Score   Finish Time     Q1 (3)      Q2 (5)        Q3 (5)    Q4 (8)
 55 / 2687  claytonjwong    13      0:24:32         0:02:33     0:07:36  *1   0:19:32
 
 Q1: https://leetcode.com/problems/backspace-string-compare/description/
 A1: https://leetcode.com/problems/backspace-string-compare/discuss/135604/Straightforward-C++-build-string-and-compare
 
 Q2: https://leetcode.com/problems/longest-mountain-in-array/description/
 A2: https://leetcode.com/problems/longest-mountain-in-array/discuss/135623/Straightforward-C++-with-explanation
 
 Q3: https://leetcode.com/problems/hand-of-straights/description/
 A3: https://leetcode.com/problems/hand-of-straights/discuss/135634/Straightforward-C++-with-explanation
 
 */

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return build(S)==build(T);
    }
private:
    string build(const string& in){
        string out;
        for (auto c: in){
            if (c=='#' && !out.empty())
                out.pop_back();
            else if (isalpha(c))
                out.push_back(c);
        }
        return out;
    }
};
*/

/*
class Solution {
public:
    int longestMountain(vector<int>& A, int ans=0) {
        for (int k=1,i=k,j=k, N=(int)A.size(); k<N-1; ++k,i=k,j=k){
            while (i>0 && A[i-1]<A[i]) --i;
            while (j<N-1 && A[j]>A[j+1]) ++j;
            if (i!=k && j!=k)
                ans=max(ans,j-i+1);
        }
        return ans;
    }
};
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& curr, int W) {
        sort(curr.begin(),curr.end());
        for (vector<int> next; !curr.empty() && curr.size()%W==0; curr.swap(next),next={})
            for (int i=1,k=1,N=(int)curr.size(); i<N; ++i)
                if (k<W && curr[i]==curr[0]+k)
                    ++k;
                else
                    next.push_back(curr[i]);
        return curr.empty();
    }
};


int main(int argc, const char * argv[]) {

    /*
    Solution s;
    vector<int> A{2,1,4,7,3,2,5};
    cout << s.longestMountain(A) << endl;
     */
    
    
    Solution s;
    vector<int> hand{1,2,3,6,2,3,4,7,8}; int W=3;
    cout << s.isNStraightHand(hand, W) << endl;
    
    
    return 0;
}


