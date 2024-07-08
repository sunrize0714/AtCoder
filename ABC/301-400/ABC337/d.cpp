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
    ll h,w,k;
    cin >> h >> w >> k;
    vs s(h);
    rep(i,0,h)cin >> s[i];
    ll ans = 1e10;
    if(w >= k){
    rep(i,0,h){
        ll x = 0;
        ll o = 0;
        ll dot = 0;
        rep(j,0,k){
            if(s[i][j] == '.')dot++;
            else if(s[i][j] == 'o')o++;
            else x++;
        }
        if(x == 0 && dot < ans)ans = min(ans,dot);
        rep(j,k,w){
            if(s[i][j] == '.')dot++;
            else if(s[i][j] == 'o')o++;
            else x++;

            if(s[i][j-k] == '.')dot--;
            else if(s[i][j-k] == 'o')o--;
            else x--;
            if(dot < ans && x == 0){
                ans = dot;
            }
        }
    }
    }
    if(h >= k){
    rep(j,0,w){
        ll x = 0;
        ll o = 0;
        ll dot = 0;
        rep(i,0,k){
            if(s[i][j] == '.')dot++;
            else if(s[i][j] == 'o')o++;
            else x++;
        }
        if(x == 0)ans = min(ans,dot);
        rep(i,k,h){
            if(s[i][j] == '.')dot++;
            else if(s[i][j] == 'o')o++;
            else x++;

            if(s[i-k][j] == '.')dot--;
            else if(s[i-k][j] == 'o')o--;
            else x--;
            if(dot < ans && x == 0){
                ans = dot;
            }
        }
    }
    }
    if(ans == 1e10)ans = -1;
    cout << ans << endl;
}