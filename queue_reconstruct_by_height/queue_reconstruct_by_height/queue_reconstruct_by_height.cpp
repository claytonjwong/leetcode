/*
 
 406. Queue Reconstruction by Height
 
 https://leetcode.com/problems/queue-reconstruction-by-height/description/
 
 Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
 
 Note:
 The number of people is less than 1,100.
 
 Example
 
 Input:
 [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 
 Output:
 [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 
 
 Solution:
 
 order by h, break h-ties by ordering by k,
 then insert into index k from tallest to shortest.
 
 0     1     2     3     4     5
 [7,0] [7,1]

 [7,0] [6,1] [7,1]
 
 [5,0] [7,0] [6,1] [7,1]
 
 [5,0] [7,0] [5,2] [6,1] [7,1]
 
 [5,0] [7,0] [5,2] [6,1] [4,4] [7,1]
 
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int,int>> res{};
        sort(people.begin(), people.end(),
             [](const pair<int,int>& lhs, const pair<int,int>& rhs){
                 return lhs.first > rhs.first || (lhs.first==rhs.first && lhs.second < rhs.second);
             });
        for (auto next_tallest : people){
            res.insert(res.begin()+next_tallest.second, next_tallest);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {

    vector<pair<int,int>> people = {
        {7,0},
        {4,4},
        {7,1},
        {5,0},
        {6,1},
        {5,2}
    };
    
    Solution solution;
    vector<pair<int,int>> ordered=solution.reconstructQueue(people);
    
    return 0;
}



