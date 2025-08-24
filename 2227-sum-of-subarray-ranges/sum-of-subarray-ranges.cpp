class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> minL(n), minR(n), maxL(n), maxR(n);
        stack<int> minst, maxst;

        // previous smaller / greater
        for (int i = 0; i < n; i++) {
            while (!minst.empty() && nums[i] < nums[minst.top()]) minst.pop();
            while (!maxst.empty() && nums[i] > nums[maxst.top()]) maxst.pop();

            minL[i] = minst.empty() ? -1 : minst.top();
            maxL[i] = maxst.empty() ? -1 : maxst.top();

            minst.push(i);
            maxst.push(i);
        }

        while (!minst.empty()) minst.pop();
        while (!maxst.empty()) maxst.pop();

        // next smaller / greater
        for (int i = n - 1; i >= 0; i--) {
            while (!minst.empty() && nums[i] <= nums[minst.top()]) minst.pop();
            while (!maxst.empty() && nums[i] >= nums[maxst.top()]) maxst.pop();

            minR[i] = minst.empty() ? n : minst.top();
            maxR[i] = maxst.empty() ? n : maxst.top();

            minst.push(i);
            maxst.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long cntMax = (long long)(i - maxL[i]) * (maxR[i] - i);
            long long cntMin = (long long)(i - minL[i]) * (minR[i] - i);
            sum += 1LL * nums[i] * (cntMax - cntMin);
        }
        return sum;
    }
};
