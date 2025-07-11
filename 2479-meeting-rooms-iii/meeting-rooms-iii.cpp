class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        using ll = long long;
        priority_queue<int, vector<int>, greater<int>> freerooms;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> meets;

        sort(meetings.begin(), meetings.end());
        for (int i = 0; i < n; i++) freerooms.push(i);

        vector<int> freq(n, 0);
        int maxfreq = 0, maxroom = 0;
        int i = 0, m = meetings.size();
        ll time = 0;

        while (i < m) {
            // Free rooms that finished
            while (!meets.empty() && meets.top().first <= time) {
                freerooms.push(meets.top().second);
                meets.pop();
            }

            // ✅ If no rooms free, skip time to earliest end time
            if (freerooms.empty()) {
                time = meets.top().first;
                continue;
            }

            // ✅ Don't process a meeting until its start time
            if (time < meetings[i][0]) {
                time = meetings[i][0];
                continue;
            }

            int room = freerooms.top(); freerooms.pop();
            ll duration = meetings[i][1] - meetings[i][0];
            ll endtime = time + duration;

            meets.push({endtime, room});
            freq[room]++;

            if (freq[room] > maxfreq || (freq[room] == maxfreq && room < maxroom)) {
                maxfreq = freq[room];
                maxroom = room;
            }

            i++;
        }

        return maxroom;
    }
};
