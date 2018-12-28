/*
 
 Question from Bloomberg, be able to output top n quantities of stocks and insert/update existing records
 
 
 
 My solution:
 
 lookup by ticker, use unordered_map for quick lookups of individual tickers
 lookup by top k max, use a vector, and bubble sort it up to k ==> O(nk)
 
 */

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Stock{
public:
    Stock(string ticker, int quantity) : ticker{ticker}, quantity{quantity} {}
    bool operator<(const Stock& rhs){
        return quantity < rhs.quantity;
    }
    
    string GetTicker(){
        return ticker;
    }
    
    int GetQuantity(){
        return quantity;
    }
    
    void UpdateQuantity(int new_quantity){
        quantity = new_quantity;
    }
private:
    string ticker;
    int quantity;
};


class Solution{
public:
    Solution() {}
    
    void update(string ticker, int quantity){
        
        // add ticker if it does NOT exist
        if ( ticker_table.find(ticker) == ticker_table.end() ){
            auto new_entry = make_shared<Stock>(ticker, quantity);
            ticker_table[ticker] = new_entry;
            ticker_list.push_back(new_entry);
        } else {
            
            // update quantity of existing stock
            ticker_table[ticker]->UpdateQuantity(quantity);
        }
        
    }
    
    int lookup(string ticker){
        
        if (ticker_table.find(ticker) == ticker_table.end()){
            return INT_MIN;
        } else {
            return ticker_table[ticker]->GetQuantity();
        }
    }
    
    void printTopK(int k){
    
        
        // bubble sort O(nk)
        for (int i=0; i < k; i++){
            
            int maxj_index = i;
            for (int j=i+1; j < ticker_list.size(); j++){
                
                // swap [k] with largest [j]
                if (*ticker_list[maxj_index] < *ticker_list[j]){
                    maxj_index = j;
                }
            }
            
            // swap max j with i
            shared_ptr<Stock> temp = ticker_list[maxj_index];
            ticker_list[maxj_index] = ticker_list[i];
            ticker_list[i] = temp;
            
            cout << i << ": Ticker==" << ticker_list[i]->GetTicker();
            cout << " ( " << ticker_list[i]->GetQuantity() << " ) " << endl;
        }
        
        
        
    }
    
private:
    unordered_map<string, shared_ptr<Stock>> ticker_table;
    vector<shared_ptr<Stock>> ticker_list;
};


int main(int argc, const char * argv[]) {
    
    
    Solution solution;
    
    solution.update("PSX", 50);
    solution.update("IBM", 69);
    solution.update("AAPL", 200);
    solution.update("AAPL", 400);
    solution.update("QCOM", 100);
    solution.update("HCP", 25);
    solution.update("MCK", 300);
    
    cout << "Lookup AAPL: " << solution.lookup("AAPL") << endl;
    
    solution.printTopK(3);
    
    return 0;
}




