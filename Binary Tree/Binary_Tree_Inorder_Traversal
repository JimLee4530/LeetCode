/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack_tree;
        vector<int> result;
        TreeNode* curr = root;
        while(curr || !stack_tree.empty()){
            while(curr){
                stack_tree.push(curr);
                curr = curr->left;
            }
            curr = stack_tree.top();
            stack_tree.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
    }
};