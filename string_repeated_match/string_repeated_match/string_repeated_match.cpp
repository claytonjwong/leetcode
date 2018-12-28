/*
 
 686. Repeated String Match
 
 https://leetcode.com/contest/leetcode-weekly-contest-52/problems/repeated-string-match/
 
 Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.
 
 For example, with A = "abcd" and B = "cdabcdab".
 
 Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").
 
 Note:
 The length of A and B will be between 1 and 10000.
 
 */

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    
    //
    // TODO: re-write this is ugly code.  AC for contest 52, but needs re-work.
    //
    int repeatedStringMatch(string A, string B) {
        if (A.empty() || B.empty()) { return -1; }
        set<char>setA{A.begin(),A.end()};
        set<char>setB{B.begin(),B.end()};
        if (setA==setB && A.size()==1){
            return (int)B.size();
        }
        if (setA.size()<setB.size()){
            return -1;
        }
        int res=1;
        string prev{},origA(A);
        do{
            if (A.find(B)!=string::npos){
                return res;
            }
            prev=A;
            A=A+origA;
            ++res;
        }while(prev.size()/2<B.size());
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    
    
    
    
    return 0;
}



