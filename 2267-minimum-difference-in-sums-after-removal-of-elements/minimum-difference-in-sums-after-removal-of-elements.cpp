class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long n = nums.size()/3;
        vector<long long>minsumv(3*n);
        vector<long long>maxsumv(3*n);

        long long minsum = 0;
        priority_queue<long long>maxHeap;
        for(long long i=0; i<=2*n-1; i++){
            if(maxHeap.size()<n){
                maxHeap.push(nums[i]);
                minsum += nums[i];
            }else if(maxHeap.top() > nums[i]){
                minsum -= maxHeap.top();
                maxHeap.pop();
                maxHeap.push(nums[i]);
                minsum += nums[i];
            }
            minsumv[i] = minsum;
        }
        priority_queue<long long,vector<long long>,greater<long long>>minHeap;
        long long maxsum = 0;
        for(long long i=3*n-1; i>=n; i--){
            if(minHeap.size()<n) {
                minHeap.push(nums[i]);
                maxsum += nums[i];
            }else if(minHeap.top() < nums[i]){
                maxsum -= minHeap.top();
                minHeap.pop();
                minHeap.push(nums[i]);
                maxsum += nums[i];
            }
            maxsumv[i] = maxsum;
        }

        long long res = LLONG_MAX;

        for(int i=n-1; i<=2*n-1; i++){
            res = min(res,(minsumv[i]-maxsumv[i+1]));
        }
        return res;
    }
};