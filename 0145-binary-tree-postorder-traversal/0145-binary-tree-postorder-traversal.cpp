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
    //     if(!node) return;
    //     dfs(node->left, arr);
    //     dfs(node->right, arr);
    //     arr.push_back(node->val);
    // }

    // vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> arr;
        // // dfs(root, arr);
        // // return arr;
        // // vector<int> arr;
        // // dfs(root, arr);
        // // return arr;
        // if(!root) return arr;
        // stack<TreeNode*> st;
        // st.push(root);
        //  while(!st.empty()){
        //     TreeNode* node = st.top();
        //     st.pop();

        //     if(node->right) st.push(node->right);
            
        //     if(node->left) st.push(node->left);
        //     arr.push_back(node->val);

        //  }
        //  return arr;

        vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;

    while (curr || !st.empty()) {
        if (curr) {
            // Go as left as possible
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode* node = st.top();
            // If right exists and hasn't been processed, move to right
            if (node->right && lastVisited != node->right) {
                curr = node->right;
            } else {
                // Otherwise, process node
                result.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }
    }

    return result;
}
    };
