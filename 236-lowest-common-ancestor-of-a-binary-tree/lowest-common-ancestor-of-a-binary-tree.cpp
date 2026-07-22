class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base case:
        // Agar tree khatam ho gaya ya p/q mil gaya,
        // to wahi node return kar do.
        if (root == NULL || root == p || root == q)
            return root;

        // Left subtree me LCA ya p/q dhoondo
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Right subtree me LCA ya p/q dhoondo
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Agar dono side se non-null aaya,
        // iska matlab p aur q alag-alag subtree me hain.
        // Current root hi unka Lowest Common Ancestor hai.
        if (left != NULL && right != NULL)
            return root;

        // Agar sirf left se answer mila,
        // to wahi answer upar bhej do.
        if (left != NULL)
            return left;

        // Warna right wala answer bhej do.
        return right;
    }
};