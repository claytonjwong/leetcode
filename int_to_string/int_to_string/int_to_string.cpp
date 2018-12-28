/*
 
 Implement a function that given an integer number num, it returns the a string representation of the number, comma separated.
 i.e. f(1234) = “1,234”
 
 */

#include <iostream>
#include <string>

using namespace std;

string to_str(int n){
    
    if (n < 1000){
        return to_string(n);
    }
    
    return to_str(n / 1000) + "," + to_string(n % 1000);
}


int main(int argc, const char * argv[]) {
    
    
    cout << "1,234,567,890 == " << to_str(1234567890) << endl;
    
    
    
    
    return 0;
}




