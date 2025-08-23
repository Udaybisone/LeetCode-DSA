#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;  // stores sequence lengths at boundaries
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            int curr = nums[i];
            int prev = curr - 1;
            int next = curr + 1;

            if(mp.find(curr) != mp.end()) continue;  // skip duplicates

            int newlen = 1;

            if(mp.find(prev) != mp.end() && mp.find(next) != mp.end()) {
                // both sides exist -> merge
                int prevlen = mp[prev];
                int nextlen = mp[next];
                newlen = prevlen + nextlen + 1;
                mp[curr - prevlen] = newlen;  // update left boundary
                mp[curr + nextlen] = newlen;  // update right boundary
                mp[curr] = newlen;            // ✅ fix: also update current
            } 
            else if(mp.find(prev) != mp.end()) {
                // extend sequence on the left
                int prevlen = mp[prev];
                newlen = prevlen + 1;
                mp[curr - prevlen] = newlen;  // update left boundary
                mp[curr] = newlen;            // update current
            } 
            else if(mp.find(next) != mp.end()) {
                // extend sequence on the right
                int nextlen = mp[next];
                newlen = nextlen + 1;
                mp[curr + nextlen] = newlen;  // update right boundary
                mp[curr] = newlen;            // update current
            } 
            else {
                // new isolated number
                mp[curr] = 1;
            }

            cnt = max(cnt, newlen);
        }

        return cnt;
    }
};
