/*
 
 853. Car Fleet
 
 https://leetcode.com/problems/car-fleet/description/
 
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/*
 
 use a map to sort the cars by position (key) and track how many moves (value) are needed to reach the target
 
 start at the lead car (right-most car in map sorted in ascending order by position )
 
 if (itr->second > prev(itr)->second) ==> if this is true, then i never runs into i+1 to coalesce into the same fleet
 therefore, increment the answer by 1
 
 otherwise a collision between i and i+1 will occur, keep track of the lead car i+1 which car i just ran into
 and see if other cars run into it as well
 
 */
class Solution {
public:
    int carFleet(int tar, vector<int>& pos, vector<int>& spd, map<int,double> m={}, int ans=1) {
        if (pos.empty()) return 0;
        int N=(int)pos.size();
        for (int i=0; i<N; ++i)
            m[pos[i]]=(tar-pos[i])/(double)spd[i];
        for (auto itr=m.rbegin(); ++itr!=m.rend();)
            if (itr->second <= prev(itr)->second) // i <= i+1, car i runs into car i+1, update lead car for this fleet
                itr->second=prev(itr)->second;
            else
                ++ans; // i takes longer to reach target than i+1, so it is counted as a different fleet
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    //vector<int> pos={10,8,0,5,3},spd={2,4,1,1,3}; int tar=12;
    //vector<int> pos={},spd={}; int tar=10;
    //vector<int> pos={3},spd={3}; int tar=10;
    vector<int> pos={0,4,2},spd={2,1,3}; int tar=10;
    cout << s.carFleet(tar, pos, spd) << endl;
    
    
    return 0;
}


