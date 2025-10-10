class Solution {
public:
    int integerReplacement(int n) {
        priority_queue<tuple<long long,long long>,vector<tuple<long long,long long>>,greater<>>pq;

        long long num = n;
        pq.push({0,num});
        unordered_set<long long>vis;
        vis.insert(num);
        while(!pq.empty()){
            auto [op,num] = pq.top();
            pq.pop();

            if(num==1) return op;
            if(num%2==0){
                pq.push({op+1,num/2});
                continue;
            }
            if(!vis.count(num-1)) {
                pq.push({op+1,num-1});
                vis.insert(num-1);
            }
            if(!vis.count(num+1)) {
                pq.push({op+1,num+1});
                vis.insert(num+1);
            }
        }

        return -1;
    }
};