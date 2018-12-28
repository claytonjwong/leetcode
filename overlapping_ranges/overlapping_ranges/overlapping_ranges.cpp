/*
 
 Find interval of most overlaps for a collection of min-max ranges
 
 Example ranges: (-2, 4) (0, 3) (2, 8) (5, 8) (6, 10) (7, 9)
 
                                 (-----------)
         (-----------)               (-------)
                 (-----------------------)
 (-----------------------)       (---------------)
 |---|---|---|---|---|---|---|---|---|---|---|---|
 -2      0       2       4       6       8       10
 Maximum:                            (---)
 (7,8) with overlapCount 4
 
 */

/*
 
 #include <iostream>
 #include <vector>
 #include <unordered_map>
 
 using namespace std;
 
class Tuple{
public:
    int val;
    bool isStart;
    
    Tuple(int val, bool isStart) : val{val}, isStart{isStart} {}
    
    bool operator<(const Tuple& rhs) const {
        return val < rhs.val;
    }
};

class Solution{
public:
    
    vector<int> rangeOverlap(vector<vector<int>>& ranges){
        vector<int> range;
        
        int count = 0;
        
        int maxStartIndex = 0;
        int maxEndIndex = 0;
        
        int maxStartCount = 0;
        int maxEndCount = 0;
        
        for ( auto r : ranges ){
            tuples.push_back(Tuple(r[0], true));
            tuples.push_back(Tuple(r[1], false));
        }
        
        sort( tuples.begin(), tuples.end() );
        
        for (int i=0; i < (int)tuples.size(); i++){
            
            if ( tuples[i].isStart ){
                
                count++;
                
                if ( count > maxStartCount ){
                    
                    maxStartCount = count;
                    maxStartIndex = i;
                }
                
            } else { // !tuples.isStart
                
                if ( count > maxEndCount ){
                    
                    maxEndCount = count;
                    maxEndIndex = i;
                }
                
                count--;
                
            }
            
        }
        
        range.push_back(maxStartIndex);
        range.push_back(maxEndIndex);
        
        return range;
    }
    
private:
    vector<Tuple> tuples;
};
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    pair<int,int> maxOverlappingRange(vector<pair<int,int>>& ranges){
        map<pair<int,int>,int> m;
        pair<int,int> maxRange={0,0};
        int overlap=0,maxo=0;
        for (auto &&range: ranges){
            ++m[{range.first,  1}];
            ++m[{range.second,-1}];
        }
        for (auto &&x: m){ // if multiple max overlaps, the right-most will be returned
            if (overlap==maxo && x.first.second==-1){
                maxRange.second=x.first.first;
            }
            overlap+=x.first.second*x.second;
            if (overlap>=maxo && x.first.second==1){
                maxo=overlap;
                maxRange.first=x.first.first;
            }
        }
        return maxRange;
    }    
};

int main(int argc, const char * argv[]) {
    
    
    //(-2, 4) (0, 3) (2, 8) (5, 8) (6, 10) (7, 9)
    
    Solution solution;
    vector<pair<int,int>> ranges = {
        { -2,  4 },
        {  0,  3 },
        {  2,  8 },
        {  6,  9 },
        {  6, 10 },
        {  7,  9 }
    };
    
    pair<int,int> result = solution.maxOverlappingRange(ranges);
    
    cout << "(" << result.first << "," << result.second << ")" << endl;
    
    
    return 0;
}








