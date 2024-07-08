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
    ll n,q;
    cin >> n >> q;
    vll t(q),a(q),b(q);
    rep(i,0,q)cin >> t[i] >> a[i] >> b[i];
    map<ll,map<ll,ll>> ff;
    rep(i,0,q){
        a[i]--,b[i]--;
        if(t[i] == 1){
            ff[a[i]][b[i]] = 1;
        }
        if(t[i] == 2){
            ff[a[i]][b[i]] = 0;
        }
        if(t[i] == 3){
            if(ff[a[i]][b[i]] & ff[b[i]][a[i]])cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}