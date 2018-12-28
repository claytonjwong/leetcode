/*
 
 https://leetcode.com/contest/weekly-contest-85
 
Rank        Name            Score   Finish Time     Q1 (3)          Q2 (6)    Q3 (7)    Q4 (10)
443 / 2531  claytonjwong    9       1:04:46         0:31:45  *1     0:59:46
 
 
 Q1: https://leetcode.com/problems/rectangle-overlap/description/
 A1: https://leetcode.com/problems/rectangle-overlap/discuss/132594/C++-verbose-and-straightforward
 
 Q2: https://leetcode.com/problems/push-dominoes/description/
 A2: https://leetcode.com/problems/push-dominoes/discuss/132600/Straightforward-C++-with-explanation
 
 */

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    bool isRectangleOverlap(vector<int>& a, vector<int>& b) {
        int x1=a[0],y1=a[1],x2=a[2],y2=a[3];
        int x3=b[0],y3=b[1],x4=b[2],y4=b[3];
        return ((
                (x1 < x3&&x3 < x2) || (x1 < x4&&x4 < x2) ||
                (x3 < x1&&x1 < x4) || (x3 < x2&&x2 < x4)
                ) && (
                (y1 < y3&&y3 < y2) || (y1 < y4&&y4 < y2) ||
                (y3 < y1&&y1 < y4) || (y3 < y2&&y2 < y4)
                ));
    }
};
 */

class Solution {
public:
    string pushDominoes(string D) {
        pair<int,char> last{0,'L'};
        int k=(int)D.find_first_of("LR",0);
        while (k!=string::npos){
            if (last.second==D[k])
                for (int i=last.first; i<k; ++i) D[i]=D[k];
            if (last.second!=D[k] && D[k]=='L')
                for (int i=last.first,j=k; i<j;) D[i++]='R',D[j--]='L';
            last={k,D[k]};
            k=(int)D.find_first_of("LR",k+1);
        }
        if (last.second=='R' && D.back()=='.')
            for (int j=last.first+1; j<(int)D.size(); ++j) D[j]='R';
        return D;
    }
};

int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    vector<int> rec1 = {7,8,13,15}, rec2 = {10,8,12,20};
    cout << s.isRectangleOverlap(rec1, rec2) << endl;
    */
//Input: ""
//Output: "LL.RR.LLRRLL.."
    Solution s;
    string str="LL.RR.LLRRLL..";
    cout << s.pushDominoes(str) << endl;
    
    return 0;
}
