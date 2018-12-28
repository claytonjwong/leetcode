/*
 
 Once in a tram
 
 https://www.hackerrank.com/contests/w34/challenges/once-in-a-tram

 One day, Jack was going home by tram. When he got his ticket, he noticed that number on the ticket was not lucky. A lucky ticket is a six-digit number on the ticket in which sum of the first three digits is equal to the sum of the last three digits.
 
 For example, number 165912 is lucky because sum of 1+6+5=12, and 9+1+2=12.
 
 Since the number on the ticket wasn't lucky, Jack needs your help to find the next lucky ticket number.
 
 For example, if Jack's ticket number is 165901, then the next lucky ticket number is 165903.
 
 Given Jack's current ticket number, find and print the next lucky ticket number.
 
 Input Format
 
 The first line contains an integer, , denoting the  number on the ticket.
 
 Constraints
 
 Output Format
 
 For the given input find and print the next lucky ticket number.
 
 Sample Input 0
 
 555555
 Sample Output 0
 
 555564
 Explanation 0
 
 After 555555 the first lucky number is 555564, where the sum of first three digits  is equal to the sum of last three digits .
 
 */



#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Solution{
public:
    string next_lucky_ticket(int ticket){

        // 543210 10 power index
        // 123456 ticket ==> 123456 / 1000 = 123
        //                   123456 % 1000 = 456
        //
        int mod_div_by = (int)pow(10,3);
        
        // bounds check, 10^5 <= ticket <= 10^6-2
        if ( ticket < (int)pow(10,5) || ticket > (int)pow(10,6)-2){
            return "";
        }
        

        // calculate initial beginning sum, and update it only when beg
        // has changed from the sequential ticket number incrementing
        int beg = (int)(ticket / mod_div_by);
        int bsum = 0;
        while ( beg > 0 ){
            bsum += beg % 10;
            beg /= 10;
        }
        
        int esum;
        do {
            
            // increment ticket sequentially until beginning sum equals the ending sum
            esum = 0;
            int temp = ++ticket % mod_div_by;
            while ( temp > 0 ){
                esum += temp % 10;
                temp /= 10;
            }

            // see if the incremented ticket number has changed the beginning
            // if so, recalculate the beginning sum
            if ( beg != (int)(ticket / mod_div_by) ){
                beg = (int)(ticket / mod_div_by);
                bsum = 0;
                int temp = beg;
                while ( temp > 0 ){
                    bsum += temp % 10;
                    temp /= 10;
                }
            }
            
        } while (esum != bsum);
        
        
        return to_string(ticket);
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solution;
    int ticket;
    
    cout << "Ticket number: ";
    cin >> ticket;
    cout << endl << endl << "Next lucky ticket: " << solution.next_lucky_ticket(ticket) << endl << endl;
    
    
    return 0;
}





