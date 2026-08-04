class Solution {
public:
    void flatten(TreeNode* root) {

        // Agar tree empty hai to kuch flatten nahi karna
        if(root == NULL) return;

        // curr pointer se tree ko traverse karenge
        TreeNode* curr = root;

        while(curr != NULL) {

            // Agar current node ka left subtree exist karta hai
            if(curr->left != NULL) {

                // Current node ka original right subtree save kar lo
                // kyunki abhi curr->right ko left subtree se replace karenge
                TreeNode* r = curr->right;


                // Left subtree ko current node ke right me shift kar diya
                //
                // Pehle:
                //       curr
                //      /    \
                //    left     r
                //
                // Ab:
                //       curr
                //          \
                //          left
                curr->right = curr->left;


                // Ab left subtree ka last/rightmost node find karna hai
                // Ye node predecessor ki tarah kaam karega
                //
                // Iske right me hum original right subtree 'r' attach karenge
                TreeNode* pred = curr->left;

                // Left subtree ke rightmost node tak jao
                while(pred->right != NULL) {
                    pred = pred->right;
                }


                // Left subtree ke last node ke right me
                // original right subtree attach kar diya
                //
                // curr -> left subtree -> original right subtree
                pred->right = r;


                // Ab next node par move karo
                // curr->left abhi wahi node hai jise humne curr->right me lagaya tha
                curr = curr->left;
            }

            else {

                // Agar left subtree nahi hai
                // to simply right wale next node par move karo
                curr = curr->right;
            }
        }


        // Upar humne right pointers ko preorder order me arrange kar diya hai
        // Lekin old left pointers abhi bhi lage hue hain
        // Flattened tree me har node ka left NULL hona chahiye
        TreeNode* temp = root;

        // Right chain ko traverse karke
        // har node ka left pointer NULL kar do
        while(temp->right != NULL) {

            temp->left = NULL;

            // Next node par move karo
            temp = temp->right;
        }
    }
};