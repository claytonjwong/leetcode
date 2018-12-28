/*
 
 https://leetcode.com/contest/weekly-contest-94/
 
 Rank           Name            Score   Finish Time     Q1 (4)    Q2 (4)    Q3 (6)    Q4 (6)
 1188 / 4541    claytonjwong    4       0:10:59         0:10:59
 
 Q1: https://leetcode.com/problems/leaf-similar-trees/description/
 A1: https://leetcode.com/problems/leaf-similar-trees/discuss/152310/Concise-C++-recursive-solution
 
 Q2: https://leetcode.com/problems/walking-robot-simulation/description/
 A2: https://leetcode.com/problems/walking-robot-simulation/discuss/152371/Concise-C++-solution
 
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <stack>
#include <queue>
#include <string>

using namespace std;

/*
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val{x},left{nullptr},right{nullptr}{}
};

using VI=vector<int>;
class Solution {
public:
    bool leafSimilar(TreeNode* R1, TreeNode* R2, VI L1={}, VI L2={}) {
        if (R1) go(R1,L1);
        if (R2) go(R2,L2);
        return L1==L2;
    }
private:
    void go(TreeNode* x, VI& L){
        if (!x->left && !x->right) L.push_back(x->val);
        if (x->left) go(x->left,L);
        if (x->right) go(x->right,L);
    }
};
*/


using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    int robotSim(VI& commands, VVI& obstacles, int dir=U, VI pos={0,0}, int ans=0) {
        for (auto& obs: obstacles)
            OBS.insert(hash(obs[0],obs[1]));
        for (auto cmd: commands){
            if (cmd<0) turn(dir,cmd); else move(pos,dir,cmd);
            ans=max(ans,pos[0]*pos[0]+pos[1]*pos[1]);
        }
        return ans;
    }
private:
    unordered_set<string> OBS;
    enum DIRS {U=0,R=1,D=2,L=3}; const VVI MOVES {{0,1},{1,0},{0,-1},{-1,0}}; // UP,RIGHT,DOWN,LEFT
    string hash(int x, int y){ return to_string(x)+","+to_string(y); }
    void turn(int& dir, int cmd){
        if      (cmd==-1) dir=(dir==L) ? U : dir+1; // right (clockwise)
        else if (cmd==-2) dir=(dir==U) ? L : dir-1; // left (counter-clockwise)
    }
    void move(VI& pos, const int dir, int N){
        while (N--){
            int x=pos[0]+MOVES[dir][0],y=pos[1]+MOVES[dir][1];
            if (OBS.find(hash(x,y))==OBS.end()) pos[0]=x,pos[1]=y; else return;
        }
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    
    /*
    TreeNode* R1=new TreeNode(3);
    R1->left=new TreeNode(5);
    R1->right=new TreeNode(1);
    R1->left->left=new TreeNode(6);
    
    
    TreeNode* R2=new TreeNode(3);
    R2->left=new TreeNode(5);
    R2->right=new TreeNode(1);
    R2->left->left=new TreeNode(6);
    
    cout << s.leafSimilar(R1, R2) << endl;
    */
    
    VI cmd{4,-1,4,-2,4};
    VVI obs{{2,4}};

    
    cout << s.robotSim(cmd, obs) << endl;
    
    
    return 0;
}





