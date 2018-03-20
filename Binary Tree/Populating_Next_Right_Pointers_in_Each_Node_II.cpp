/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            TreeLinkNode *curr;
            while(size--)
            {
                curr = q.front();
                q.pop();
                if(size > 0)
                    curr->next = q.front();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
    }
};