
// This is the text editor interface.
// Anything you type or change here will be seen by the other person in real time.

Rotate square matrix 90 degrees

ex:
Input
1  2  3
4  5  6
7  8  9

Output:
3  6  9
2  5  8
1  4  7






    
    -------------
    
    


/*
 
 
 
 */

#include <iostream>








int main(int argc, const char * argv[]) {

    
    
    // This is the text editor interface.
    // Anything you type or change here will be seen by the other person in real time.
    
    Output of ps:
    Given a pid, kill all the descendant processes
    
ex:
    name	pid		ppid (parent)
    n1		12		3
    n2		13		12
    n3		18		13
    n4		27		3
    n5		99		12
    
    A. Kill pid 12 and all descendant processes (12, 13, 18, 99)
    
    ---------
    
#include <vector>
    
    using namespace std;
    
    class Process{
    public:
        Process(string name, int pid, int* ppid) : name{name}, pid{pid}, ppid{ppid} {}
        string name;
        int pid;
        vector<Process*> children;
    }
    
    class Solution{
    public:
        static void KillAll(Process* p){
            
            if (!p->children.empty()){
                kill(p);
            }
            
            for (vector<Process>::iterator itr; itr != p->children.begin(); itr++){
                Solution::KillAll(itr);
            }
            kill(p);
            
        }
    }
    
    int main(){
        
        
        
        
        
        return 0;
    }
    
    
    

    
    
    return 0;
}







A

// This is the text editor interface.
// Anything you type or change here will be seen by the other person in real time.

please implement a function that prints out all possibilities of n choose k

example:

input: 3, 2 (3 choose 2)

1, 2, 3
output:
1,2
1,3
2,3

input: 5,2
output:
1,2
1,3
1,4
1,5
2,3
2,4

input: 4, 3
output:
1, 2, 3
1, 2, 4
1, 3, 4
2, 3, 4

'

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int n = 4;

int k = 3;

string input = "";
unordered_map<string> umap;


for (int i=1; i <= n; i++){
    input += push_back(chr(i));
}



for (int i=1;i<=n;i++){
    
    string curr = input;
    
    for (int j=n;j>=1;j--){
        
        if (i==j){
            continue;
        }
        
        substring = curr.substr(0,k+1);
        umap[substring] = true;
        
        char temp = curr[i];
        curr[i] = curr[j];
        curr[i] = temp;
        
        12345
        i   j
        
        
    }
}

for (auto itr=umap.begin(); itr != umap.end(); itr++){
    cout << itr->first
    }
    
    12345  take first k 123
    
    51234   512
    
    41235   412
    
    31245  321
    
    21345   213
    
    12345
    
    21345  213
    
    13245  132
    
    14235  142
    
    15234  152
    
    
    
    
    
    }
    }
    
    
    



