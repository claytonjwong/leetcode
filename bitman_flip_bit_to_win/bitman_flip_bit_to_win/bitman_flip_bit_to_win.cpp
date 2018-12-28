/*
 
 CCI CH 5.3 Flip Bit to Win: You have an integer and you can flip exactly one bit from a 0 to a 1.  Write code to find the length of the longest sequence of 1s you could create.
 
 Example:
 
 Input: 1775   ( or:  11011101111 )
 Output: 8
 
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Chunk{
public:

    
    
    Chunk() : val{Chunk::INIT}, size{0} {}

    static const int INIT = -1;
    static const int ZERO = 0;
    static const int ONE = 1;
    
    int val;
    int size;
    
    
};

class Solution{
public:
    
    int maxLengthOnes(int n){
        
        /*
         
         each consequetive group of 1s is separated by one or more 0s
         
         
         case 1:
         
         if one 0 separates two consequetive groups of 1s,
         then their lengths can be added together
         
         
         case 2:
         
         if more than one 0 separates two consequetive groups of 1s,
         then only one 1 can be added to its length
         
         
         edge case:
         
         the begin / end can only be potentially added onto from one end,
         all other groups of 1s can be added onto from either end
         
         */
 
        /*
         
        10987654321098765432109876543210
        00000000000000000000011011101100
         
         
        */
        
        int max_len = 0;
        
        vector<Chunk> chunks;
        toChunks(n, chunks); // every other chunk is 0, 1
        
        for (int i=0; i < chunks.size(); i++){
            
            //
            // for each chunk of 1s trying making max len chunk by adding 1 to the right
            //
            if ( chunks[i].val == Chunk::ONE && i >= 1 ){
                
                int chunk_size = 0;
                
                //
                // every other chunk is 0,1 so the next (i+1) chunk is 0s since curr (i) is 1s
                //
                if (chunks[i-1].size == 1 && i >= 2){
                
                    // bridge two chunks of 1s separated by one 0
                    chunk_size = chunks[i].size + chunks[i-2].size;
                }
                else
                if ( chunks[i-1].size > 1){
                    
                    // append one 1 onto this chunk of 1s
                    chunk_size = chunks[i].size + 1;
                }
                
                max_len = max( max_len, chunk_size);
            }
        }
        
        //
        // one last check, since we were only trying to add a 1 onto the right so far,
        // we have to see if there is potential for adding onto the left of the
        // last chunk when the last chunk is 0s, and second to last chunk is 1s
        //
        if ( chunks.size() >= 2 && chunks[chunks.size()-1].val == Chunk::ZERO ){

            max_len = max ( max_len, chunks[chunks.size()-2].size + 1 );
        }
        
        return max_len;
    }
    
    void toChunks(int n, vector<Chunk>& chunks){
        
        Chunk curr;
        for (int i=0; i < 32; i++){
            
            bool curr_bit_set = n & (1<<i);
            
            if (curr_bit_set && curr.val == Chunk::ONE){ // chunk of 1s
                curr.size++;
            }
            else
            if (!curr_bit_set && curr.val == Chunk::ZERO){ // chunk of 0s
                curr.size++;
            }
            else { // new chunk, save old chunk
                
                if (curr.size > 0){
                    chunks.push_back(curr);
                }
                
                curr.val = Chunk::INIT;
                curr.size = 0;
            }
            
            if (curr.val == Chunk::INIT){
                if (curr_bit_set){
                    curr.val = Chunk::ONE;
                } else {
                    curr.val = Chunk::ZERO;
                }
                curr.size = 1;
            }
        }
        
        if (curr.size > 0){
            chunks.push_back(curr); // append last chunk
        }
    }
};


int main(int argc, const char * argv[]) {

    
    Solution solution;
    
    cout << "7 == " << solution.maxLengthOnes(1775) << endl;
    cout << "11 == " << solution.maxLengthOnes(1024-1) << endl;
    
    
    return 0;
}




