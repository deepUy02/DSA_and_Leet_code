TC-O(N)
SC-O(1)
int solve(TreeNode* root ,int curr){
    //base case
    if(root == NULL)    return 0;
    curr = (curr*10) + root -> val;

    if(root->left == NULL && root ->right == NULL){
        return curr;     
    } 
    int left = solve(root->left , curr);
    int right = solve(root->right, curr);
    return left + right;
}    
int sumNumbers(TreeNode* root) {        
    return solve(root, 0);
}