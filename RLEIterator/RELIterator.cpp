/*

900. RLE Iterator

Q: https://leetcode.com/problems/rle-iterator/description/
A: https://leetcode.com/problems/rle-iterator/discuss/169584/C++-solution-using-std::queue

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Element
{
    int value{ 0 }, count{ 0 };

    Element ( int value, int count ) :
    value{ value },
    count{ count }
    {
    }
};

class RLEIterator
{
public:
    RLEIterator ( vector<int> A )
    {
        for ( size_t index{ 1 };  index < A.size();  index += 2 )
        {
            Element element{ A[ index ], A[ index - 1 ] };

            if ( element.count > 0 )
            {
                myQueue.push(element);
            }
        }
    }

    int next( int distance )
    {
        int lastValue{ 0 };
        while ( ! myQueue.empty() && myQueue.front().count <= distance )
        {
            distance -= myQueue.front().count;
            lastValue = myQueue.front().value;
            myQueue.pop();
        }

        if ( distance == 0 )
        {
            return lastValue;
        }
        else if ( myQueue.empty()  &&  distance > 0 )
        {
            return -1;
        }
        else
        {
            myQueue.front().count -= distance;
            return myQueue.front().value;
        }
    }

private:

    queue< Element > myQueue;

};


/*
struct Element {
    int value{ 0 }, count{ 0 };
    Element ( int value, int count ) : value{ value }, count{ count } {}
};

class RLEIterator {
    queue< Element > myQueue;
public:
    RLEIterator ( vector<int> A ) {
        for (size_t index{1}; index < A.size(); index += 2) if (A[index - 1] > 0)
            myQueue.push( Element{A[index], A[index - 1]} );
    }

    int next ( int distance, int lastValue = 0 ) {
        for (; ! myQueue.empty() && myQueue.front().count <= distance;  myQueue.pop() )
            lastValue = myQueue.front().value, distance -= myQueue.front().count;

        if ( distance == 0 )
            return lastValue;
        else if ( myQueue.empty()  &&  distance > 0 )
            return -1;
        else
            myQueue.front().count -= distance;

        return myQueue.front().value;
    }
};
*/

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */

int main() {

    vector< int > A{ 3,8, 0,9, 2,5 };
    RLEIterator it{ A };
    vector< int > result;
    result.push_back( it.next(2) );
    result.push_back( it.next(1) );
    result.push_back( it.next(1) );
    result.push_back( it.next(2) );


    for ( const auto& value: result )
    {
        cout << value << ", ";
    }
    cout << endl;

    return 0;
}