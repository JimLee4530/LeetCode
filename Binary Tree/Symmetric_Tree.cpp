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
    bool isSymmetric(TreeNode* root) {
        //solution 1 & 2
        // if(root == NULL)
        //     return true;
        // return compRoot(root->left, root->right);
        
        // Solution 3
        deque<TreeNode*> dq;
        if(!root) return true;
        if(root->left == NULL || root->right == NULL)
            return root->left == root->right;
        dq.push_front(root->left);
        dq.push_back(root->right);
        while(!dq.empty()){
            bool lflag = true;
            bool rflag = true;
            TreeNode* lroot = dq.front();
            TreeNode* rroot = dq.back();
            dq.pop_front();
            dq.pop_back();
            if(lroot->val != rroot->val)
                return false;
            if(lroot->left == NULL || rroot->right == NULL)
            {
                lflag = (lroot->left == rroot->right);
                if(!lflag)
                    return false;
            }else{
                dq.push_front(lroot->left);
                dq.push_back(rroot->right);
            }
            if(lroot->right == NULL || rroot->left == NULL){
                rflag = lroot->right == rroot->left;
                if(!rflag)
                    return false;
            }else{
                dq.push_front(lroot->right);
                dq.push_back(rroot->left);
            }
        }
        return true;
    }
private:
    bool compRoot(TreeNode* lroot, TreeNode* rroot){
        // solution 1
        // if(!lroot) return (NULL == rroot);
        // if(NULL == rroot) return false;
        // if(lroot -> val != rroot -> val) return false;
        // return (compRoot(lroot -> left, rroot -> right) && compRoot(lroot -> right, rroot -> left));
        
        //solution 2
        if (lroot == NULL || rroot == NULL){
            return (lroot == rroot);
        }
        return (lroot->val == rroot->val) && compRoot(lroot->left, rroot->right) && compRoot(lroot->right, rroot->left);
    }
};