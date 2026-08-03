class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr= root;
        while(curr!=NULL){
            if(curr->left!=NULL){//find the predecessor
                TreeNode* pred=curr->left;
                while(pred->right!=NULL && pred->right!=curr){
                    pred=pred->right;
                }
                if(pred->right==NULL){//link kro ..farzi connection banao
                    pred->right= curr;
                    curr= curr->left;
                }
                else {//pred->right==curr : unlink
                    pred->right= NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else {//curr->left==NULL
                 //visit
                 ans.push_back(curr->val);
                 curr=curr->right;
            }
        }
    
    return ans;
    }
};