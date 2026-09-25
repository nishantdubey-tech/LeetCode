class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1; 
        int max_area = 0; 

        while (l < r) {
            
            int w = r - l;
            int current_area = w * min(height[l], height[r]);
            
            max_area = max(max_area, current_area);
            
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return max_area;
    }
};