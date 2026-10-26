class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int x: nums) freq[x]++;
        using p=pair<int,int>;
        priority_queue<p,vector<p>,greater<p>>pq;
        for(auto& [value,count]:freq){
            pq.push({count,value});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};