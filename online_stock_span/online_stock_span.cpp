/*

901. Online Stock Span

Q: https://leetcode.com/problems/online-stock-span/description/
A: https://leetcode.com/problems/online-stock-span/discuss/180323/Straightforward-C++

*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
class StockSpanner{
    struct Stock{
        const int price;
        int span;
        Stock( const int price, const int span = 1 ): price{ price }, span{ span }{}
    };
    vector< Stock > history;
public:
    int next( int price ){
        if ( history.empty()  ||  price < history.back().price ){
            history.emplace_back(  Stock{ price }  );
        } else {
            auto span{ 1 };
            for (;  ! history.empty()  &&  price >= history.back().price;  history.pop_back() )
                span += history.back().span;
            history.emplace_back(  Stock{ price, span }  );
        }
        return history.back().span;
    }
};
*/

class StockSpanner{
    vector< pair<int,int> > history;
public:
    int next( int price ){
        if ( history.empty()  ||  price < history.back().first ){
            history.emplace_back(  make_pair( price, 1 )  );
        } else {
            auto span{ 1 };
            for (;  ! history.empty()  &&  price >= history.back().first;  history.pop_back() )
                span += history.back().second;
            history.emplace_back(  make_pair( price, span )  );
        }
        return history.back().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * \
 * int param_1 = obj.next(price);
 */


int main() {

    StockSpanner ss;

    vector<int> testData{ 100, 80, 60, 70, 60, 75, 85 }, result;

    for_each( testData.begin(), testData.end(), [&]( const auto price ){
        result.push_back( ss.next( price ) );
    });

    ostream_iterator<int> outIt{ cout, "," };
    std::copy( result.begin(), result.end(), outIt );

    return 0;
}