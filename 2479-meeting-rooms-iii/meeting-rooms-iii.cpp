class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int,vector<int>,greater<int>> freerooms;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> meets;
        sort(meetings.begin(), meetings.end());

        for(int i = 0; i < n; i++) freerooms.push(i);
        vector<int> freq(n, 0);

        for(auto &meet : meetings){
            long long start = meet[0], end = meet[1];

            // Free up rooms
            while(!meets.empty() && meets.top().first <= start){
                freerooms.push(meets.top().second);
                meets.pop();
            }

            if(freerooms.empty()){
                auto [nextEnd, room] = meets.top(); meets.pop();
                start = nextEnd;
                end = start + (meet[1] - meet[0]);
                freerooms.push(room);
            }

            int room = freerooms.top(); freerooms.pop();
            freq[room]++;
            meets.push({end, room});
        }

        int maxroom = 0;
        for(int i = 1; i < n; i++){
            if(freq[i] > freq[maxroom]) maxroom = i;
        }

        return maxroom;
    }
};
