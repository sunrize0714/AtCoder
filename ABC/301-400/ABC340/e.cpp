#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
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

using s = ll;
using t = ll;
s op(s a,s b){
    return a+b;
}
s e(){
    return 0;
}
s mapping(t a,t b){
    return 0;
}
t composition(t a,t b){
    return 0;
}
t id(){
    return 0;
}

int main(){
    ll n,m;
    cin >> n >> m;
    vll a(n),b(m);
    rep(i,0,n)cin >> a[i];
    rep(i,0,m)cin >> b[i];
    vll ans(n);
    rep(i,0,n)ans[i] = a[i];
    lazy_segtree<s,op,e,t,mapping,composition,id> seg(ans);
    vll l(m),r(m),mov(m),baseAdd(m);
    rep(i,0,m){
        ll pos = seg.get(b[i]);
        seg.

        
    }
}