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
    ll h,w,n;
    cin >> h >> w >> n;
    ll x = 0,y = 0;
    string o = "";
    rep(i,0,w)o += '.';
    vs ans(h,o);
    ll pos = 1;

    rep(i,0,n){
        if(ans[x][y] == '.'){
            ans[x][y] = '#';
            pos += 3;
            pos %= 4;
            x = x + dy4[pos] + h;
            x %= h;
            y = y + dx4[pos] + w;
            y %= w;
        }
        else{
            ans[x][y] = '.';
            pos += 1;
            pos %= 4;
            x = x + dy4[pos] + h;
            x %= h;
            y = y + dx4[pos] + w;
            y %= w;
        }
    }
    rep(i,0,h)cout << ans[i] << endl;
}