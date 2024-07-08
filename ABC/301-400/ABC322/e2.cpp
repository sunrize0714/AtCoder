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
    ll n,k,p;
    cin >> n >> k >> p;
    vll c(n);
    vvll a(n,vll(k));
    ll s = 0;
    rep(i,0,n){
        cin >> c[i];
        s += c[i];
        rep(j,0,k){
            cin >> a[i][j];
        }
    }

    rep(i,0,k){
        ll capa = 0;
        rep(j,0,n){
            capa += a[j][i];
        }
        if(capa < p){
            cout << "-1" << endl;
            return 0;
        }
    }
    
    vvll dp(n+1,vll(60000,100000000000));
    dp[0][0] = 0;

    rep(i,0,n){
        ll index=1,power=0;
        rep(j,0,k){
            power += index*a[i][j];
            index *= 10;
        }
        rep(j,0,power){
            dp[i+1][j] = dp[i][j];
        }
        rep(j,power,60000){
            ll now = j;
            ll moto = 0;
            bool flag = true;
        while(power > 0){
            if(now % 10 > 6){
                flag = false;
                break;
            }
            if(now % 10 + power % 10 >= 5 && ){
                moto += 5*index;
            }
            else if(now % 10 - power % 10 > 0){
                moto += (min(5LL,now % 10 - power % 10))*index;
            }
            else{
                moto += 5*index;
            }
            now /= 10;
            index *= 10;
            power /= 10;
        }
        if(flag)dp[i+1][j] = min(dp[i][j],dp[i][moto]+c[i]);
        }

    
    }

    ll ans = 1000000000000;
    rep(i,0,60000){
        ll ju = i;
        bool flag = false;
        while(ju > 0){
            if(ju % 10 < p){
                flag = false;
                break;
            }
        }
        if(flag)ans = min(ans,dp[n][i]);
    }
    cout << ans ;
}