#include<bits/stdc++.h>
using namespace std;
vector<int> g[210000];
bool visit[210000];
vector<int> pass[210000];

void dfs(int pos){
    visit[pos]=true;
    for(int i=0;i<g[pos].size();i++){
        int nex = g[pos][i];
        if(visit[nex] == true)dfs(nex);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> u(m),v(m);
    for(int i=0;i<m;i++){
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            visit[j] = false;
        }
        dfs(i);
        for(int j=0;i<)
    }

}