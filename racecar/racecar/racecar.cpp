#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

#define P first
#define S second
using PII = pair< int, int >;
using QPII = queue< PII > ;
class Solution {
    struct hash { size_t operator()( const PII& x ) const {  return x.P*100000+x.S;  } };
public:
    int racecar( int T, QPII q=QPII({ make_pair(0,1) })){
        unordered_set< PII, hash > V({ q.front() });
        for( int d=0,N=(int)q.size(); ;++d,N=(int)q.size() ){
            for( int cur=q.front(); N--; q.pop(),cur=q.front() ){
            
                if( cur.P == T ) return d;
                
                auto A = make_pair( cur.P + cur.S, cur.S * 2 );
                if( V.insert( A ).second && abs( A.P - T ) < T ) // prune A by position
                    q.push( A );
                
                auto R = make_pair( cur.P, ( cur.S > 0 )  ?  -1  :  1 );
                if( V.insert( R ).second )
                    q.push( R );
            }
        }
    }
};

int main() {

    Solution s;
    
    auto result = s.racecar(10);

    return 0;
}
