int solve(TreeNode<int> *root, int &m){
    if(!root) return 0;
    
    int ls = solve(root->left, m);
    int rs = solve(root->right, m);
    
   	int subsum = ls + rs + root->data;
    m = max(subsum, m);
    return subsum;
    
}
int largestSubtreeSum(TreeNode<int> *root) {
	// Write your code here.
    int m = INT_MAX;
    solve(root, m);
    return m;
     
}