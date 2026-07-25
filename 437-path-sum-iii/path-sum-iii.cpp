class Solution {
public:

    // Ye function current node se start hone wale
    // valid paths ki count return karta hai
    int helper(TreeNode* root, long long sum){

        // Agar node NULL hai to koi path nahi
        if(root == NULL) return 0;

        // Current node ki wajah se milne wale paths
        int count = 0;

        // Agar current node ki value remaining sum ke equal hai
        // to ek valid path mil gaya
        if((long long)root->val == sum){
            count++;
        }

        // Left subtree se milne wale valid paths add karo
        count += helper(root->left, sum - (long long)root->val);

        // Right subtree se milne wale valid paths add karo
        count += helper(root->right, sum - (long long)root->val);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {

        // Empty tree me koi path nahi
        if(root == NULL) return 0;

        // Total paths =
        // 1. Current node se start hone wale paths
        // 2. Left subtree ke har node se start hone wale paths
        // 3. Right subtree ke har node se start hone wale paths
        return helper(root, (long long)targetSum)
             + pathSum(root->left, targetSum)
             + pathSum(root->right, targetSum);
    }
};