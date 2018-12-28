/*
 
 https://leetcode.com/contest/weekly-contest-93
 
 Q1: https://leetcode.com/problems/binary-gap/description/
 A1: https://leetcode.com/problems/binary-gap/discuss/150931/Straightforward-C++
 
 Q2: https://leetcode.com/problems/reordered-power-of-2/description/
 A2: https://leetcode.com/problems/reordered-power-of-2/discuss/150936/Straightforward-C++-multiset-of-chars
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>

using namespace std;

/*
class Solution {
public:
    int binaryGap(int N, int maxi=0) {
        for (int i=0; i<31; ++i){
            if (N & 1<<i){
                for (int j=i+1; j<32; ++j){
                    if (N & 1<<j){
                        maxi=max(j-i,maxi);
                        break;
                    }
                }
            }
        }
        return maxi;
    }
};
*/
 

/*
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        auto p=to_set(N);
        for (int i=0; i<32; ++i){
            auto q=to_set(1<<i);
            if (p==q)
                return true;
        }
        return false;
    }
private:
    unordered_multiset<int> to_set(int x){
        string s(to_string(x));
        return {s.begin(),s.end()};
    }
};
*/

/*
class Solution {
public:
    bool reorderedPowerOf2(int N, int i=32) {
        for (auto p=to_set(N); --i >= 0;)
            if (p==to_set(1<<i)) return true;
        return false;
    }
private:
    unordered_multiset<int> to_set(int x){
        string s(to_string(x));
        return {s.begin(),s.end()};
    }
};
*/

class Solution {
public:
    bool reorderedPowerOf2(int N, int i=31) {
        for (auto p=to_set(N),q=to_set(1<<i); i >= 0; q=to_set(1<<--i))
            if (p==q) return true;
        return false;
    }
private:
    unordered_multiset<int> to_set(int x){
        string s(to_string(x));
        return {s.begin(),s.end()};
    }
};

/*
 // incorrect solution, and ran out of time
using VI=vector<int>;
class Solution {
public:
    VI advantageCount(VI& A, VI& B) {
        int N=(int)A.size();
        VI ans(N,-1);
        map<int,int> MA;
        for (int i=0; i<N; ++i)
            ++MA[A[i]];
        map<int,vector<int>> MB;
        for (int i=0; i<N; ++i){
            MB[B[i]].push_back(i);
        }
        
        for (auto& v: MB){
            do {
                auto it=upper_bound(MA.begin(),MA.end(),v.first);
                auto idx=v.second.back();
                if (it!=MA.end()){
                    ans[idx]=it->first;
                    --it->second;
                }
                if (it->second==0)
                    MA.erase(it);
            } while (!v.second.empty());
        }
        for (int i=0; i<N; ++i){
            if (ans[i]>=0) continue;
            ans[i]=MA.begin()->first;
            --MA.begin()->second;
            if (MA.begin()->second==0)
                MA.erase(MA.begin());
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    
    Solution s;
    cout << s.reorderedPowerOf2(1) << endl;
    
    return 0;
}
