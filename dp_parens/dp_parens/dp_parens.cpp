/*
 
 CCI 8.9 Parens: Implement an algorithm to print all valid (e.g. properly opened and closed) combinations of n pairs of parentheses.
 
 EXAMPLE
 Input: 0
 Output:
 
 Input: 1
 Output: ()
 
 Input: 2
 Output: ()(), (())
 
 Input: 3
 Output: (())(), ()()(), ()(()),
         (()()), ((()))
 
 */

#include <iostream>
#include <vector>
#include <set>


using namespace std;


class Solution{
public:
    vector<string> generateParenthesis(int n){

        if (n <= 0) { return vector<string>(); }
        
        //
        // [0:n]
        //
        vector<set<string>> dp(n+1);
        dp[0].insert("");
        dp[1].insert("()");
        for (int i=2; i <= n; i++){

            //
            // create current set by adding parens before each previous solution
            // and by adding parens after each left paren "("
            //
            set<string> prev = dp[i-1];
            set<string> curr;
            for ( string str : prev ){
                
                for (int j=0; j < str.size(); j++){
                    
                    if (j==0){ // add () before prev solution
                        
                        curr.insert("()" + str);
                    }
                    
                    else
                    if ( str[j-1] == '(' ){ // add () after each left paren in prev soution
                        string temp = str;
                        curr.insert(temp.insert(j, "()"));
                    }
                }
            }
            dp[i] = curr; // save current set to use as next prev
        }
        
        //
        // construct and return result of the nth solution
        //
        return vector<string>(dp[n].begin(), dp[n].end());
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;
    
    for (int k=0; k < 5; k++){
        vector<string> result = solution.generateParenthesis(k);
        string output = to_string(k) + ":";
        
        for (int i=0; i < result.size(); i++){
        
            output += result[i] + ",";
        }
        output.pop_back(); // remove trailing ","
        
        cout << output << endl;
    }
    
    return 0;
}





