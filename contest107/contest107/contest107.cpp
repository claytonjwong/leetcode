/*
 
 https://leetcode.com/contest/weekly-contest-107
 
 Rank           Name            Score   Finish Time     Q1 (4)    Q2 (5)    Q3 (8)    Q4 (8)
 1431 / 3711    claytonjwong    4       0:13:16         0:13:16
 
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <numeric>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        auto i=name.begin(), last=i, j=typed.begin();
        while(  ! ( i == name.end()  &&  j == typed.end() )  ){
            if( *i == *j ){
                last = i;
                advance( i, 1 );
                advance( j, 1 );
            }
            else if( *last == *j )
                advance( j, 1 );
            else
                return false;
        }
        return true;
    }
};
*/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        for( auto i=name.begin(), last=i, j=typed.begin();  ! ( i == name.end()  &&  j == typed.end() ); ){
            if( *i == *j ){
                i = next( last=i );
                j = next( j );
            }
            else if( *last == *j )
                j = next( j );
            else
                return false;
        }
        return true;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    
    string name = "alex", typed = "alexxx";
    
    cout << s.isLongPressedName( name, typed ) << endl;
    
    return 0;
}


/*
#define L first
#define R second
class Solution {
public:
    int minFlipsMonoIncr( string S, int depth=0 ) {
        queue<pair<uint16_t,uint16_t>> q{{{ (uint16_t)S.find_first_of('1'), (uint16_t)S.find_last_of('0') }}};
        
        while( ! q.empty() ){
            
            for( int i{ 0 }, N{ static_cast<int>(q.size()) }; i < N; ++i ){
                
                auto cur{ q.front() }; q.pop();
                
                if( cur.L == numeric_limits<uint16_t>::max() || cur.R == numeric_limits<uint16_t>::max() || cur.R < cur.L ){
                    return depth;
                }
                
                auto
                    flipL{ make_pair( (uint16_t)S.find_first_of('1',cur.L+1), (uint16_t)cur.R ) },
                    flipR{ make_pair( (uint16_t)cur.L, (uint16_t)S.find_last_of('0',cur.R-1) ) };
                
                q.push( flipL );
                q.push( flipR );
            }
            
            ++depth;
        }
        return depth;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    cout << s.minFlipsMonoIncr( "11011" ) << endl;
    
    return 0;
}
 */

/*
int main(int argc, const char * argv[]) {
    
    Solution s;
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    return 0;
}
*/
