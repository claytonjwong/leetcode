#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


using VI = vector< int >;
class Solution
{
public:

    VI searchRange( VI& A, int target )
    {
        auto pair = equal_range( A.cbegin(), A.cend(), target );
        return( pair.first == pair.second )
            ? VI{ -1, -1 }
            : VI{ static_cast< int >( distance( A.cbegin(), pair.first ) ),
                  static_cast< int >( distance( A.cbegin(), prev(pair.second) ) ) };
    }

};

int main()
{
    Solution s;
    VI A{ 5,7,7,8,8,10 };
    auto result = s.searchRange( A, 7 );
    cout << result[0] << ", " << result[1] << endl;
    return 0;
}