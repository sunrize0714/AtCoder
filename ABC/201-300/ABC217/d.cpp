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
    ll l,q;
    cin >> l >> q;
    vll c(q),x(q);
    set<ll> cut;
    cut.insert(l);
    cut.insert(0);
    rep(i,0,q){
        cin >> c[i] >> x[i];
        if(c[i] == 1)cut.insert(x[i]);
        if(c[i] == 2){
            auto itr = cut.lower_bound(x[i]);
            ll r = *(itr);
            itr--;
            ll left = *(itr);
            cout << r-left << endl;
        }
    }
}