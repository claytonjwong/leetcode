/*
 
 683. K Empty Slots
 
 https://leetcode.com/problems/k-empty-slots/description/
 
 There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.
 
 Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.
 
 For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.
 
 Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.
 
 If there isn't such day, output -1.
 
 Example 1:
 Input:
 flowers: [1,3,2]
 k: 1
 Output: 2
 Explanation: In the second day, the first and the third flower have become blooming.
 Example 2:
 Input:
 flowers: [1,2,3]
 k: 1
 Output: -1
 Note:
 The given array will be in the range [1, 20000].
 
 */


#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int delta=k+1;
        set<int> blooms{};
        for (int i=0; i<flowers.size(); ++i){
            int day=i+1, position=flowers[i];
            blooms.insert(position);
            auto neighbor=blooms.equal_range(position);
            if (neighbor.first!=blooms.begin()){
                int left=*(--neighbor.first);
                if (position-left==delta){ return day; }
            }
            if (neighbor.second!=blooms.end()){
                int right=*(neighbor.second);
                if (right-position==delta){ return day; }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {

    vector<int> flowers { 1, 3, 2 };
    Solution solution;
    cout << solution.kEmptySlots(flowers, 1) << endl;
    
    return 0;
}








