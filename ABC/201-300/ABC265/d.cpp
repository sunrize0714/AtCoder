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
    ll n,p,q,r;
    cin >> n >> p >> q >> r;
    vll a(n);
    vll suma(n+1);
    suma[0] = 0;
    rep(i,0,n){
        cin >> a[i];
        suma[i+1] = suma[i] + a[i];
    }
    ll x = 0;
    while(suma[x]+p+q+r <= suma[n]){
        auto itr = lower_bound(suma.begin(),suma.end(),suma[x]+p) - suma.begin();
        auto itr2 = lower_bound(suma.begin(),suma.end(),suma[x]+p+q) - suma.begin();
        auto itr3 = lower_bound(suma.begin(),suma.end(),suma[x]+p+q+r) - suma.begin();
        if(suma[itr] == suma[x]+p && suma[itr2] == suma[x]+p+q && suma[itr3] == suma[x]+p+q+r){
            cout << "Yes" << endl;
            return 0;
        }
        x++;
    }
    cout << "No" << endl;
}