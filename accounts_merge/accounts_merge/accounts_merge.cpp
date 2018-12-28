/*
 
 721. Accounts Merge
 
 https://leetcode.com/contest/leetcode-weekly-contest-57/problems/accounts-merge/
 
 Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
 
 Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
 
 After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
 
 Example 1:
 Input:
 accounts = [["John", "a", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "a", "b"], ["Mary", "mary@mail.com"]]
 Output: [["John", 'john00@mail.com', 'b', 'a'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
 Explanation:
 The first and third John's are the same person as they have the common email "a".
 The second John and Mary are different people as none of their email addresses are used by other accounts.
 We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
 ['John', 'john00@mail.com', 'b', 'a']] would still be accepted.
 Note:
 
 The length of accounts will be in the range [1, 1000].
 The length of accounts[i] will be in the range [1, 10].
 The length of accounts[i][j] will be in the range [1, 30].
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    class Account {
    public:
        shared_ptr<Account> _parent;
        string _name;
        set<string> _emails;
        
        Account(string name) : _parent{nullptr}, _name{name}, _emails{} {}
        
        void AddEmail(string email){
            _emails.insert(email);
        }
        
        void AddEmails(set<string>& emails){
            for (auto &&email: emails)
                _emails.insert(email);
        }
    };
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res{};
        vector<shared_ptr<Account>> va{}; // vector<vector<string>> to vector<shared_ptr<Account>>
        for (auto &&account: accounts){
            auto a=make_shared<Account>(account[0]);
            for (int i=1; i<account.size(); ++i){
                string email=account[i];
                a->AddEmail(email);
            }
            va.push_back(a);
        }
        unordered_map<string,shared_ptr<Account>> hash{}; // hash collisions are unioned (key=email val=ptr to Account)
        for (auto &&a: va){
            for (auto &&email: a->_emails){
                if (hash.find(email)==hash.end()){
                    hash[email]=a;
                } else {
                    auto b=hash[email];
                    Union(a,b);
                }
            }
        }
        unordered_set<shared_ptr<Account>> disjoint{}; // disjoint sets to vector<vector<string>> res
        for (auto &&a: hash){
            auto parent=Find(a.second);
            disjoint.insert(parent);
        }
        for (auto &&a: disjoint){
            vector<string> merged{a->_name};
            for (auto &&email: a->_emails){
                merged.push_back(email);
            }
            res.push_back(merged);
        }
        return res;
    }

    void Union(shared_ptr<Account> a, shared_ptr<Account> b){
        shared_ptr<Account> pa=Find(a);
        shared_ptr<Account> pb=Find(b);
        if (pa==pb) return;
        if (pa->_emails.size() > pb->_emails.size()){
            pa->AddEmails(pb->_emails);
            pb->_parent=pa;
        } else {
            pb->AddEmails(pa->_emails);
            pa->_parent=pb;
        }
    }
    
    shared_ptr<Account> Find(shared_ptr<Account> account){
        if (account->_parent){
            account->_parent=Find(account->_parent);
            return account->_parent;
        }
        return account;
    }
};

int main(int argc, const char * argv[]) {

    vector<vector<string>> accounts {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"},
    };
    
    Solution solution;
    auto res=solution.accountsMerge(accounts);

    return 0;
}





