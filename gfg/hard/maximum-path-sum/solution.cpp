class Solution {
int ans;
int solve(Node* root) {
if (root == NULL)
return 0;
if (root->left == NULL && root->right == NULL)
return root->data;
if (root->left == NULL)
return root->data + solve(root->right);
if (root->right == NULL)
return root->data + solve(root->left);
int left = solve(root->left);
int right = solve(root->right);
ans = max(ans, left + right + root->data);
return root->data + max(left, right);
}
public:
int maxPathSum(Node* root) {
ans = -1000000000;
solve(root);
if (root == NULL)
return -1;
// Check whether there are at least two leaves
int leaves = countLeaves(root);
if (leaves < 2)
return -1;
return ans;
}
int countLeaves(Node* root) {
if (root == NULL)
return 0;
if (root->left == NULL && root->right == NULL)
return 1;
return countLeaves(root->left) + countLeaves(root->right);
}
};