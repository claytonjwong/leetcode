/*
 
 CCI CH 12.1 Last K Lines: write a method to print the last K lines of an input file using C++
 
 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

int main(int argc, const char * argv[]) {

    
    
    int k = 5;
    
    deque<string> klines;
    
    
    ifstream fin ("/Users/claytonjwong/workspace/xcode/cpp_last_k_lines/cpp_last_k_lines/test.txt");
    
    if (!fin.is_open()){
        cout << "Error: Unable to open file" << endl;
        return -1;
    }
    
    string line;
    while ( getline(fin, line) ){
        
        if (klines.size() == k){ // make room if full
            klines.pop_back();
        }
        klines.push_front(line);
    }
    
    cout << "Last " << k << " lines: " << endl;
    for ( auto kline : klines ){
        cout << kline << endl << endl;
    }
    
    return 0;
}







