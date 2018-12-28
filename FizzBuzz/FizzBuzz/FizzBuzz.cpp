/*
 
 412. Fizz Buzz
 
 https://leetcode.com/problems/fizz-buzz/description/
 
 Write a program that outputs the string representation of numbers from 1 to n.
 
 But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
 
 Example:
 
 n = 15,
 
 Return:
 [
 "1",
 "2",
 "Fizz",
 "4",
 "Buzz",
 "Fizz",
 "7",
 "8",
 "Fizz",
 "Buzz",
 "11",
 "Fizz",
 "13",
 "14",
 "FizzBuzz"
 ]
 
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        return helper(1,n,{{3,"Fizz"},{5,"Buzz"},{15,"FizzBuzz"}});
    }
private:
    vector<string> helper(int beg, int end, vector<pair<int,string>>&& mapping){
        vector<string> res{};
        map<int,string,std::greater<int>> hash{};
        for (auto &&x: mapping) hash[x.first]=x.second;
        for (int i=beg; i<=end; ++i){
            string special{};
            for (auto &&x: hash){
                if (i%x.first==0){
                    special=x.second;
                    break;
                }
            }
            if (special.empty()) res.push_back(to_string(i)); // normal
            else                 res.push_back(special);      // special
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto res=solution.fizzBuzz(100);
    return 0;
}
