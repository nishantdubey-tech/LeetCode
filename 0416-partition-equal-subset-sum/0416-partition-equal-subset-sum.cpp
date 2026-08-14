class Solution {
public:
    bool subsetsum(int n,int k,vector<int>&nums){
        vector<bool>curr(k+1,0),prev(k+1,0);
        prev[0]=curr[0]=true;
        if(nums[0]<=k){
        prev[nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool nottake=prev[target];
                bool take=false;
                if(nums[i]<=target) take=prev[target-nums[i]];
                curr[target]=take | nottake;
            }
            prev=curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
       int sum=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
        sum+=nums[i];
       }
       if(sum % 2)return false;
       int target=sum/2;
       return subsetsum(n,target,nums);
    }
};