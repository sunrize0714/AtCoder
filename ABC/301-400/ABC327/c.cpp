#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
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

int main(){
    vvll a(9,vll(9));
    rep(i,0,9)rep(j,0,9)cin >> a[i][j];

    bool ans = true;
    rep(i,0,9){
        set<ll> t;
        rep(j,0,9){
            t.insert(a[i][j]);
        }
        if(t.size()!=9)ans = false;
        set<ll> u;
        rep(j,0,9){
            u.insert(a[j][i]);
        }
        if(u.size()!=9)ans = false;
    }

    pair<ll,ll> to[9]={make_pair(1,1),make_pair(1,4),make_pair(1,7),make_pair(4,1),make_pair(4,4),make_pair(4,7),make_pair(7,1),make_pair(7,4),make_pair(7,7)};
    ll dy[9]={0,0,-1,-1,-1,0,1,1,1};
    ll dx[9]={0,1,1,0,-1,-1,-1,0,1};
    rep(i,0,9){
        set<ll> t;
        rep(j,0,9){
            t.insert(a[to[i].first+dx[j]][to[i].second+dy[j]]);
        }
        if(t.size()!=9)ans = false;
    }
    if(ans)cout << "Yes";
    else cout << "No";
}