/*
 
 Trailing Zeros - C
 
 https://stackoverflow.com/questions/45270401/trailing-zeros-c/45270720#45270720
 
 */

#include <iostream>

using namespace std;

unsigned tzr(unsigned x)
{
    unsigned n; /* number of bits */
    
    n = 0;
    if (!(x & 0x0000FFFF)) { n += 16; x >>= 16; }
    if (!(x & 0x000000FF)) { n += 8; x >>= 8; }
    if (!(x & 0x0000000F)) { n += 4; x >>= 4; } // won't compile due to missing ;
    if (!(x & 0x00000003)) { n += 2; x >>= 2; } // won't compile due to missing ;
    
    n += (x & 1) ^ 1; // anyway what does this do ?
    
    return n;
}

int main(int argc, const char * argv[]) {

    cout << tzr(9) << endl << endl;
    cout << tzr(8) << endl << endl;
    cout << tzr(4) << endl << endl;
    cout << tzr(2) << endl << endl;
    cout << tzr(1) << endl << endl;
    
    return 0;
}
