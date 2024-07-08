#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

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
    vll a(n+1);
    rep(i,1,n+1)cin >> a[i];
    vll in(n+1,0);
    vll g(n+1,0);
    rep(i,1,n+1){
        if(a[i] != -1){
            g[i] = a[i];
            in[a[i]]++;
        }
    }
    vll ans;
    ll pos = -1;
    rep(i,1,n+1){
        if(in[i] == 0){
            pos = i;
        }
    }
    while(pos != -1){
        ans.push_back(pos);
        if(pos != -1)pos = a[pos];
    }
    reverse(all(ans));
    rep(i,0,n)cout << ans[i] << " ";
}