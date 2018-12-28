/*
 
 https://leetcode.com/contest/weekly-contest-82
 
 Rank           Name            Score   Finish Time     Q1 (4)          Q2 (5)    Q3 (7)    Q4 (8)
 1053 / 2563    claytonjwong    4       0:22:51         0:17:51  *1
 
 
 Q1: https://leetcode.com/contest/weekly-contest-82/problems/goat-latin/
 A1: https://leetcode.com/problems/goat-latin/discuss/126940/C++-stringstream
 
 Q2: https://leetcode.com/contest/weekly-contest-82/problems/friends-of-appropriate-ages/
 A2: https://leetcode.com/problems/friends-of-appropriate-ages/discuss/127014/C++-solution-with-explanation
 
 Q3: https://leetcode.com/contest/weekly-contest-82/problems/most-profit-assigning-work/
 A3: https://leetcode.com/problems/most-profit-assigning-work/discuss/126999/C++-map
 
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <sstream>
#include <cctype>

using namespace std;

using LL=long long;
using II=pair<int,int>;
using VI=vector<int>;
using VII=vector<vector<int>>;


 // AC
class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        string a="a",s,ans;
        vector<string> res;
        while (ss >> s){
            char c=s[0],v=tolower(c);
            if ( ! (v=='a' || v=='e' || v=='i' || v=='o' || v=='u'))
                res.emplace_back(s.substr(1)+s.substr(0,1));
            else
                res.push_back(s);
            res.back()+="ma";
        }
        for (auto& s: res){
            ans.append(s+a+" ");
            a.push_back('a');
        }
        ans.pop_back();
        return ans;
    }
};


//16,17,18

/*
 // wrong answer
class Solution {
public:
    int numFriendRequests(vector<int>& A) {
        int cnt=0;
        set<int> S(A.begin(),A.end());
        sort(A.begin(),A.end());
        for (int i=1; i<A.size(); ++i){
            int b=A[i-1],a=A[i];
            if (b<=100 || a>=100){
                int smallest=floor(a*0.5+7);
                auto lower=S.upper_bound(smallest),upper=S.lower_bound(a);
                int lowerVal=*lower,upperVal=*upper;
                int dist=distance(lower,upper);
                cnt+=dist;
            }
        }
        return cnt;
    }
};
 */

/*
// AC
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int cnt=0,N=120;
        vector<int> A(N+1); for (auto x: ages) ++A[x];
        for (int i=1; i<=N; ++i){
            for (int j=i; j > floor(0.5*i+7); --j){
                cnt+=A[i]*A[j];
                if (i==j)
                    cnt-=A[i];
            }
        }
        return cnt;
    }
};
*/
 
/*
 // runtime error
class Solution {
public:
    int maxProfitAssignment(vector<int>& D, vector<int>& P, vector<int>& W) {
        int N=10000;
        vector<int> dp(N+1);
        map<int,int> M;
        for (int i=0; i<D.size(); ++i)
            M[D[i]]=max(M[D[i]],P[i]);
        int profit=0;
        for (int i=1; i<=N; ++i){
            if (M.find(i)!=M.end())
                profit=max(profit,M[i]);
            dp[i]=profit;
        }
        int total=0;
        for (auto w: W){
            int curr=dp[w];
            total+=curr;
        }
        return total;
    }
};
 */


/*
 // AC
class Solution {
public:
    int maxProfitAssignment(vector<int>& D, vector<int>& P, vector<int>& W) {
        map<int,int> M;
        for (int i=0; i<D.size(); ++i)
            M[D[i]]=max(M[D[i]],P[i]);
        for (auto prev=M.begin(),curr=next(prev); curr!=M.end(); ++prev,curr=next(prev))
            if (curr->second < prev->second)
                curr->second = prev->second;
        int profit=0;
        for (auto w: W)
            if (M.upper_bound(w)!=M.begin())
                profit+=prev(M.upper_bound(w))->second;
        return profit;
    }
};
 */

/*
 D={66, 1,28,73,53,35,45,60,100,44,59,94,27,88, 7,18,83,18, 72,63},
 P={66,20,84,81,56,40,37,82, 53,45,43,96,67,27,12,54,98,19, 47,77},
 W={61,33,68,38,63,45, 1,10, 53,23,66,70,14,51,94,18,28,78,100,16};
    84 84 84 84 84 84 20 20  84 20 84 84 20 84 98
 */



int main(int argc, const char * argv[]) {

    Solution s;
    
    
    string S="The quick brown fox jumped over the lazy dog";
    cout << s.toGoatLatin(S) << endl;

    
    
    /*
    vector<int> ages={16,17,18};
    auto r=s.numFriendRequests(ages);
    */
    
    /*
    vector<int> D = {68,35,52,47,86},
                P = {67,17, 1,81, 3},
                W = {92,10,85,84,82};
    auto r=s.maxProfitAssignment(D, P, W);
    cout << r << endl;
    */
    
   /*
    vector<int>
    D= {64448,79457,42016,11665,2469,91969,46731,54320,5882,93835,21708,50277,16955,45755,72327,12268,15839,18850,10936,86865,31179,70806,862,89380,85395,37685,35989,22400,65446,89518,87777,70913,94050,19520,32338,6472,5200,80772,51039,17062,50872,15560,72431,78446,60361,6777,31654,21757,14900,97226},
    P= {55170,24810,99019,14644,60739,86776,3656,85057,88453,42411,63691,60967,64863,28688,57126,98045,43420,1719,81693,43774,89525,86382,83018,5553,3184,1542,40108,39794,79829,30024,96082,41089,60930,38049,63082,94078,7062,33691,18438,35911,30367,21478,97103,32558,53184,24942,53365,48591,38949,88794},
    W= {1934,65871,592,76268,61862,74422,53430,95603,70312,43409,30258,54173,99791,21407,42909,96179,64854,77416,24428,68409,21827,4982,72940,99041,52118,94881,31780,84764,7679,56624,41536,87404,39901,61306,81696,61301,46775,19110,95183,84615,2265,56050,69873,14041,41356,18511,15227,5037,23642,36803};
    */
    
    /*
    vector<int>
    D={66, 1,28,73,53,35,45,60,100,44,59,94,27,88, 7,18,83,18, 72,63},
    P={66,20,84,81,56,40,37,82, 53,45,43,96,67,27,12,54,98,19, 47,77},
    W={61,33,68,38,63,45, 1,10, 53,23,66,70,14,51,94,18,28,78,100,16};
     */
    
    /*
    auto r=s.maxProfitAssignment(D, P, W);
    cout << r << endl;
    */
    
    return 0;
}



