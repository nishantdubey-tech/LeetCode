/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        // Step 1: Initialize the parent map using a standard BFS
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
        
        // Step 2: Second BFS starting from the target node to find nodes at distance k
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            // If we have reached the k-th level, stop expanding
            if (curr_level == k) break;
            curr_level++;
            
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                
                // Check Left Child
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                
                // Check Right Child
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                
                // Check Parent (Moving Upwards)
                if (parent_track[current] && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        
        // Collect all remaining elements in the queue (which are exactly at distance k)
        vector<int> result;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        
        return result;
    }
};