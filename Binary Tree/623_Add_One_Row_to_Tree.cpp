TC-O(N)
SC-O(1)
TreeNode* solve(TreeNode* root, int val ,int depth,int curr){
    //base case
    if(root == NULL){            
	return NULL;
    }
    if(curr == depth - 1){  
       TreeNode* leftTemp = root->left;
       TreeNode* rightTemp = root->right;
            
       root->left = new TreeNode(val);
       root->right = new TreeNode(val);

       root->left->left = leftTemp;
       root->right->right = rightTemp;
       return root;
    }
    root->left=solve(root->left ,val ,depth, curr+1);
    root->right=solve(root->right,val, depth, curr+1);
    return root;
}
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if(depth == 1){
    	TreeNode* newRoot = new TreeNode(val);

        newRoot-> left = root;
        return newRoot;
    }
    int curr = 1;
    return solve(root, val ,depth ,curr);
}