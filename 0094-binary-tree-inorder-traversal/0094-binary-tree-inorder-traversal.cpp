/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void dfs(TreeNode* node, vector<int>& arr){
    //     if (!node) return;
    //     dfs(node->left, arr);
    //     arr.push_back(node->val);
        
    //     dfs(node->right, arr);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> arr;
        // dfs(root , arr);
        // return arr;
        
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        // Go all the way left
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        // Process node
        curr = st.top();
        st.pop();
        result.push_back(curr->val);

        // Go to right subtree
        curr = curr->right;
    }

    return result;
    }   

    };
