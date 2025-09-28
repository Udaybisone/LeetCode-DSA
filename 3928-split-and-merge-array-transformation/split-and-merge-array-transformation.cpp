class Solution {
public:
    int minSplitMerge(vector<int>& v, vector<int>& dv) {
        int n = v.size();

        queue<tuple<int, vector<int>>> q;

        q.push({0,v});

        map<vector<int>,int>vis;
        vis[v] = 1;
        
        while(!q.empty()){
            auto [op,vec] = q.front();
            q.pop();

            if(vec==dv) return op;

            for(int i=0; i<n; i++){
                for(int j=i; j<n; j++){
                    vector<int> v1(vec.begin(), vec.end() - (n - i));      
                    vector<int> v2(vec.begin() + i, vec.end() - (n - j));  
                    vector<int> v3(vec.begin() + j, vec.end());            
                    int v1s = v1.size();


                    for(int ps=0; ps<v1s; ps++){
                        vector<int>a;
                        for(int x=0; x<ps; x++) a.push_back(v1[x]);
                        a.insert(a.end(),v2.begin(),v2.end());
                        for(int x=ps; x<v1s; x++) a.push_back(v1[x]);
                        a.insert(a.end(),v3.begin(),v3.end());

                        if(!vis[a]){
                            q.push({op+1,a});
                            vis[a] = 1;
                        }
                    }

                    int v3s = v3.size();

                    for(int ps=1; ps<=v3s; ps++){
                        vector<int>a;
                        a.insert(a.end(),v1.begin(),v1.end());
                        for(int x=0; x<ps; x++) a.push_back(v3[x]);
                        a.insert(a.end(),v2.begin(),v2.end());
                        for(int x=ps; x<v3s; x++) a.push_back(v3[x]);

                        if(!vis[a]){
                            q.push({op+1,a});
                            vis[a] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};