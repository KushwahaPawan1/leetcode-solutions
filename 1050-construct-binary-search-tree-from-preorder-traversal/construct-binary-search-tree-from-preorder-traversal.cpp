class Solution {
public:

    // Preorder aur Inorder ki help se BST construct karega.
    TreeNode* build(vector<int>& pre, int prelo, int prehi,
                    vector<int>& in, int inlo, int inhi) {

        // Agar range invalid ho gayi to node exist nahi karega.
        if(prelo > prehi) return NULL;

        // Preorder ka first element hamesha root hota hai.
        TreeNode* root = new TreeNode(pre[prelo]);

        // Sirf ek hi node bachi hai.
        if(prelo == prehi) return root;

        // Inorder me root ki position dhoondo.
        int i = inlo;
        while(i <= inhi) {
            if(in[i] == pre[prelo]) break;
            i++;
        }

        // Left subtree me kitne nodes hain.
        int leftCount = i - inlo;

        // Right subtree me kitne nodes hain.
        int rightCount = inhi - i;

        // Left subtree construct karo.
        root->left = build(pre,
                           prelo + 1,
                           prelo + leftCount,
                           in,
                           inlo,
                           i - 1);

        // Right subtree construct karo.
        root->right = build(pre,
                            prelo + leftCount + 1,
                            prehi,
                            in,
                            i + 1,
                            inhi);

        // Current subtree ka root return karo.
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        // Preorder ki copy banao.
        vector<int> in = preorder;

        // Copy ko sort kar do.
        // Sorted array hi inorder traversal hota hai BST ka.
        sort(in.begin(), in.end());

        int n = preorder.size();

        // Preorder + Inorder se BST construct karo.
        return build(preorder, 0, n - 1,
                     in, 0, n - 1);
    }
};