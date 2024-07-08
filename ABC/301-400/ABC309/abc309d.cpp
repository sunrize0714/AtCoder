#include<bits/stdc++.h>
using namespace std;
int dist[2500000]; 


int main(){
    int n1,n2,m;cin >> n1 >> n2 >> m;
    vector<vector<int>> graph(n1+n2+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n1+n2;i++)dist[i]=-1;
    queue<int> q1,q2;
    q1.push(1);
    dist[1] = 0;
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
    }
    
    q2.push(n1+n2);
    dist[n1+n2] = 0;
    while(!q2.empty()){
        int pos = q2.front();
        q2.pop();
        for(int i=0;i<graph[pos].size();i++){
            int to = graph[pos][i];
            if(dist[to]== -1){
                dist[to] = dist[pos] +1;
                q2.push(to);
            }
        }
    }

    int ans1 =0,ans2=0;
    for(int i=1;i<=n1;i++)ans1 = max(ans1,dist[i]);
    for(int i=n1+1;i<=n1+n2;i++)ans2 = max(ans2,dist[i]);

    
    cout << ans1+ans2+1 << endl;
}