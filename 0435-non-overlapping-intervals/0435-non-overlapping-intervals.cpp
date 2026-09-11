class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
     }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size();
        int endtime=intervals[0][1];
        int cnt=0;
    
        for(int i=1;i<n;i++){
              if(intervals[i][0]>= endtime){
                endtime=intervals[i][1];
              }else{
                cnt++;
              }
        }
        return cnt;
    }
};