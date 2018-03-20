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
    int maxDepth(TreeNode* root) {
    //     solution 1
        // if(root == NULL)
        //     return 0;
        // int left_depth = maxDepth(root->left);
        // int right_depth = maxDepth(root->right);
        // return max(left_depth, right_depth)+1;
    //     solution 2
        int depth = 0;
        int answer;
        return getMaxDepth(root, depth);
    }
private:
    int answer = 0;
    int getMaxDepth(TreeNode* root, int depth){
        if (root == NULL)
            return depth;
        if(!root->left && !root->right){
            answer = max(depth, answer);
        }
        getMaxDepth(root->left, depth+1);
        getMaxDepth(root->right, depth+1);
        return answer+1;
    }
};