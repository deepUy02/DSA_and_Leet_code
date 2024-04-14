int solve(TreeNode* root,bool ans){
        if(root == NULL)    return 0;
        if(ans == false && root -> right == NULL && root -> left == NULL){
            return root->val;
        }
        return solve(root -> left , false) + solve(root -> right , true);
}
int sumOfLeftLeaves(TreeNode* root) {
    return solve(root,true);
}