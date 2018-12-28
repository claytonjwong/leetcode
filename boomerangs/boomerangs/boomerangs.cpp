/*
 
 447. Number of Boomerangs
 
 https://leetcode.com/problems/number-of-boomerangs/description/
 
 Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
 
 Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
 
 Example:
 Input:
 [[0,0],[1,0],[2,0]]
 
 Output:
 2
 
 Explanation:
 The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 
 */


#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution{
public:
    int numberOfBoomerangs(vector<pair<int,int>>& points){
        int res=0;
        for (auto &p : points){
            unordered_map<int,int> dist(points.size());
            for (auto &q : points){
                int dx = p.first - q.first;
                int dy = p.second - q.second;
                res += 2 * dist[(dx*dx)+(dy*dy)]++;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {

    vector<pair<int,int>> points {
        make_pair(0,0),
        make_pair(0,1),
        make_pair(0,2)
    };
    
    Solution solution;
    cout << solution.numberOfBoomerangs(points) << endl;
    
    
    return 0;
}



