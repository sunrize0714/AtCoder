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
    ll n,q;
    cin >> n >> q;
    vll l(q),r(q);
    vll rev(n+2,0);
    rep(i,0,q){
        cin >> l[i] >> r[i];
        rev[l[i]]++;
        rev[r[i]+1]--;
    }

    rep(i,2,n+2){
        rev[i] += rev[i-1];
        rev[i-1]%2 == 0 ? cout << '0' : cout << '1';
    }
    cout << endl;    
}