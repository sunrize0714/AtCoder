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
    while(b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if(u < 0) u += m;
    return u;
}

int main(){
    ll n,k;
    cin >> n >> k;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vvll s(k);
    rep(i,0,n){
        s[i%k].push_back(a[i]);
    }
    rep(i,0,k)sort(all(s[i]));
    sort(all(a));
    rep(i,0,n){
        if(a[i] != s[i%k][i/k]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}