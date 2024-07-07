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
    ll n;
    cin >> n;
    ll pos = 1;
    ll dist = 0;
    ll ind = 0;
    rep(i,2,n+1){
        cout << "? " << 1 << " " << i << endl;
        ll to;
        cin >> to;
        if(to > dist){
            dist = to;
            ind = i;
        }
    }
    dist = 0;
    rep(i,1,n+1){
        if(i == ind)continue;
        cout << "? " << ind << " " << i << endl;
        ll to;
        cin >> to;
        if(to > dist){
            dist = to;
            pos = i;
        }
    }

    cout << "! " << dist << endl;
}