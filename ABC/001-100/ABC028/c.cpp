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
    vll a(5);
    rep(i,0,5)cin >> a[i];
    vll sums;
    rep(i,0,4){
        rep(j,i+1,5){
            ll wa = 0;
            rep(k,0,5){
                if(k == j || i == k)continue;
                wa += a[k];
            }
            sums.push_back(wa);
        }
    }
    sort(sums.begin(),sums.end());
    cout << sums[7] << endl;
}