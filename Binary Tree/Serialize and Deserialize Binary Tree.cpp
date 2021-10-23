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
        if(!root) return "x,";
        
        string left_subtree=serialize(root->left);
        string right_subtree=serialize(root->right);
        
        return to_string(root->val)+","+left_subtree+right_subtree;
    }

    // Decodes your encoded data to tree.
    TreeNode* helper(queue<string> &q)
    {
        string a=q.front();
        q.pop();
        if(a=="x") return NULL;
        
        stringstream obj(a);
        int temp = 0;
        obj >> temp;
        TreeNode* node=new TreeNode(temp);
        node->left=helper(q);
        node->right=helper(q);
        
        return node;
    }
    TreeNode* deserialize(string data) {
        queue<string> q;
        string a="";
        int n=data.length();
        for(int i=0;i<n;i++)
        {
            if(data[i]==',')
            {
                q.push(a);
                a="";
            }
            else a+=data[i];            
        }
        return helper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
