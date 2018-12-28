/*
 
 860. Lemonade Change
 
 Q: https://leetcode.com/problems/lemonade-change/description/
 A: https://leetcode.com/problems/lemonade-change/discuss/144199/Straightforward-C++-(-EASY-to-understand-)-with-explanation
 
 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills, unordered_map<int,int> m={}) {
        for (auto b: bills){
            ++m[b];
            if (b==10 && --m[5]<0)
                return false;
            else if (b==20){
                if (m[5]>0 && m[10]>0)
                    --m[5],--m[10];
                else if (m[5]>2)
                    m[5]-=3;
                else
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    vector<int> bills{5,5,5,5,5,5,5,5,5,20,20};
    cout << s.lemonadeChange(bills) << endl;


    return 0;
}
