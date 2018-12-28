/*
 
 CCI CH 8.4 Power Set: Write a method to return all subsets of a set
 
 
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution{
public:
    
    set<vector<int>> permutations(vector<int>& v){
        return permutations(v, (int)v.size());
    }
    
    set<vector<int>> permutations(vector<int>& v, int k){
        
        set<vector<int>> p;
        
        if (k<=0 || v.empty()) { return p; }
        
        if (k > (int)v.size()) { k = (int)v.size(); }
        
        do {
            p.insert(vector<int>(v.begin(), v.begin()+k));
            
        } while ( next_permutation(v.begin(), v.end()) );
        
        return p;
    }


    
    
    vector<set<int>> power_set(vector<int>& v){
        
        //
        // {}
        //
        vector<set<int>> ps;
        set<int> init_set;
        ps.push_back(init_set);
        
        if (v.empty()){
            return ps;
        }
        
        //
        // {v0}
        //
        init_set.insert(v[0]);
        ps.push_back(init_set);
        
        
        /*
         
         add element from v onto each set in the power set so far
         
         power_set {} ==> {}
         power_set {v0} ==> {},          {v0}
         power_set {v1} ==> {}+v1=={v1}, {v0}+v1=={v0, v1} ( v1 appended onto each prev set )
         power_set {v2} ==> {v2}, {v0, v2}, {v1,v2}, {v0, v1, v2} ( v2 appended onto each prev set )
         
         */
        for ( int i=1; i < v.size(); i++ ){
            
            //
            // for each set in the power set so far
            //
            // ( size must be evaluated before this loop,
            //   since the array size increases )
            //
            int size = (int)ps.size();
            for ( int j=0; j < size; j++){
                
                //
                // invoke set copy constructor, insert element into set,
                // and append set onto the power set so far
                //
                set<int> ps_plus_one = ps[j];
                ps_plus_one.insert( v[i] );
                ps.push_back( ps_plus_one );
            }
        }
        
        return ps;
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;
    
    vector<int> test { 1,2,3 };
    set<vector<int>> result = solution.permutations(test, 4);
    
    cout << "Permutations of 1,2,3:" << endl;
    for (auto ss : result ){
        
        cout << "[";
        for (int i=0; i < ss.size(); i++){
            cout << ss[i] << ",";
        }
        cout << "]" << endl;
    }
    
    vector<set<int>> ps = solution.power_set(test);

    cout << "Power set of 1,2,3:" << endl;
    for (auto s : ps ){
        
        cout << "[";
        for (auto u : s){
            cout << u << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}



