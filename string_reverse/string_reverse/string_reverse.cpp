/*
 
 Write a function to reverse a string in place
 
 Write a function to reverse words in a string
 
 */

#include <iostream>

using namespace std;

class Solution {
public:
    
    void reverse_word(char* begin, char* end) {
        
        /* while begin points to a memory address less than end */
        while (begin < end) {
            
            /* swap chars pointed at by begin/end */
            char temp = *begin;
            *begin = *end;
            *end = temp;
            
            /* move pointers inwards towards eachother */
            begin++;
            end--;
        }
    }
    
    int reverse_sentence(char* s){
        
        int i=0;
        int j=0;
        while ( s[i] != '\0' ) {
            
            /* find a word,
             
             i = the index of the first char of the word
             j = the index of the first word deliminator ( whitespace or null char )
             
             */
            
            while ( s[j] != ' ' && s[j] != '\0' ) {
                
                j++; // increment j until whitespace or null char found
                
            }
            
            
            /* reverse word from [i:j)
             
             check if i < j - 1 since if i == j-1,
             then this "word" is just a single char,
             which cannot be reversed
             
             only invoke reverse_word when "word" is >= 2 chars (which can be reversed)
             
            */
            
            if ( i < j - 1 ) {
                reverse_word(&s[i],&s[j-1]);
            }
            
    
            /* move i to j for the next word
            
             set i=j+1 since j is the index of the whitespace before the next word
             
            */

            i = j+1;
            j = i;
        }
        
        return i; // length of the sentence
    }
};



int main(int argc, const char * argv[]) {
    
    /* test data */
    
    char test_string[] = "a b c hello world how are you\0";
    char rev_test_string[] = "a b c olleh dlrow woh era uoy\0";

    
    /* solution */
    
    Solution solution;
    int len = solution.reverse_sentence(test_string);
    
    
    /* output */
    
    for (int i=0; i < len; i++) {
        cout << i % 10;
    }
    cout << endl;
    cout << test_string << endl;
    cout << rev_test_string << endl;
    cout << endl;
    
    return 0;
}



