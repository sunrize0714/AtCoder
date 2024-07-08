#include<bits/stdc++.h>
using namespace std;
string s[10];
vector<int> g[10];
bool visited[10];

void dfs(int pos){
    visited[pos]=true;
    for(int i=0;i<g[pos].size();i++){
        int nex = g[pos][i];
        if(visited[nex]==false)dfs(nex);
    }
    return;
}
int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> s[i];
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int almost=0;
            for(int k=0;k<m;k++){
                if(s[i][k] == s[j][k])almost++;
            }
            if(almost == m-1){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            visited[j]=false;
        }
        dfs(i);
        for(int j=0;j<n;j++){
            if(visited[j]==false)flag=1;
        }
        if(flag == 0){
        cout << "Yes";
        return 0;
        }
    }

    cout << "No";
}