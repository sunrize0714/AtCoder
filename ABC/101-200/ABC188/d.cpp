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
    ll n,C;
    cin >> n >> C;
    vll a(n),b(n),c(n);
    rep(i,0,n)cin >> a[i] >> b[i] >> c[i];
    vp event;
    rep(i,0,n){
        event.push_back(make_pair(a[i]-1,c[i]));
        event.push_back(make_pair(b[i],-c[i]));
    }
    sort(all(event));
    ll ans = 0,pos = 0,t = 0;
    rep(i,0,event.size()){
        if(event[i].first != t){
            ans += min(C,pos)*(event[i].first-t);
            t = event[i].first;
        }
        pos += event[i].second;
    }
    cout << ans << endl;
}