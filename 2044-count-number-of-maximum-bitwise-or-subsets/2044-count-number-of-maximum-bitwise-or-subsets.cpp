#include <vector>

class Solution {
public:
    int countMaxOrSubsets(std::vector<int>& nums) {
        int target_or = 0;
        for (int num : nums) {
            target_or |= num;
        }

        return dfs(0, 0, target_or, nums);
    }

private:
    int dfs(int idx, int current_or, int target_or, const std::vector<int>& nums) {
        if (current_or == target_or) {
            return 1 << (nums.size() - idx);
        }
        if (idx == nums.size()) {
            return 0;
        }
        int include = dfs(idx + 1, current_or | nums[idx], target_or, nums);
        int exclude = dfs(idx + 1, current_or, target_or, nums);

        return include + exclude;
    }
};