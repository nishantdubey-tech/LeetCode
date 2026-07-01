class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        
        int l = 0, sum = 0, count = 0;
        
        for (int r = 0; r < nums.size(); r++) {
            sum += (nums[r]%2);
            
            
            while (sum > goal) {
                sum -= (nums[l]%2);
                l++;
            }
            
           
            count += (r - l + 1);
        }
        
        return count;
    }
};