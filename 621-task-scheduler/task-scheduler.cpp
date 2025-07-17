class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks)
            freq[task - 'A']++;

        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0)
                pq.push(f);
        }

        int time = 0;

        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> temp;

            while (cycle > 0 && !pq.empty()) {
                int top = pq.top(); pq.pop();
                if (top > 1)
                    temp.push_back(top - 1); 
                cycle--;
                time++;
            }

            for (int f : temp) {
                pq.push(f);
            }

            if (!pq.empty()) {
                time += cycle;
            }
        }

        return time;
    }
};
