class Solution {
public:

    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void preOrder(TreeNode* root,vector<int>&ans,int level){
        if(root==NULL) return;
        ans[level]=root->val;
        preOrder(root->left,ans,level+1);
        preOrder(root->right,ans,level+1);

    }
 
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans(levels(root),0);
        preOrder(root, ans,0);
        return ans;
    }
};