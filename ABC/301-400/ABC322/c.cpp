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
    ll n,m;
    cin >> n >> m;
    vll a(m);
    rep(i,0,m)cin >> a[i];
    ll ans = a[0]-1,count = 0;
    while(n--){
        cout << ans << endl;
        if(ans > 0){
            ans--;
        }
        else{
            ans = a[count+1] -a[count] -1;
            count++;
        }
    }

    
}