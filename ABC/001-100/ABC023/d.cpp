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
    vll h(n),s(n);
    rep(i,0,n)cin >> h[i] >> s[i];
    ll ok = 1e17,ng = 0LL;
    while(abs(ok-ng) > 1LL){
        ll mid = (ok+ng)/2;
        bool f = true;
        vll lim(n);
        rep(i,0,n){
            ll d = mid-h[i];
            if(d < 0){
                f = false;
                break;
            }
            d /= s[i];
            lim[i] = d+1;
        }
        sort(all(lim));
        rep(i,0,n){
            if(lim[i] < i+1){
                f = false;
                break;
            }
        }

        if(f)ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}