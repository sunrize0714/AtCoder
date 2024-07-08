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
    ll h,w;
    cin >> h >> w;
    vs c(h);
    rep(i,0,h)cin >> c[i];
    vector<vb> g(h,vb(w,false));
    g[0][0] = true;
    ll ans = 0;
    rep(i,1,h+w){
        rep(j,0,i+1){
            if(j >= h || i-j >= w)continue;
            if(c[j][i-j] == '#')continue;
            if(j!=0){
                if(g[j-1][i-j]){
                    g[j][i-j] = true;
                    ans = max(ans,i);
                }
            }
            if(i-j != 0){
                if(g[j][i-j-1]){
                    g[j][i-j] = true;
                    ans = max(ans,i);
                }
            }
        }
    }
    cout << ans+1 << endl;
}