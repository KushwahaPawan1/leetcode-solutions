class Solution {
public:

    // DFS function jo root se leaf tak saare paths explore karega
    void helper(TreeNode* root, vector<int> v, vector<vector<int>>& ans, int sum){

        // Agar node NULL hai to kuch nahi karna
        if(root == NULL) return;

        // Agar leaf node mil gayi
        if(root->left == NULL && root->right == NULL){

            // Check karo ki remaining sum isi node ke equal hai ya nahi
            if(root->val == sum){

                // Leaf node ko current path me add karo
                v.push_back(root->val);

                // Current valid path answer me store kar do
                ans.push_back(v);
            }

            return;
        }

        // Current node ko path me add karo
        v.push_back(root->val);

        // Left subtree explore karo
        // Remaining sum = sum - current node ki value
        helper(root->left, v, ans, sum - root->val);

        // Right subtree explore karo
        helper(root->right, v, ans, sum - root->val);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        // Final answer store karega
        vector<vector<int>> ans;

        // Current path store karega
        vector<int> v;

        // DFS start karo
        helper(root, v, ans, targetSum);

        return ans;
    }
};