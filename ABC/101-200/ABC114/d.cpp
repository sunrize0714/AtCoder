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

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll n;
    cin >> n;
    if(n < 10){
        cout << 0 << endl;
        return 0;
    }
    map<ll,ll> m;
    rep(i,2,n+1){
        ll pos = i;
        rep(j,2,sqrt(i)+1){
            if(pos%j == 0){
                while(pos%j == 0){
                    m[j]++;
                    pos /= j;
                }
            }
        }
        if(pos > 1)m[pos]++;
    }
    ll ans = 0;
    rep(i,1,n+1)if(m[i] >= 74)ans++;
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(i != j && m[i] >= 24 && m[j] >= 2)ans++;
        }
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(i != j && m[i] >= 14 && m[j] >= 4)ans++;
        }
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            rep(k,j+1,n+1){
                if(i != j && i != k && m[i] >= 2 && m[j] >= 4 && m[k] >= 4)ans++;
            }
        }
    }
    cout << ans << endl;
}