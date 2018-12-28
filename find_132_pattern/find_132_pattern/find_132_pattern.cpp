/*
 
 
 
 */

#include <iostream>
#include <vector>

using namespace std;

// wrong answer
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        return false;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    //vector<int> nums { 3,5,0,3,4 };
    //vector<int> nums { 3,1,4,2 };
    //vector<int> nums { 1,2,3,4 };
    vector<int> nums { -2,1,2,-2,1,2 };
    cout << s.find132pattern(nums) << endl;
    
    return 0;
}
