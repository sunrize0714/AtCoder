#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while(b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if(u < 0) u += m;
    return u;
}

int main(){
    ll n,m;
    cin >> n >> m;
    vll x(m),y(m);
    rep(i,0,m)cin >> x[i] >> y[i];
    vvll g(n+1);
    vll in(n+1,0);
    rep(i,0,m){
        g[x[i]].push_back(y[i]);
        in[y[i]]++;
    }
    queue<ll> q;
    rep(i,1,n+1){
        if(in[i] == 0)q.push(i);
    }
    if(q.size() != 1){
        cout << "No" << endl;
        return 0;
    }
    vll ans;
    while(!q.empty()){
        ll pos = q.front();q.pop();
        ans.push_back(pos);
        rep(i,0,g[pos].size()){
            ll to = g[pos][i];
            in[to]--;
            if(in[to] == 0)q.push(to);
        }
        if(q.size() != 1 && ans.size() != n){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    vll a(n+1);
    rep(i,0,ans.size()){
        ll pos = ans[i];
        a[pos] = i+1;
    }
    rep(i,1,n+1)cout << a[i] << " ";
    cout << endl;
}