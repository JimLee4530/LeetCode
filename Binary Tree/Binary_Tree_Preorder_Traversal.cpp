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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack_tree;
        if(root != NULL && root->val != NULL){
            stack_tree.push(root);
        }
        else
            return result;
        while(!stack_tree.empty()){
            TreeNode* temp = stack_tree.top();
            stack_tree.pop();
            result.push_back(temp->val);
            if(temp->right != NULL)
            {
                stack_tree.push(temp->right);
            }
            if(temp->left != NULL){
                stack_tree.push(temp->left);
            }
        }
        return result;
    }
};