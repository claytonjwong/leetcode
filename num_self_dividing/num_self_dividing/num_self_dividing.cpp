/*
 
 728. Self Dividing Numbers
 
 https://leetcode.com/contest/weekly-contest-59/problems/self-dividing-numbers/
 
 A self-dividing number is a number that is divisible by every digit it contains.
 
 For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 
 Also, a self-dividing number is not allowed to contain the digit zero.
 
 Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
 
 Example 1:
 Input:
 left = 1, right = 22
 Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 Note:
 
 The boundaries of each input argument are 1 <= left <= right <= 10000.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res{};
        for (int i=left; i<=right; ++i)
            if (selfDividing(i)) res.push_back(i);
        return res;
    }
private:
    bool selfDividing(int n){
        int orig=n;
        while (true){
            if (!(n%10) || orig%(n%10)) return false;
            if (n<10) return true;
            n/=10;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    while(true){
        int m,n;
        cout << "m: ";
        cin >> m;
        cout << "n: ";
        cin >> n;
        auto res=s.selfDividingNumbers(m, n);
        for (auto &&x: res)
            cout << x << "," << endl;
    }
    return 0;
}



