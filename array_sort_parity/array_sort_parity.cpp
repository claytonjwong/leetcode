#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity ( vector<int>& A, list<int> parity={} ){
        for_each( A.begin(), A.end(), [&]( const auto value ){
            if ( value % 2 == 0 ){
                parity.push_front( value );
            } else {
                parity.push_back( value );
            }
        });
        return { parity.begin(), parity.end() };
    }
};

int main() {
    Solution s;


    return 0;
}