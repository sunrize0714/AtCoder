#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        graph[p].push_back(i); 
    }
    /*vector<int> dist(n+1,-1);
    dist[1] = 0;
    queue<int> q1;
    q1.push(1);
    while(!q1.empty()){
        int pos = q1.front();
        q1.pop();
        for(int i=0;i<graph[pos].size();i++){
            int to = graph[pos][i];
            if(dist[to]== -1){
                dist[to] = dist[pos] +1;
                q1.push(to);
            }
        }
    }*/


    vector<int> ins(n+1,0);
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        ins[x] = max(ins[x],y+1);
    }

    set<int> ans;
    for(int i=1;i<=n;i++){
        if(ins[i] != 0){
            ans.insert(i);
            for(int j=0;j<graph[i].size();j++){
                int to = graph[i][j];
                ins[to] = max(ins[to],ins[i]-1);
            }
        }
    }
    cout << ans.size();
}