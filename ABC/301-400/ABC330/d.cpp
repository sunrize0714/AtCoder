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
    vs s(n);
    rep(i,0,n)cin >> s[i];

    vvll tate(n,vll(n,0));
    rep(i,0,n)if(s[0][i]=='o')tate[0][i] = 1;
    rep(i,1,n){
        rep(j,0,n){
            if(s[i][j] == 'o')tate[i][j] = tate[i-1][j]+1;
            else tate[i][j] = tate[i-1][j];
        }
    }
    ll ans = 0;
    vll push(n,0);
    rep(i,0,n){
        ll pos = 0;
        rep(j,0,n){
            if(s[i][j] == 'o')pos++;
        }
        rep(j,0,n){
            if(s[i][j] == 'o')push[j] += pos-1;
        }
    }

    rep(i,0,n){
        ans += push[i]*(tate[n-1][i]-1);
    }
    cout << ans << endl;
}