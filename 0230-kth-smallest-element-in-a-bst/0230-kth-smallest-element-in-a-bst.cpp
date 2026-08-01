/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 void inorderTraversal(TreeNode* root, vector<int>& values) {
        if (root) {
            inorderTraversal(root->left, values);
            values.push_back(root->val);
            inorderTraversal(root->right, values);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
         vector<int> values;
        inorderTraversal(root, values);
        int kth_smallest = values[k-1];
      
        
        return kth_smallest;
    }
};