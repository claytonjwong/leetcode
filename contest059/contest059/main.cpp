/*
 
 Rank           Name            Score   Finish Time     Q1 (3)      Q2 (5)    Q3 (8)    Q4 (8)
 1457 / 2491    claytonjwong    3       0:38:03         0:23:03  3
 
 
 Q1: https://leetcode.com/problems/self-dividing-numbers/description/
 A1: https://leetcode.com/problems/self-dividing-numbers/discuss/133637/Straightforward-C++
 
 Q2: https://leetcode.com/problems/my-calendar-i/description/
 A2: https://leetcode.com/problems/my-calendar-i/discuss/133633/Concise-C++-set
 
 */


#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i=left; i<=right; ++i)
            if (isSelfDiv(i)) ans.push_back(i);
        return ans;
    }
private:
    bool isSelfDiv(int i) const {
        for (int num=i,last=i%10; i>0; i/=10,last=i%10)
            if (last==0 || num%last!=0) return false;
        return true;
    }
};



/*
using PII=pair<int,int>;
using CPII=const PII;
class MyCalendar {
public:
    bool book(int beg, int end) {
        return s.insert({beg,end}).second;
    }
private:
    struct cmp{ bool operator()(CPII& lhs, CPII& rhs) const {
        return rhs.second <= lhs.first;
        
    }};
    set<PII,cmp> s;
};
*/

int main(int argc, const char * argv[]) {
    
    Solution s;
    auto r=s.selfDividingNumbers(1, 22);
    
    /*
    MyCalendar c;
    
    cout << c.book(1,2) << endl;
    cout << c.book(2,3) << endl;
    cout << c.book(10,20) << endl;
    cout << c.book(30,40) << endl;
    cout << c.book(40,50) << endl;
    cout << c.book(20,30) << endl;
    */
    
    /*
    cout << c.book(37,50) << endl;
    cout << c.book(33,50) << endl;
    */
    return 0;
}


