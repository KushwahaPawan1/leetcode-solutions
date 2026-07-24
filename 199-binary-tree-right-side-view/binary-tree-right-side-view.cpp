class Solution {
public:

    int levels(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    void nthLevel(TreeNode* root, int curr, int level, vector<int>& ans) {

        if (root == NULL) return;

        if (curr == level) {
            // Same level ka last visited node store hoga
            ans[level] = root->val;
            return;
        }

        // Left pehle, right baad me
        // Right overwrite karega => Right View
        nthLevel(root->left, curr + 1, level, ans);
        nthLevel(root->right, curr + 1, level, ans);
    }

    void levelOrder(TreeNode* root, vector<int>& ans) {

        int h = levels(root);

        for (int i = 0; i < h; i++) {
            nthLevel(root, 0, i, ans);
        }
    }

    vector<int> rightSideView(TreeNode* root) {

        if (root == NULL) return {};

        vector<int> ans(levels(root));

        levelOrder(root, ans);

        return ans;
    }
};