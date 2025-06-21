class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>freq(26,0);
        for(auto c:word) freq[c-'a']++;
        int ans = INT_MAX;
        sort(freq.begin(),freq.end());
        int idx = 0;
        while(idx<26 && freq[idx]==0) idx++;
        int sum = 0;
        // cout<<idx<<endl;
        for(int i=idx; i<26; i++){
            int j = 25;
            int deleted = 0;
            while(j>i && (freq[j]-freq[i])>k) deleted += (freq[j--]-freq[i]-k);
            ans = min(ans,deleted+sum);
            sum += freq[i];
        }
        return ans;
    }
};