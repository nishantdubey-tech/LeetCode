class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int zeropos=0;
        for(int curr=0;curr<n;curr++){
            if(nums[curr]!=0){
                swap(nums[curr],nums[zeropos]);
                zeropos++;
            }

        }
    }
};