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
    ll n;
    cin >> n;
    vvll ans(n,vll(n,-1));
    ans[n/2][n/2] = 0;
    ll x = n/2;
    ll y = n/2;
    ll cnt = 0;
    vll to;
    rep(i,1,n){
            to.push_back(i);
            to.push_back(i);
        if(i == n-1)to.push_back(i);
    }
    
    rep(i,0,to.size()){
        rep(j,0,to[i]){
            ll tox = x + dx4[i%4];
            ll toy = y + dy4[i%4];
            ans[tox][toy] = cnt+1;
            x = tox;
            y = toy;
            cnt++;
        }
    }

    rep(i,0,n){
        rep(j,0,n){
            if(ans[i][j] == 0)cout << "T ";
            else cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}