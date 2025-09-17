class Graph {
    int n;
    vector<vector<pair<int,int>>>adj;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(300);
        for(auto v:edges){
            adj[v[0]].push_back({v[1],v[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dist(300,INT_MAX);
        priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<>>pq;

        pq.push({0,node1});
        dist[node1] = 0;

        while(!pq.empty()){
            auto [currdist,node] = pq.top();
            pq.pop();

            if(node==node2) return currdist;

            for(auto [adjnode,wt]:adj[node]){
                int newdist = currdist + wt;
                if(newdist < dist[adjnode]){
                    dist[adjnode] = newdist;
                    pq.push({newdist,adjnode});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */