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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& inorder, int iLeft, int iRight, vector<int>&postorder, int pLeft, int pRight){
        if(iLeft > iRight || pLeft > pRight)
            return NULL;
        TreeNode* curr = new TreeNode(postorder[pRight]);
        int i = iLeft;
        for(i;i<inorder.size();i++)
            if(inorder[i] == curr->val)
                break;
        curr->left = buildTree(inorder, iLeft, i-1, postorder, pLeft, pLeft + i - iLeft - 1);
        curr->right = buildTree(inorder, i+1, iRight, postorder, pLeft - iLeft + i, pRight - 1);
        return curr;
    }
};