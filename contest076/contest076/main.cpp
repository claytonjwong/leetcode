/*
 
 contest 76
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <sstream>

using namespace std;

/*
 // wrong answer
class Solution {
public:
    string similarRGB(string color) {
        static map<int,string> shorthand {
            {0x00,"00"}, {0x11,"11"}, {0x22,"22"}, {0x33,"33"}, {0x44,"44"},
            {0x55,"55"}, {0x66,"66"}, {0x77,"77"}, {0x88,"88"}, {0x99,"99"},
            {0xAA,"AA"}, {0xBB,"BB"}, {0xCC,"CC"}, {0xDD,"DD"}, {0xEE,"EE"}, {0xFF,"FF"},
        };
        stringstream ss;
        color[0]='0'; // change # to 0
        ss << std::hex << color;
        int i,r,g,b;
        ss >> i;
        r=(0xFF0000 & i) >> 16;
        g=(0x00FF00 & i) >> 8;
        b=(0x0000FF & i);
        string ans;
        ss.str("");
        auto lb=shorthand.lower_bound(r),ub=shorthand.upper_bound(r);
        string sr=((abs(r-lb->first)<abs(r-ub->first)) ? lb->second : ub->second);
        
        //ss << shorthand[r].second;
        return ss.str();
    }
};
*/


/*
 // AC
class Solution {
public:
    string similarRGB(string color) {
        vector<int> ans(3),target(3);
        getRGB(color, target[0], target[1], target[2]);
        int best=INT_MAX;
        for (int r=0; r<16; ++r){
            for (int g=0; g<16; ++g){
                for (int b=0; b<16; ++b){
                    int curr=similarity(target,{r,g,b});
                    if (curr<best){
                        best=curr;
                        ans={r,g,b};
                    }
                }
            }
        }
        return str(ans[0],ans[1],ans[2]);
    }
private:
    string str(int r, int g, int b){
        stringstream ss;
        ss << "#" << std::hex << r << r << g << g << b << b;
        return ss.str();
    }
    
    void getRGB(string color, int& r, int& g, int& b){
        stringstream ss;
        color[0]='0'; // change # to 0
        ss << std::hex << color;
        int i;
        ss >> i;
        r=(0xFF0000 & i) >> 16;
        g=(0x00FF00 & i) >> 8;
        b=(0x0000FF & i);
    }
    
    int similarity(vector<int>& t, vector<int>&& c){ // target & candidate
        int ans=0;
        for (int i=0; i<3; ++i){
            int curr=(t[i]-(c[i]*16+c[i]));
            curr*=curr;
            ans+=curr;
        }
        return ans;
    }
};
 */

/*
// wrong answer
class Solution {
public:
    string similarRGB(string color) {
        static map<int,string> shorthand;
        shorthand[0]="00";
        for (int i=0x11; i<=0xFF; i+=0x11){
            stringstream ss;
            ss << std::hex << i;
            shorthand[i]=ss.str();
        }
        stringstream ss;
        color[0]='0'; // change # to 0
        ss << std::hex << color;
        int hex,r,b,g;
        ss >> hex;
        vector<int> rbg(3);
        rbg[0]=r=(0xFF0000 & hex) >> 16;
        rbg[1]=b=(0x00FF00 & hex) >> 8;
        rbg[2]=g=(0x0000FF & hex);
        
        string ans="#";
        for (int i=0; i<rbg.size(); ++i){
            auto lb=shorthand.lower_bound(rbg[i]),ub=shorthand.upper_bound(rbg[i]);
            int lower=lb->first,upper=ub->first;
            int lowerdiff=rbg[i]-lb->first,upperdiff=rbg[i]-ub->first;
            string si=((abs(rbg[i]-lb->first)<abs(rbg[i]-ub->first)) ? lb->second : ub->second);
            ans+=si;
        }
        
        //ss << shorthand[r].second;
        return ans;
    }
};
 */

/*
// TLE
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int N=(int)g.size();
        unordered_set<int> res;
        unordered_set<int> visited;
        vector<int> path;
        for (int i=0; i<N; ++i)
            go(res,g,i,visited,path);
        vector<int> ans;
        for (int i=0; i<N; ++i)
            if (!res.count(i))
                ans.push_back(i);
        return ans;
    }
private:
    void go(unordered_set<int>& r, vector<vector<int>>& g, int i,
            unordered_set<int>& v, vector<int>& p){
        if (r.count(i)){
            r.insert(p.begin(),p.end());
            return;
        }
        v.insert(i);
        p.push_back(i);
        for (auto nei: g[i])
            if (!v.count(nei)){
                go(r,g,nei,v,p);
            } else {
                r.insert(p.begin(),p.end());
                return;
            }
        v.erase(i);
        p.pop_back();
    }
};
*/

// AC
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        set<int> safe,cycle,visited;
        for (int i=0; i<graph.size(); ++i)
            DFS(graph,safe,cycle,visited,i);
        return vector<int>(safe.begin(),safe.end());
    }
private:
    bool DFS(vector<vector<int>>& g, set<int>& s, set<int>& c, set<int>& v, int i){
        if (c.count(i) || v.count(i)) return false;
        if (s.count(i)) return true;
        v.insert(i);
        for (auto nei: g[i]){
            if (!DFS(g,s,c,v,nei)){
                v.erase(i);
                c.insert(i);
                return false;
            }
        }
        v.erase(i);
        s.insert(i);
        return true;
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    /*
    vector<vector<int>> g {
        {0},
        {2,3,4},
        {3,4},
        {0,4},
        {},
    };
*/
    //[1,2],[2,3],[5],[0],[5],[],[]

    vector<vector<int>> g {
        {1,2},
        {2,3},
        {5},
        {0},
        {5},
        {},
        {}
    };
    auto r=s.eventualSafeNodes(g);

    
    /*
    Solution s;
    //while(true){
        string in="#09f166";
        //cout << "in: "; cin >> in;
        cout << s.similarRGB(in) << endl;
    //}
    */

    
    return 0;
}



