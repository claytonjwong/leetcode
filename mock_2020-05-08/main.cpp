#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace Question1 {
    class Solution {
    public:
        using VS = vector<string>;
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Map = unordered_map<char, string>;
        VS compare(VS& A, string target, VS ans = {}) {
            auto hash = [&](auto& str) {
                Map m;
                for (auto i{ 0 }; i < str.size(); ++i)
                    m[str[i]].append(to_string(i)).push_back(',');
                VS S;
                for (auto [_, str]: m)
                    S.push_back(str);
                sort(S.begin(), S.end());
                string res;
                for (auto& str: S)
                    res.append(str).push_back(':');
                return res;
            };
            auto T = hash(target);
            for_each(A.begin(), A.end(), [&](auto& s){
                if (hash(s) == T) // 🎯
                    ans.push_back(s);
            });
            return ans;
        }
    };
}

namespace Question2 {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int val) : val{val}, next{nullptr} {}
    };
    struct TreeNode {
        int val;
        TreeNode *left, *right;
        TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
    };
    class Solution {
    public:
        TreeNode* makeTree(ListNode* head) {
            auto N{ 0 }; for (auto cur{ head }; cur; cur = cur->next, ++N);
            return head ? go(head, 0, N - 1) : nullptr;
        }
        string deserialize(TreeNode* root) {
            string s;
            inorder(root, s);
            return s;
        }
    private:
        TreeNode* go(ListNode* head, int i, int j) {
            auto k = (i + j) / 2,
                 steps = k - i;
            auto cur = head,
                 pre = head;
            while (steps--)
                cur = cur->next;
            auto root = new TreeNode(cur->val);
            root->left = i <= k - 1 ? go(pre, i, k - 1) : nullptr;
            root->right = k + 1 <= j ? go(cur->next, k + 1, j) : nullptr;
            return root;
        }
        void inorder(TreeNode* root, string& res) {
            if (!root)
                return;
            inorder(root->left, res);
            res.append(to_string(root->val)).push_back(',');
            inorder(root->right, res);
        }
    };
}

namespace Question3 {
    class Solution {
    public:
        using VI = vector<int>;
        bool hasSeqSum(VI& A, int T) {
            int N = A.size();
            auto i = 0,
                 j = 0,
                 sum = 0;
            while (j < N) {
                if (sum < T) sum += A[j++]; // expand window
                if (sum > T) sum -= A[i++]; // shrink window
                if (sum == T) // 🎯
                    return true;
            }
            return false;
        }
    };
}

int main() {
    // Question 1
    {
        using Solution = Question1::Solution;
        Solution solution;
        Solution::VS A{"abb", "abc", "xyz", "xyy", "yza"};
        Solution::VS B{"abb", "abc", "xyz", "xyy", "wgw"};
        auto ansA = solution.compare(A, "mnq");
        auto ansB = solution.compare(B, "aba");
        copy(ansA.begin(), ansA.end(), ostream_iterator<string>(cout, " ")), cout << endl; // abc xyz yza
        copy(ansB.begin(), ansB.end(), ostream_iterator<string>(cout, " ")), cout << endl; // wgw
    }
    // Question 2
    {
        using Solution = Question2::Solution;
        using ListNode = Question2::ListNode;
        Solution solution;
        auto head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        head->next->next->next->next->next = new ListNode(6);
        head->next->next->next->next->next->next = new ListNode(7);
        head->next->next->next->next->next->next->next = new ListNode(8);
        auto root = solution.makeTree(head);
        cout << solution.deserialize(root) << endl; // 1,2,3,4,5,6,7,8,
    }
    // Question 3
    {
        using Solution = Question3::Solution;
        Solution::VI A{1, 3, 1, 4, 23};
        Solution solution;
        cout << solution.hasSeqSum(A, 8) << endl; // true
        cout << solution.hasSeqSum(A, 7) << endl; // false
        Solution::VI B{1, 1, 1};
        cout << solution.hasSeqSum(B, 3) << endl; // true
        cout << solution.hasSeqSum(B, 2) << endl; // true
        cout << solution.hasSeqSum(B, 1) << endl; // true
    }
    return 0;
}
