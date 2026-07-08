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
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, vector<pair<int, int>>> nodes;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int r = p.second.first;
            int c = p.second.second;
            
            nodes[c].push_back({r, node->val});
            
            if (node->left) q.push({node->left, {r + 1, c - 1}});
            if (node->right) q.push({node->right, {r + 1, c + 1}});
        }
        
        vector<vector<int>> result;
        for (auto& entry : nodes) {
            
            sort(entry.second.begin(), entry.second.end());
            
            vector<int> colNodes;
            for (auto& p : entry.second) {
                colNodes.push_back(p.second);
            }
            result.push_back(colNodes);
        }
        
        return result;
    }
};