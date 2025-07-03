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
    // void dfs(TreeNode* node, vector<int>& arr) {
    //     if (!node) return;
    //     arr.push_back(node->val);
    //     dfs(node->left, arr);
    //     dfs(node->right, arr);
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        // dfs(root, arr);
        // return arr;
        if(!root) return arr;
        stack<TreeNode*> st;
        st.push(root);
         while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            if(node->right) st.push(node->right);
            arr.push_back(node->val);
            if(node->left) st.push(node->left);

         }
         return arr;
    }
};
