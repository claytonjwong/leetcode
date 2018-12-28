/*
 
 Rank           Name            Score   Finish Time     Q1 (2)    Q2 (6)    Q3 (6)    Q4 (10)
 948 / 3646     claytonjwong    2       0:03:37         0:03:37
 
 */

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return (int)distance(A.begin(),max_element(A.begin(),A.end()));
    }
};
*/

/*
 
 target = 12,
 position = [  10,    8,    0,    5,    3],
    speed = [   2,    4,    1,    1,    3]
 
 hour 1        12    12     1     6     6
 hour 2
 
 use unordered_map to mark nodes to be ignored since they are already part of a representative fleet
 
 
 keep track of the element just larger than self, ( prob use a map )
 if self position + speed > the psotion of the elemtn just larger than self, then delete self
 
 for each hour of simulation,
    position += speed
 
 whenever a non-fleet node position reaches the target ans++, and mark node as included in fleet
 
 use a map which only contains the fleet repreesntative, so node marked as part of a fleet are removed form the map.
 
 map[key=index]=value==pair{position,speed}
 
 if I pass map.upper_bound when my speed is added to my position, then i'm included as part of that fleet I should delete myself from the map based on my current index, and I should mark my index as included in the fleet set
 
 int N
 while (fleet.size() < N)
 for (int i [0:N)
    if i in fleet continue
    process i, by getting upper_bound from map, if != end, then check if current position + speed is >=the mapped value, then this car becomes part of that fleet, add car index into fleet set and remove car from the map based on index
 
    otheriwse if the current position + speed >= target, ans++ and insert car index into fleet and delete car index from map
 
 */


#include <unordered_set>
#include <map>

#define position first
#define speed second

class Solution {
    struct Car {
        int pos,spd,moves;
        Car(int pos, int spd) : pos{pos}, spd{spd}, moves{0} {}
    };
public:
    int carFleet(int target, vector<int>& P, vector<int>& S, int ans=0) {
        if (P.empty()) return 0;
        int N=(int)P.size();
        vector<Car> C;
        for (int i=0; i<N; ++i)
            C.push_back({P[i],S[i]});
        sort(C.begin(),C.end(),[](const Car& lhs, const Car&rhs){ return lhs.pos > rhs.pos; });
        vector<double> A(N);
        for (int i=0; i<N; ++i)
            A[i]=(target-C[i].pos) / (double)C[i].spd;
        for (int i=0,j=0; i<N; i=j){
            double moves = A[i];
            j=i+1;
            while(j<N && A[j]<=moves) ++j;
            ++ans;
        }
        return ans;
    }
};


/*
class ExamRoom {
public:
    ExamRoom(int N) {
        
    }
    
    int seat() {
        
    }
    
    void leave(int p) {
        
    }
private:
    vector<int>
};
*/

/*
 
create a set
 
 add end points     0, N-1
 
 add middle          N/2
 
 
 10
 
 0123456789
 
 path={}
 
 q next { 0, N-1 }
 
 seat ()
 
    if !next.empty()
        res = q.top()
        q.pop()
        curr.insert ( res )
        return res;
 
    for each current internval, calc middles and create next
 
 
 0   and   N-1
 
 for each curr, calc middle between i and i+1 for all elemetns i in curr except the last one
 
 
 
*/
 
/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */

/*
class Solution{
public:
    int carFleet(int target, vector<int>& P, vector<int>& S, int ans=0) {
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    
    //ExamRoom er(10);
    
    
    
    /*
    Solution s;
    
    vector<int> A{0,2,1,0};
    cout << s.peakIndexInMountainArray(A) << endl;
    */
    
    
    Solution s;
    int target = 12; vector<int> pos = {10,8,0,5,3}, spd = {2,4,1,1,3};
    cout << "3==" << s.carFleet(target,pos,spd) << endl;
    
    
    target = 10; pos = {2,4}, spd={3,2};
    cout << "1==" << s.carFleet(target,pos,spd) << endl;
    
    target = 10; pos = {8,3,7,4,6,5}; spd={4,4,4,4,4,4};
    cout << "6==" << s.carFleet(target, pos, spd);
    
    target = 10; pos = {}; spd={};
    cout << "?==" << s.carFleet(target, pos, spd);

    /*
     
     target = 10
     
     pos        2      4
     spd        3      2
     
       0        2      4
       1        5      6
       2        8      8
       3        11    10
     
     
     target = 12,
     position = [  10,    8,    0,    5,    3],
        speed = [   2,    4,    1,    1,    3]
     
          0        10     8     0     5     3
     hour 1        12    12     1     6     6
     hour 2                     2     7     9
     hour 3                     3     8    12
     hour 4                     4     9
     
     
     order by position
     
     position     0      3     5     8     10
       speed      1      3     1     4     2
     
     hour 0       0      3     5      8     10
          1       1      6     6     12     12
          2       2            7
          3       3            8
     
     caclculate # turns
     
     turns       12     3      7      1      1
     
     if you take less turns, but you are same speed or slower than than rhs
     
     
     iterate backwards from N-1 to 0
     keeping track of max so far
     max so far == N-1
     if i-i < max so far,
        update max so far
        increment count
     
     
     
     
     
     
     
     
     for each car, how many turns is it going to take
     to get to the target?
     
                   1      1     12    7    3
     
     
     it takes cars 0 and 1 one hour to both reach the target at the same time
     that is counted as one fleet
     
     at hour 1, car 4 meets up with car 3 and they become a fleet
     
     car 2 never meets up with car 3
     
     so there are 3 fleets, car 0 & 1... and car 2 and car 3
     
     the last car to the finish line is always a fleet, this is the car
     with the maximal amount of moves to reach the finish line
     
     moves to reach finish line is equal to ( target-position ) / speed
     
     
     
     for each car, will it reach another car before it reaches the target?
        if yes, then dont' count this car, it will become part of a fleet
        if not then count this car, it is a fleet representative
     
     
     
     
     
     use a priority queue to see if anyone is ahead of you
     
     position can be the key
     
     
     target = 10
     
     
     position     3,   4
     speed        3    2
     
     
     hour 0       3     4
          1       6     6
          2       9     8
          3      12    10

          ans = 1
     
                i-1   i
     
     # hours     3    3
     
     
     target-positin / speed
     
     10-3=7    ceil(7 / 3) = 3
     
     
     10-4=6   6/2 = 3
     
     
     target 17
     
     [   8,    12,    16,    11,    7]
     
     
     [   6,     9,     10,    9,     7]
     
     
     */
    
    
    return 0;
}
