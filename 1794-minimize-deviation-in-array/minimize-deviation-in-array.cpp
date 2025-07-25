class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mini = INT_MAX;

        // Normalize the array: make all elements even
        for(int num : nums) {
            if(num % 2) num *= 2; // make odd numbers even
            pq.push(num);
            mini = min(mini, num);
        }

        int res = INT_MAX;

        while(true) {
            int maxVal = pq.top(); pq.pop();
            res = min(res, maxVal - mini);

            if(maxVal % 2 == 0) {
                maxVal /= 2;
                mini = min(mini, maxVal);
                pq.push(maxVal);
            } else {
                // If max is odd, we can't reduce further
                break;
            }
        }

        return res;
    }
};
