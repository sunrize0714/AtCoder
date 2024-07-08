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

ll n,x;
vvll a;
ll ans = 0;
void dfs(ll q,ll val){
    if(q == n){
        if(val == x)ans++;
        return;
    }
    else{
        rep(i,0,a[q].size()){
            if(val > x/a[q][i])continue;
            dfs(q+1,val*a[q][i]);
        }
    }
}

int main(){
    cin >> n >> x;
    vll l(n);
    a.resize(n);
    rep(i,0,n){
        cin >> l[i];
        rep(j,0,l[i]){
            ll p;
            cin >> p;
            a[i].push_back(p);
        }
    }
    dfs(0,1);
    cout << ans << endl;
}