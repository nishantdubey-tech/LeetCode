class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int suff=1;
        int pref=1;
        for(int i=0;i<n;i++){
           
            if(pref==0)pref=1;
             if(suff==0)suff=1;

            pref*=nums[i];
            suff*=nums[n-i-1];
            ans=max(ans,max(pref,suff));
        }

          return ans;
        
    }
};