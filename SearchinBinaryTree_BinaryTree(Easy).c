struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode* x = NULL;
    if (root == NULL) {
        return NULL;
    }
    if (root->val == val) {
        x = root;
    } else {
        if (root->val < val) {
            x = searchBST(root->right, val);
        } else {
            x = searchBST(root->left, val);
        }
    }
    return x;
}