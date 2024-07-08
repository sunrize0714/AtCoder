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

int main(){
    ll n;
    cin >> n;
    vll re(13);
    re[0] = 1;
    rep(i,1,13)re[i] = re[i-1]*10 + 1;
    ll cnt = 1;
    rep(i,0,13){
        rep(j,0,i+1){
            rep(k,0,j+1){
               if(cnt == n){
                   cout << re[i] + re[j] + re[k] << endl;
                   return 0;
               }
               cnt++;
            }
        }
    }
}