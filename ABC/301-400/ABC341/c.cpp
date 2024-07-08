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
    string t;
    cin >> t;
    vs s(h);
    rep(i,0,h)cin >> s[i];
    ll ans = 0;
    rep(i,0,h){
        rep(j,0,w){
            ll x = j,y = i;
            if(s[y][x] == '#')continue;
            rep(k,0,n){
                if(t[k] == 'L')x--;
                else if(t[k] == 'R')x++;
                else if(t[k] == 'U')y--;
                else y++;
                if(x < 0 || x >= w || y < 0 || y >= h)break;
                if(s[y][x] == '#')break;
                if(k == n-1)ans++;
            }
        }
    }
    cout << ans << endl;
}