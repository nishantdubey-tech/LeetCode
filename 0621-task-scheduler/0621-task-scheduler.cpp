class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char c: tasks){
            freq[c - 'A']++;
        }
        priority_queue<int>pq;
        for(int f: freq){
            if(f>0) pq.push(f);
        } 
        int time=0;
        while(!pq.empty()){
            vector<int>used;
            int cycle=n+1;
            while(cycle>0 && !pq.empty()){
                int f=pq.top();
                pq.pop();
                if(f>1) used.push_back(f-1);
                time++;
                cycle--;
            }
            for(int f: used) pq.push(f);
            if(pq.empty()) break;
            time += cycle;
        }
        return time;
    }
};