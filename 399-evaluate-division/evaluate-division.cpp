class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& qr) {
        unordered_map<string,unordered_map<string,double>>v;
        set<string>st;
        int i = 0;
        for(auto it:eq){
            string x = it[0];
            string y = it[1];
            double num = val[i++];
            st.insert(x);
            st.insert(y);
            v[x][y] = num;
            v[y][x] = 1*1.0/num;
        }
        const double inf = numeric_limits<double>::infinity();
        for(auto ff:st){
            for(auto ss:st){
                if(ff==ss) v[ff][ss] = 1.0;
                if(v.find(ff) == v.end() or v[ff].find(ss)==v[ff].end()) v[ff][ss] = inf;
            }
        }

        for(auto via:st){
            for(auto ff:st){
                for(auto ss:st){
                    if(v[ff][via] != inf && v[via][ss]!=inf && v[ff][ss] == inf){
                        v[ff][ss] = v[ff][via]*v[via][ss];
                    }
                }
            }
        }
        vector<double>res;
        for(auto q:qr){
            string x = q[0];
            string y = q[1];
            double ans;
            if(v.count(x)==0 || v[x].count(y)==0 || v[x][y] == inf ){
                res.push_back(-1.0);
            }else res.push_back(v[x][y]);
        }
        return res;
    }
};