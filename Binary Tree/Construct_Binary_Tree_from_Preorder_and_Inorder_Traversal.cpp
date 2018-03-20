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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() -1 , inorder, 0, inorder.size()-1);
    }
private:
    TreeNode* buildTree(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight){
        if(pLeft > pRight || iLeft > iRight)
            return  NULL;
        TreeNode* curr = new TreeNode(preorder[pLeft]);
        int i = iLeft;
        for(i;i < inorder.size();i++)
            if(inorder[i] == curr->val)
                break;
        curr->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i-1);
        curr->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i+1, iRight);
        return curr;
    }
};