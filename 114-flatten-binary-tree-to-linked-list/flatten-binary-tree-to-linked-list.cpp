class Solution {
public:
    void flatten(TreeNode* root) {

        // Base case:
        // Agar current node NULL hai to flatten karne ke liye kuch nahi hai
        if(root == NULL) return;


        // Current root ke original left subtree ko save kar lo
        // Kyunki aage hum root->left ko NULL karne wale hain
        TreeNode* l = root->left;

        // Current root ke original right subtree ko bhi save kar lo
        // Kyunki root->right ko bhi temporarily NULL karenge
        TreeNode* r = root->right;


        // Flattened tree me kisi bhi node ka left child nahi hona chahiye
        // Isliye current root ka left NULL kar diya
        root->left = NULL;

        // Right ko bhi temporarily NULL kar diya
        // Original right subtree already 'r' me save hai
        root->right = NULL;


        // Pehle original left subtree ko recursively flatten karo
        // flatten(l) ke baad:
        // l ka poora subtree ek right-side linked list jaisa ban jayega
        flatten(l);

        // Ab original right subtree ko bhi recursively flatten karo
        // flatten(r) ke baad:
        // r ka poora subtree bhi right-side linked list jaisa ban jayega
        flatten(r);


        // Preorder order hota hai:
        // Root -> Left -> Right
        //
        // Isliye current root ke right me
        // flattened LEFT subtree ko attach kar diya
        root->right = l;


        // Ab hume flattened left subtree ke END tak jana hai
        // taaki uske baad original right subtree attach kar sake
        TreeNode* temp = root;

        // temp ko right-right move karate rahenge
        // jab tak flattened left part ka last node nahi mil jata
        //
        // Example:
        // root -> 2 -> 3 -> 4
        //                  ^
        //                temp
        while(temp->right != NULL) {
            temp = temp->right;
        }


        // Ab temp flattened left subtree ke last node par hai
        // Iske right me flattened original right subtree attach kar do
        temp->right = r;


        // Final structure:
        //
        // root
        //   \
        //    flattened LEFT subtree
        //              \
        //               flattened RIGHT subtree
        //
        // Isse preorder sequence maintain hoti hai:
        // Root -> Left -> Right
    }
};