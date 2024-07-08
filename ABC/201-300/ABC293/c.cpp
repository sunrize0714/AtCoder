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
    ll h,w;
    cin >> h >> w;
    vvll dp(h,vll(w));
    rep(i,0,h)rep(j,0,w)cin >> dp[i][j];
    vll array;
    rep(i,0,h-1){
        array.push_back(0);
    }
    rep(i,0,w-1){
        array.push_back(1);
    }
    ll ans = 0;
    do{
        ll x = 0,y = 0;
        set<ll> s;
        s.insert(dp[y][x]);
        rep(i,0,array.size()){
            if(array[i] == 0)y++;
            else x++;

            s.insert(dp[y][x]);
        }
        if(s.size() == h+w-1)ans++;
    }while(next_permutation(array.begin(),array.end()));
    cout << ans << endl;
}