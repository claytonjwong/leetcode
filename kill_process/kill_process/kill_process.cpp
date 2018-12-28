/*
 
 582. Kill Process
 
 https://leetcode.com/problems/kill-process/description/
 
 
 Given n processes, each process has a unique PID (process id) and its PPID (parent process id).
 
 Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.
 
 We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.
 
 Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.
 
 Example 1:
 Input:
 pid =  [1, 3, 10, 5]
 ppid = [3, 0, 5, 3]
 kill = 5
 Output: [5,10]
 Explanation:
 3
 /   \
 1     5
 /
 10
 Kill 5 will also kill 10.
 Note:
 The given kill id is guaranteed to be one of the given PIDs.
 n >= 1.
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    //
    // brute force, for each process, search through the parent process list
    // to find children to further process, O(N^2)
    //
    
    /*
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        
        vector<int> killed;

        if ( kill == 0 ){ // kill none
            return killed;
        }

        vector<int> stack;
        stack.push_back(kill);
        while (!stack.empty()){
            
            // pop and add to retval
            int curr = stack.back();
            stack.pop_back();
            killed.push_back(curr);
            
            // process children in the same way
            for (int i=0; i < ppid.size(); i++){
                
                if ( ppid[i] == curr ){ // push children onto stack for further processing
                    stack.push_back(pid[i]);
                }
            }
        }
        
        return killed;
    }
     */
    
    //
    // same strategy as before, but use a hash table to store parent/child relationship
    // this allows for O(1) lookup (rather than O(n) lookup), so our algo will run in O(n),
    // with tradeoff of using additonal memory space to increase lookup times
    //
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill){
        
        vector<int> killed;
        
        if ( kill == 0 ){
            return killed;
        }
        
        //
        // populate hash table for parent/child lookup
        //
        unordered_map<int,vector<int>> children; // key=ppid (parent)  value=pid (children)
        for (int i=0; i < ppid.size(); i++){
            
            int parent = ppid[i];
            int child = pid[i];
            
            if ( children.find( parent ) == children.end() ){ // new parent
                
                children[ parent ] = vector<int>{ child };
                
            } else { // existing parent
                
                children[ parent ].push_back( child ); // add child onto children
            }
        }
        
        //
        // DFS using stack to kill parent/children and append onto killed as retval
        //
        vector<int> stack{ kill };
        while (!stack.empty()){
            
            int curr = stack.back();
            stack.pop_back();
            killed.push_back(curr);
            
            if ( children.find(curr) != children.end() ){ // if curr if parent of other processes
                
                vector<int>::iterator itr;
                for (itr = children[curr].begin(); itr != children[curr].end(); itr++){
                    stack.push_back(*itr);
                }
            }
            
        }
        
        return killed;
    }
};


int main(int argc, const char * argv[]) {

    /*
     pid =  [1, 3, 10, 5]
     ppid = [3, 0, 5, 3]
     kill = 5
     Output: [5,10]
     Explanation:
     3
     /   \
     1     5
     /
     10
     */
    Solution solution;
    
    vector<int> ppid { 3, 0,  5, 3 };
    vector<int> pid  { 1, 3, 10, 5 };
    
    int kill_pid = 5;
    
    vector<int> killed = solution.killProcess(pid, ppid, kill_pid);
    
    cout << "Killed: ";
    for ( auto kid : killed ){
        cout << to_string(kid) << ",";
    }
    cout << endl;
    
    return 0;
}




