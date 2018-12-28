/*
 
 451. Sort Characters By Frequency
 
 https://leetcode.com/problems/sort-characters-by-frequency/description/
 
 Given a string, sort it in decreasing order based on the frequency of characters.
 
 Example 1:
 
 Input:
 "tree"
 
 Output:
 "eert"
 
 Explanation:
 'e' appears twice while 'r' and 't' both appear once.
 So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 Example 2:
 
 Input:
 "cccaaa"
 
 Output:
 "cccaaa"
 
 Explanation:
 Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 Note that "cacaca" is incorrect, as the same characters must be together.
 Example 3:
 
 Input:
 "Aabb"
 
 Output:
 "bbAa"
 
 Explanation:
 "bbaA" is also a valid answer, but "Aabb" is incorrect.
 Note that 'A' and 'a' are treated as two different characters.
 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    string frequencySort(string s){
        
        string res;
        
        vector<string> alpha_group(123);
        for (char c : s){
            alpha_group[ int(c) ] += c;
        }
        
        sort(alpha_group.begin(), alpha_group.end(),
             [](string& a, string& b){ return a.size() > b.size(); });
        
        for (auto group : alpha_group){
            if (!group.empty()) { res += group; }
        }
        
        return res;
    }
};


int main(int argc, const char * argv[]) {
    
    
    Solution solution;
    cout << solution.frequencySort("scoobysnacks") << endl;
    cout << solution.frequencySort("tree") << endl;
    cout << solution.frequencySort("cccaaa") << endl;
    cout << solution.frequencySort("cccAaa") << endl;
    
    return 0;
}





