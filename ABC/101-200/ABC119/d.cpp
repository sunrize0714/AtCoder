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
    ll a,b,q;
    cin >> a >> b >> q;
    vll s(a),t(b),x(q);
    rep(i,0,a)cin >> s[i];
    rep(i,0,b)cin >> t[i];
    rep(i,0,q)cin >> x[i];
    s.push_back(-1e18);
    s.push_back(1e18);
    t.push_back(-1e18);
    t.push_back(1e18);
    sort(all(s));
    sort(all(t));
    rep(i,0,q){
        auto itr1 = lower_bound(all(s),x[i]) - s.begin();
        auto itr2 = lower_bound(all(t),x[i]) - t.begin();
        ll ans = 1e19;
        ans = min(ans,max(s[itr1],t[itr2])-x[i]);
        ans = min(ans,x[i]-min(s[itr1-1],t[itr2-1]));
        ans = min(ans,abs(s[itr1]*2 - t[itr2-1]*2)-max(s[itr1]-x[i],x[i]-t[itr2-1]));
        ans = min(ans,abs(t[itr2]*2 - s[itr1-1]*2)-max(t[itr2]-x[i],x[i]-s[itr1-1]));
        cout << ans << endl;
    }  
}