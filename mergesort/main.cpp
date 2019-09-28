#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector< int >;
    VI mergesort( VI& A ){
        return go(  move( A ) );
    }
private:
    VI go( VI&& A ){
        auto N = static_cast< int >( A.size() );
        if( N < 2 )
            return A;
        auto pivot = A.begin() + ( N / 2 );
        auto L = go({ A.begin(), pivot }),
             R = go({ pivot, A.end() });
        return merge( L, R );
    }
    VI merge( VI& A, VI& B, VI res={} ){
        auto a = A.begin(),
             b = B.begin();
        while( a != A.end() && b != B.end() ){
            if( *a < *b )
                res.push_back( *a++ );
            else
                res.push_back( *b++ );
        }
        res.insert( res.end(), a, A.end() );
        res.insert( res.end(), b, B.end() );
        return res;
    }
};

int main() {
    Solution::VI A{ 3,5,7,1,3,9,2,0 };
    auto ans = Solution().mergesort( A );
    copy( ans.begin(), ans.end(), ostream_iterator< int >( cout, " " ) );
    return 0;
}
