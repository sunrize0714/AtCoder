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
    ll n,q;
    cin >> n >> q;
    vll a(n+1,0);
    rep(i,1,n+1)cin >> a[i];
    vll wa(n+1,0);
    rep(i,1,n+1)wa[i] = a[i] - i;
    while(q--){
        ll k;
        cin >> k;
        auto itr = lower_bound(all(wa),k) - wa.begin();
        if(itr == n+1){
            cout << k + n+1 << endl;
        }
        else{
            itr--;
            cout << a[itr] + (k-wa[itr]) << endl;
        }
    }
}