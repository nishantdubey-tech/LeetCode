class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int n = gas.size();

    int total = 0;
    int curr = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {

        int diff = gas[i] - cost[i];

        total += diff;
        curr += diff;

        if (curr < 0) {

            start = i + 1;

            curr = 0;
        }
    }
    if (total < 0) {
        return -1;
    }

    return start;
    }
};