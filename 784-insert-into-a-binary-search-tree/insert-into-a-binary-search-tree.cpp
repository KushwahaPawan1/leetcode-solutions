class Solution {
public:
    void insert(TreeNode* root, int val) {
        if(root->val > val) { // go left
            if(root->left == NULL) {
                root->left = new TreeNode(val);
            }
            else {
                insert(root->left, val);
            }
        }
        else { // go right
            if(root->right == NULL) {
                root->right = new TreeNode(val);
            }
            else {
                insert(root->right, val);
            }
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        
        insert(root, val);
        return root;
    }
};