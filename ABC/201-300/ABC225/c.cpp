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

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll n;
    cin >> n;
    vll t(n+1),k(n+1);
    vvll a(n+1);
    vvll g(n+1);
    rep(i,1,n+1){
        cin >> t[i] >> k[i];
        rep(j,0,k[i]){
            ll to;
            cin >> to;
            a[i].push_back(to);
            g[i].push_back(to);
        }
    }

    ll ans = 0;
    queue<ll> q;
    vb fin(n+1,false);
    fin[n] = true;
    q.push(n);
    while(!q.empty()){
        ll pos = q.front();q.pop();
        ans += t[pos];
        rep(i,0,g[pos].size()){
            ll to = g[pos][i];
            if(!fin[to]){
                fin[to] = true;
                q.push(to);
            }
        }
    }

    cout << ans << endl;
}