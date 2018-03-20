/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            if(curr == nullptr)
            {
                result += "#,";
            }else
            {
                q.push(curr->left);
                q.push(curr->right);
                result = result + to_string(curr->val) + ",";
            }
            q.pop();
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        queue<TreeNode**> q;
        q.push(&root);
        string::iterator first = data.begin();
        while (first != data.end()) {
            TreeNode** pp = q.front();
            if (*first == '#') {
                // *pp = nullptr;
                advance(first, 2);
            } else {
                string::iterator last = find(first, data.end(), ',');
                int val = stoi(string(first, last));
                *pp = new TreeNode(val);
                q.push(&((*pp)->left));
                q.push(&((*pp)->right));
                first = next(last);
            }
            q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));