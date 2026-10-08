class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k_val;

public:
    KthLargest(int k, vector<int>& nums) {
        k_val = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k_val) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};