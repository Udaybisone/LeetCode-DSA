class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>avs;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>busys;
        queue<int>tasq;
        int n = servers.size(), m = tasks.size();

        for(int i=0; i<n; i++){
            avs.push({servers[i],i});
        }
        int i = 0;
        int t = 0;
        vector<int>res(m);
        while(i<m or !tasq.empty()){
            while(i<m && i<=t) tasq.push(i++);

            while(!busys.empty() && busys.top().first <= t){
                avs.push({servers[busys.top().second],busys.top().second});
                busys.pop();
            }

            while(!avs.empty() && !tasq.empty()){
                int taskidx = tasq.front();
                tasq.pop();
                int taskdur = tasks[taskidx];
                int sidx = avs.top().second;
                avs.pop();
                res[taskidx] = sidx;
                busys.push({t+taskdur,sidx});
            }
            if(avs.empty()){
                t = busys.top().first;
            }else if(tasq.empty()) t++;
        }
        return res;
    }
};