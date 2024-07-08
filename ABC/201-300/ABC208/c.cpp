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
    ll n,k;
    cin >> n >> k;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vll b(n);
    rep(i,0,n)b[i] = a[i];
    sort(b.begin(),b.end());
    rep(i,0,n){
        auto itr = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
        cout << k/n + (itr+1 <= k%n) << endl;
    }
}