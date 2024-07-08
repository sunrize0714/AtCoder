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
    ll n,m,x,y;
    cin >> n >> m >> x >> y;
    vll a(n),b(m);
    rep(i,0,n)cin >> a[i];
    rep(i,0,m)cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    rep(i,x+1,y+1){
        if(a[n-1] < i && i <= b[0]){
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
}