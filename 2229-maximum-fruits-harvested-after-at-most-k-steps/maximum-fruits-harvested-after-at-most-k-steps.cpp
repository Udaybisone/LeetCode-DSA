class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fr, int st, int k) {
        
        int n = fr.size();
        vector<int>pre(2*1e6,0);
        for(auto it:fr){
            pre[it[0]] = it[1];
        }
        for(int i=1; i<=2*1e5; i++) pre[i] += pre[i-1];
        int ans = 0;
        int presize = pre.size();
        for(int i=1; i<=min(st,k); i++){
            int leftidx = st - i;
            int leftsum = pre[st] - ((leftidx==0)?0:pre[leftidx-1]);
            int remain = max(0,k - 2*i);
            
            int rightidx = min(presize-1,st+remain);
            int rightsum = pre[rightidx] - pre[st];

            ans = max(ans,leftsum+rightsum);
        }
        cout<<ans<<endl;
        int maxi  = 0;
        for(int i=0; i<=min(k,presize-st-1); i++){
            int rightidx = st+i;
            int rightsum = pre[rightidx] - ((st==0)?0:pre[st-1]);
            int remain = max(0,k-2*i);

            int leftidx = max(0,st-remain);
            int leftsum = ((st==0)?0:pre[st-1]) - ((leftidx==0)?0:pre[leftidx-1]);

            ans = max(ans,leftsum+rightsum);
            maxi = max(maxi,leftsum+rightsum);
        }
        // cout<<ans<<endl;
        cout<<maxi<<endl;
        return ans;
    }
};