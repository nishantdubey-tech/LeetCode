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
private:
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

    TreeNode* buildTreeHelper(vector<int>& preorder, int inorderStart, int inorderEnd) {
      
        if (inorderStart > inorderEnd) {
            return nullptr;
        }

     
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

       int inorderRootIndex = inorderMap[rootValue];

        root->left = buildTreeHelper(preorder, inorderStart, inorderRootIndex - 1);
        
        root->right = buildTreeHelper(preorder, inorderRootIndex + 1, inorderEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorderMap.clear();
        preorderIndex = 0;

        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};