#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    cin >> q;
    vector<int> dist(n+1,-1);
    rep(i,0,q){
        int x,k;
        cin >> x >> k;
        rep(j,0,n+1)dist[j] = -1;
        dist[x] = 0;
        queue<int> que;
        que.push(x);
        int ans = 0;
        while(!que.empty()){
            int pos = que.front();que.pop();
            ans += pos;
            if(dist[pos] == k)continue;
            rep(j,0,g[pos].size()){
                int to = g[pos][j];
                if(dist[to] != -1)continue;
                dist[to] = dist[pos]+1;
                if(dist[pos]<k)que.push(to);
            }
        }
        rep(j,0,n+1)dist[j] = -1;
        cout << ans << endl;
    }
}
