/*
 
 CCI CH 5.6 Conversion:  Write a function to determine the number of bits you would need to flip to convert integer a to integer b
 
 */


#include <iostream>
#include <bitset>


using namespace std;

int bits_to_convert(int a, int b){
    
    return (int)bitset<32>( a ^ b ).count();
}

int main(int argc, const char * argv[]) {

    int a,b;
    while ( true ){
        
        cout << "Enter a and b: " << endl;
        cin >> a;
        cin >> b;

        cout << bits_to_convert(a, b) << endl;
    }
    
    return 0;
}




