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
    vll x(n),y(n),h(n);
    rep(i,0,n)cin >> x[i] >> y[i] >> h[i];
    ll lo = 0;
    rep(i,0,n)lo = max(lo,h[i]);
    rep(i,0,101){
        rep(j,0,101){
            rep(k,lo,lo+201){
                bool ok = true;
                rep(l,0,n){
                    ll dist = abs(i-x[l]) + abs(j-y[l]);
                    if(max(k-dist,0LL) != h[l]){
                        ok = !ok;
                        break;
                    }
                }
                if(ok){
                    cout << i << " " << j << " " << k;
                    return 0;
                }
            }
        }
    }
}