class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sorted=arr;
        sort(sorted.begin(),sorted.end());

        unordered_map<int,int>mpp;
        int rank=0;
        for(int x:sorted){
            if(mpp.find(x)== mpp.end()){
                mpp[x]=++rank;
            }
        }
        vector<int>ans;
        for(int x:arr){
            ans.push_back(mpp[x]);
        }

       return ans;

    }
};