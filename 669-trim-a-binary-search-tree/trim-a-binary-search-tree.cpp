class Solution {
public:

    void trim(TreeNode* root, int lo, int hi) {

        // Agar root NULL hai to kuch trim nahi karna
        if (root == NULL)
            return;

        // Left child ko check karte raho jab tak wo valid range me na aa jaye
        while (root->left != NULL) {

            // Agar left child ki value lo se chhoti hai,
            // to left child aur uska left subtree valid nahi hoga
            // isliye uske right child ko connect kar do
            if (root->left->val < lo) {
                root->left = root->left->right;
            }

            // Agar left child ki value hi se badi hai,
            // to uska right subtree bhi range ke bahar hoga
            // isliye uske left child ko connect kar do
            else if (root->left->val > hi) {
                root->left = root->left->left;
            }

            // Agar left child [lo, hi] range me hai to stop
            else {
                break;
            }
        }


        // Right child ko check karte raho jab tak wo valid range me na aa jaye
        while (root->right != NULL) {

            // Agar right child ki value hi se badi hai,
            // to right child aur uska right subtree valid nahi hoga
            // isliye uske left child ko connect kar do
            if (root->right->val > hi) {
                root->right = root->right->left;
            }

            // Agar right child ki value lo se chhoti hai,
            // to uska left subtree bhi range ke bahar hoga
            // isliye uske right child ko connect kar do
            else if (root->right->val < lo) {
                root->right = root->right->right;
            }

            // Agar right child [lo, hi] range me hai to stop
            else {
                break;
            }
        }


        // Ab left subtree ko recursively trim karo
        trim(root->left, lo, hi);

        // Ab right subtree ko recursively trim karo
        trim(root->right, lo, hi);
    }


    TreeNode* trimBST(TreeNode* root, int lo, int hi) {

        // Dummy node banaya taaki original root bhi
        // range ke bahar ho to easily remove ho sake
        TreeNode* dummy = new TreeNode(INT_MAX);

        // Original tree ko dummy ke left me attach kar diya
        dummy->left = root;

        // Puri BST ko trim karo
        trim(dummy, lo, hi);

        // Dummy ke left me final trimmed BST milegi
        return dummy->left;
    }
};