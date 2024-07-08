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
    ll t,n;
    cin >> t >> n;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    ll m;
    cin >> m;
    vll b(m);
    rep(i,0,m)cin >> b[i];
    ll tako = 0;
    rep(i,0,m){
        while(tako < n){
            if(a[tako]+t < b[i] || a[tako] > b[i])tako++;
            else{
                tako++;
                b[i] = -1;
                break;
            }
        }
        if(tako == n && b[m-1] != -1){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}