#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;


 using VI = vector< int >;
 class Solution {
     
     VI original;
     
 public:
     
     Solution( VI nums ) : original{ nums } {}
 
     VI reset() { return original; }
 
     VI shuffle() {
         vector<int> random{ original };
         random_shuffle( random.begin(), random.end() );
         return random;
     }
};
 
/*
using VI = vector< int >;
class Solution {
    VI original;
public:
    Solution( VI nums ) : original{ nums } {}

    VI reset() { return original; }

    VI shuffle() {
        random_device randomDevice;
        mt19937 generator( randomDevice() );
        vector<int> random{ original };
        ::shuffle( random.begin(), random.end(), generator );
        return random;
    }
};
*/

int main() {
    
    VI A = { 1,2,3,4,5,6,7,8,9 };
    
    Solution s{ A };
    
    auto result1 = s.shuffle();
    auto result2 = s.shuffle();
    auto result3 = s.shuffle();
    
    
    return 0;
}
