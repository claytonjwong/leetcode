#include <iostream>
#include <sstream>
#include <iterator>
#include <set>

using namespace std;

int main() {

    set< unsigned int > S = { 1,2,3,4,5 };
    ostringstream outStream;
    copy( S.begin(), S.end(), ostream_iterator< unsigned int >( outStream, "," ));
    string result( outStream.str() );
    result.pop_back();

    cout << result << endl;

    return 0;
}