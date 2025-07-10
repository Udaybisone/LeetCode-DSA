class Solution {
public:
    int maxFreeTime(int evt, vector<int>& st, vector<int>& et) {

        st.push_back(evt);
        et.push_back(evt);
        st.insert(st.begin(), 0);
        et.insert(et.begin(), 0);
        int n = st.size();
        int ft = -1, sc = -1, th = -1;
        int ftidx, scidx,thidx;

        for(int i=1; i<n; i++){
            int gap = st[i] - et[i-1];
            if(gap>ft){
                th = sc;
                thidx = scidx;
                sc = ft;
                scidx = ftidx;
                ft = gap;
                ftidx = i;
            }else if(gap>sc){
                th = sc;
                thidx = scidx;
                sc = gap;
                scidx = i;
            }else if(gap>th){
                th = gap;
                thidx = i;
            }
        }


        int ans = 0;
        for(auto it:st){
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto it:et){
            cout<<it<<" ";
        }
        cout<<endl;
        cout<<ft<<endl;
        cout<<scidx<<endl;
        cout<<th<<endl;
        for(int i=1; i<n-1; i++){
            int dur = et[i]-st[i];
            if(ft!=0 && ftidx != i && ftidx != i+1 && ft>=dur) ans = max(ans,(st[i+1]-et[i-1]));
            if(sc!=0 && scidx != i && scidx != i+1 && sc>=dur) ans = max(ans,(st[i+1]-et[i-1]));
            if(th!=0 && thidx != i && thidx != i+1 && th>=dur) ans = max(ans,(st[i+1]-et[i-1]));
            ans = max({ans,(st[i]-et[i-1])+(st[i+1]-et[i])});
        }
        return ans;       
    }
};