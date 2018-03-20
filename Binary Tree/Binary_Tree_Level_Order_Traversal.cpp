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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if(root == NULL)
            return result;
        TreeNode* curr = root;
        q.push(curr);
        while(!q.empty())
        {
            int levCount = q.size();
            int count = 0;
            vector<int> levNode;
            while(count < levCount)
            {
                curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                levNode.push_back(curr->val);
                count++;
            }
            result.push_back(levNode);
        }
        return result;
//         vector<vector<int>> res;
//         queue<TreeNode *> Q;
//         if(root)    Q.push(root);

//         while( !Q.empty())
//         {
//             int count=0;
//             int levCount=Q.size();
//             vector<int> levNode;
            
//             //遍历当前层
//             while(count<levCount)
//             {
//                 TreeNode *curNode=Q.front();
//                 Q.pop();
//                 levNode.push_back(curNode->val);
//                 if(curNode->left)
//                     Q.push(curNode->left);
//                 if(curNode->right)
//                     Q.push(curNode->right);
//                 count++;
//             }
//             res.push_back(levNode);
//         }
//         return res;    
    }
};