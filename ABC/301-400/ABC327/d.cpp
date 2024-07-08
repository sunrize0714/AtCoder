#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

int main(){
    ll n,m;
    cin >> n >> m;
    vll a(m),b(m);
    set<pair<ll,ll>> s;
    rep(i,0,m)cin >> a[i];
    rep(i,0,m)cin >> b[i];
    vll dist(n,-1);
    vll ji(n,0);
    vvll g(n);
    rep(i,0,m){
        a[i]--,b[i]--;
        if(s.count(make_pair(a[i],b[i])) || s.count(make_pair(b[i],a[i])))continue;
        else s.insert(make_pair(a[i],b[i]));

        if(a[i]!=b[i]){
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
        ji[a[i]]++;
        ji[b[i]]++;
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    queue<ll> q;
    set<ll> aa;
    rep(i,0,n)aa.insert(i);
    while(aa.size() != 0){
        auto itr = aa.begin();
        ll first = *(itr);
        q.push(first);
        aa.erase(first);
        while(!q.empty()){
            ll pos = q.front();q.pop();
            rep(i,0,g[pos].size()){
                ll to = g[pos][i];
                if(dist[to] == -1){
                    dist[to] = 1 - dist[pos];
                    q.push(to);
                    aa.erase(to);
                }
                else if(dist[to] == dist[pos]){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
}