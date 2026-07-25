class Solution {
public:
    int helper(TreeNode* root, int sum){
        bool flag=false;
        if(root==NULL) return 0;
        
        if(root->left==NULL && root->right==NULL){//leaf node
            if(root->val==sum){
                flag=true;
                return flag;
            }
        }
       
      return helper(root->left, sum-root->val) ||
       helper(root->right, sum-root->val);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return helper(root,targetSum);
    }
};