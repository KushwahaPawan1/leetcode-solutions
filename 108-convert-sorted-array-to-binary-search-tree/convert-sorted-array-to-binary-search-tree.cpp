class Solution {
public:

    // Sorted array se height balanced BST banayega.
    TreeNode* helper(vector<int>& arr, int lo, int hi) {

        // Agar range invalid ho gayi to node exist nahi karega.
        if(lo > hi) return NULL;

        // Middle element ko root banao.
        int mid = lo + (hi - lo) / 2;

        // Middle element ki new node create karo.
        TreeNode* root = new TreeNode(arr[mid]);

        // Left half se left subtree banao.
        root->left = helper(arr, lo, mid - 1);

        // Right half se right subtree banao.
        root->right = helper(arr, mid + 1, hi);

        // Current subtree ka root return karo.
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& arr) {

        // Array ka size nikalo.
        int n = arr.size();

        // Puri array se BST construct karo.
        return helper(arr, 0, n - 1);
    }
};