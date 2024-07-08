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
    vs a(n);
    rep(i,0,n)cin >> a[i];
    vs b(3*n);
    rep(i,0,3*n){
        ll pos = i % n;
        b[i] = a[pos] + a[pos] + a[pos];
    }
    vs ans;
    rep(i,n,2*n){
        rep(j,n,2*n){
            rep(k,0,8){
                string t;
                ll x = j,y = i;
                rep(l,0,n){
                    t += b[y+dy8[k]*l][x+dx8[k]*l];
                }
                ans.push_back(t);
            }
        }
    }
    sort(ans.begin(),ans.end(),greater<string>());
    cout << ans[0] << endl;
}