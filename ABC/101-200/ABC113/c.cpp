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
    vll p(m),y(m);
    vvll g(n+1);
    rep(i,0,m){
        cin >> p[i] >> y[i];
        g[p[i]].push_back(y[i]);
    }
    rep(i,1,n+1){
        sort(all(g[i]));
    }
    rep(i,0,m){
        string a = "000000" + to_string(p[i]);
        ll itr = lower_bound(all(g[p[i]]),y[i]) - g[p[i]].begin();
        string b = "000000" + to_string(itr+1);
        cout << a.substr(a.size()-6,6) + b.substr(b.size()-6,6) << endl;
    }
}