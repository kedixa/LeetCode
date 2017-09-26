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
    void se(TreeNode* root, string &data) {
        data += to_string(root->val);
        if(root -> left) {
            data += "(";
            se(root->left, data);
            data += ")";
        }
        if(root -> right) {
            data += "[";
            se(root->right, data);
            data += "]";
        }
    }
    void de(TreeNode* &root, const char* &p) {
        int val = 0;
        bool neg = false;
        if(*p == '-') ++p, neg = true;
        while(isdigit(*p)) {
            val = val * 10 + (*p - '0');
            ++p;
        }
        if(neg) val = -val;
        root = new TreeNode(val);
        if(*p == '(') {
            ++p;
            de(root->left, p);
            ++p;
        }
        if(*p == '[') {
            ++p;
            de(root->right, p);
            ++p;
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // root = "val(left)[right]"
        string data;
        if(root != nullptr)
            se(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = nullptr;
        const char *p = data.c_str();
        if(data.length() != 0)
            de(root, p);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
