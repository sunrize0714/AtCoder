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

int main(){
    ll n;
    cin >> n;
    vll s(n),t(n);
    rep(i,0,n)cin >> s[i];
    rep(i,0,n)cin >> t[i];
    vll ans(n);
    rep(i,0,n){
        ans[i] = t[i];
    }
    ll mini = 1e10,index = -1;
    rep(i,0,n){
        if(mini > ans[i]){
            mini = ans[i];
            index = i;
        }
    }
    rep(i,index,n-1){
        ans[i+1] = min(ans[i+1],ans[i]+s[i]);
    }
    ans[0] = min(ans[0],ans[n-1]+s[n-1]);
    rep(i,0,index){
        ans[i+1] = min(ans[i+1],ans[i]+s[i]);
    }
    rep(i,0,n)cout << ans[i] << endl;
}