class Solution {
public:
    void findcombination(int ind,int tar,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        if(ind==arr.size()){
            if(tar==0){
                ans.push_back(ds);
                
            }
            return;
        }
        if(arr[ind]<=tar){
            ds.push_back(arr[ind]);
            findcombination(ind,tar-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        findcombination(ind+1,tar,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findcombination(0,target,candidates,ans,ds);
        return ans;
    }
};