/*
 
 735. Asteroid Collision
 
 https://leetcode.com/contest/weekly-contest-60/problems/asteroid-collision/
 
 We are given an array asteroids of integers representing asteroids in a row.
 
 For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
 
 Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
 
 Example 1:
 Input:
 asteroids = [5, 10, -5]
 Output: [5, 10]
 Explanation:
 The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
 Example 2:
 Input:
 asteroids = [8, -8]
 Output: []
 Explanation:
 The 8 and -8 collide exploding each other.
 Example 3:
 Input:
 asteroids = [10, 2, -5]
 Output: [10]
 Explanation:
 The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.
 Example 4:
 Input:
 asteroids = [-2, -1, 1, 2]
 Output: [-2, -1, 1, 2]
 Explanation:
 The -2 and -1 are moving left, while the 1 and 2 are moving right.
 Asteroids moving the same direction never meet, so no asteroids will meet each other.
 Note:
 
 The length of asteroids will be at most 10000.
 Each asteroid will be a non-zero integer in the range [-1000, 1000].
 
 */

/*
 
 pseudo:
 
 create vector<int> res which will be the returned result after all collisions
 
 use cases:
 
 * res is empty, regardless of the curr asteroid value, add it onto res
 * res.back is a positive integer
    * curr asteroid is positive --> no-op
    * curr asteroid is negative --> if abs eq, then pop_back, else process collisions
 * res.back is a negative integer
    * curr asteroid is positive --> if abs eq, then pop_back, else process collisions
    * curr asteroid is negative --> no-op
 
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res{};
        for (auto &&a: asteroids)
            if (res.empty() || !isCollision(res,a)) res.push_back(a);
            else processCollision(res,a);
        return res;
    }
private:
    bool isCollision(vector<int>& v, int x){
        return (v.back()>0 && x<0);
    }
    void processCollision(vector<int>& v, int x){
        while (!v.empty() && isCollision(v,x)){
            if (abs(v.back())>abs(x)) return;
            else if (abs(v.back())==abs(x)) { v.pop_back(); return; }
            else v.pop_back();
        }
        v.push_back(x);
    }
};

int main(int argc, const char * argv[]) {
    
    
    Solution s;
    vector<int> a { 10,5,-5 };
    auto res=s.asteroidCollision(a);
    
    
    
    return 0;
}




