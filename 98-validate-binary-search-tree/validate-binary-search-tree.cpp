class Solution {
public:

    // Subtree ka maximum value return karega
    long long maxTree(TreeNode* root) {

        // Agar subtree exist nahi karti to
        // sabse chhoti possible value return karo.
        if(root == NULL) return LLONG_MIN;

        // Current node, left subtree aur right subtree
        // tino me se maximum value return karo.
        return max((long long)root->val,
                   max(maxTree(root->left), maxTree(root->right)));
    }

    // Subtree ka minimum value return karega
    long long minTree(TreeNode* root) {

        // Agar subtree exist nahi karti to
        // sabse badi possible value return karo.
        if(root == NULL) return LLONG_MAX;

        // Current node, left subtree aur right subtree
        // tino me se minimum value return karo.
        return min((long long)root->val,
                   min(minTree(root->left), minTree(root->right)));
    }

    bool isValidBST(TreeNode* root) {

        // Empty tree hamesha valid BST hota hai.
        if(root == NULL) return true;

        // Agar left subtree ka maximum value
        // current node se bada ya equal hai,
        // to BST property violate ho jayegi.
        if((long long)root->val <= maxTree(root->left))
            return false;

        // Agar right subtree ka minimum value
        // current node se chhota ya equal hai,
        // to BST property violate ho jayegi.
        if((long long)root->val >= minTree(root->right))
            return false;

        // Dono subtrees ko recursively check karo.
        return isValidBST(root->left) &&
               isValidBST(root->right);
    }
};