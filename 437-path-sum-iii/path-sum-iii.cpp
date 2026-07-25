class Solution {
public:

    // Ye function sirf un paths ko count karta hai
    // jo current node se start hote hain.
    void helper(TreeNode* root, long long sum, int& count){

        // Agar node NULL hai to return
        if(root == NULL) return;

        // Agar current node ki value remaining sum ke equal hai
        // to ek valid path mil gaya
        if((long long)root->val == sum){
            count++;
        }

        // Left subtree me remaining sum ke saath search karo
        helper(root->left, sum - (long long)root->val, count);

        // Right subtree me remaining sum ke saath search karo
        helper(root->right, sum - (long long)root->val, count);
    }

    int pathSum(TreeNode* root, int targetSum) {

        // Empty tree me koi path nahi hoga
        if(root == NULL) return 0;

        // Total valid paths count karega
        int count = 0;

        // Current node ko starting point maan kar
        // saare downward paths check karo
        helper(root, (long long)targetSum, count);

        // Ab left subtree ke har node ko starting point banao
        // aur right subtree ke har node ko bhi starting point banao
        count += pathSum(root->left, targetSum)
              +  pathSum(root->right, targetSum);

        return count;
    }
};