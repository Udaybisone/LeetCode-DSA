class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int cnt = 0;
        for(int i=0; i<n; i++){
            int curr = nums[i];
            int prev = nums[i]-1;
            int next = nums[i]+1;
            int newlen = 1;
            if(mp.find(curr) != mp.end()) continue;
            if(mp.find(prev) != mp.end() && mp.find(next)!=mp.end()){
                int prevlen = mp[prev];
                int nextlen = mp[next];
                newlen = prevlen + nextlen + 1;
                mp[curr-prevlen] = newlen;
                mp[curr+nextlen] = newlen;
                mp[curr] = newlen;
            }else if(mp.find(prev) != mp.end()){
                int prevlen = mp[prev];
                newlen = prevlen + 1;
                mp[curr-prevlen] = newlen;
                mp[curr] = newlen;
            }else if(mp.find(next) != mp.end()){
                int nextlen = mp[next];
                newlen = nextlen + 1;
                mp[curr+nextlen] = newlen;
                mp[curr] = newlen;
            }else mp[curr] = 1;
            cout<<newlen<<endl;
            cnt = max(cnt,newlen);
        }
        return cnt;
    }
};