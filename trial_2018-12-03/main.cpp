/*
numbers=[2, 7, 11, 15], target=9

numers=[] // empty --> {}

numbers=[1, 7, 11, 15], target=9 // target doesn't exist --> {}

numbers[2,7,2,7], target=9 // --> ?
0 1 2 3

numers[2,-11], target = -9 --> +20 or 2 - 11 = -9

                                               -2, 11 => target =9

m[2] = 0
m[-11] = 1
*/

// O(nlogn) time, O(1) --> sorted solution + binary search O(logn) => 2nlogn

// nlogn + n

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace std;

//vector<int> getIndice(vector<int> nums, int target) {
//    unordered_map<int,int> m;
//    for( int i=0; i < nums.size(); ++i ){ // time O(N), space O(N)
//        int b = target - nums[i]; // -9 - - 11 ==> +11 == 2
//        auto itr = m.find(b);
//        if( itr != m.end() ){
//            return { i, itr->second };
//        }
//        m[ nums[i] ] = i;
//    }
//    return {};
//}

/*
1,2,3,4,5,5,6 // <-- O(n)
i           j


2, 2, 7 = target 9

0, 2
1, 2

2, 2, 7, 7   target = 9
i        j

0,2
0,3

1,2
1,3
*/

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int,int>;

struct myHash{
    std::size_t operator()(const std::pair<int,int>& key) const {
        auto next(key);
        if( next.first > next.second )
            swap( next.first, next.second );
        return ( next.first * 100001 ) + next.second;
    }
};

VVI getIndice(vector<int> nums, int target) {
    VVI ans;
    if( nums.size() < 2 )
        return ans;
    map<int,VI> m;
    for( int i=0; i < nums.size(); ++i ){ // o(n)
        if( m.find( nums[i] ) == m.end() )
            m[ nums[i] ] = {};
        m[ nums[i] ].push_back( i );
    }
    for( int i=0; i < nums.size(); ++i ){ // time O(N), space O(N)
        int b = target - nums[i]; // -9 - - 11 ==> +11 == 2
        auto itr = m.find(b);
        if( itr != m.end() ){
            unordered_set<pair<int,int>,myHash> indices;
            for( const auto index1: itr->second ){
                for( const auto index2: m.find( nums[i] )->second ){
                    indices.insert( { index1, index2 } );
                }
            }
            for( auto indexes: indices){
                ans.push_back( { indexes.first, indexes.second } );
            }
        }
    }
    return ans;
}

int main() {
    VI nums{ 2,2,7,7 };
    auto res = getIndice(nums,9);

    for( auto x: res ){
        copy(x.begin(),x.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}
