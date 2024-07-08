#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    vector<set<int>> foreigner(n+1);
    int ans = n;
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int u,v;
            cin >> u >> v;
            foreigner[u].insert(v);
            foreigner[v].insert(u);
            if(foreigner[u].size() == 1)ans--;
            if(foreigner[v].size() == 1)ans--;
            cout << ans << endl;
        }
        if(t == 2){
            int v;
            cin >> v;
            auto itr = foreigner[v].begin();
            while(itr != foreigner[v].end()){
                foreigner[(*itr)].erase(v);
                if(foreigner[(*itr)].size() == 0)ans++;
                itr++;
            }
            if(foreigner[v].size() != 0)ans++;
            foreigner[v].clear();
            cout << ans << endl;
        }
    }
}