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
    vector<int> postorderTraversal(TreeNode* root) {
        // solution 1
        // vector<int> result;
        // if (root == NULL)
        //     return result;
        // stack<TreeNode*> stack_tree;
        // TreeNode* curr = root;
        // stack_tree.push(curr);
        // while(!stack_tree.empty()){
        //     curr = stack_tree.top();
        //     result.push_back(curr->val);
        //     stack_tree.pop();
        //     if(curr->left != NULL){
        //         stack_tree.push(curr->left);
        //     }
        //     if(curr->right != NULL){
        //         stack_tree.push(curr->right);
        //     }
        // }
        // reverse(result.begin(), result.end());
        // return result;
        vector<int> result;
        if (root == NULL)
            return result;
        stack<TreeNode*> stack_tree;
        TreeNode* head = root;
        TreeNode* curr = root;
        stack_tree.push(curr);
        while(!stack_tree.empty()){
            curr = stack_tree.top();
            if((!curr->left && !curr->right) || curr->left == head || curr->right == head){
                result.push_back(curr->val);
                stack_tree.pop();
                head = curr;
            }
            else
            {
                if(curr->right) stack_tree.push(curr->right);
                if(curr->left) stack_tree.push(curr->left);
            }
        }
        return result;
    }
};