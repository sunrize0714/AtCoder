#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

ll modinv(ll a, ll m) {
    ll b=m,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b;swap(a,b);
        u-=t*v;swap(u,v);
    }
    u%=m; 
    if(u<0)u+=m;
    return u;
}

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll n,k,p;
    cin >> n >> k >> p;
    vll c(n);
    vvll a(n,vll(k));
    rep(i,0,n){
        cin >> c[i];
        rep(j,0,k){
            cin >> a[i][j];
        }
    }
    vvll dp(n+1,vll(100000,1e15));
    dp[0][0] = 0;
    rep(i,0,n){
        rep(j,0,100000){
            dp[i+1][j] = min(dp[i][j],dp[i+1][j]);
            vll x(k);
            ll pos = j;
            bool f = true;
            rep(l,0,k){
                x[l] = pos%10;
                if(x[l] >= p+1){
                    f = false;
                    break;
                }
                pos /= 10;
            }
            if(f){
                ll pos2 = 0;
                ll cnt = 1;
                rep(l,0,k){
                    x[l] = min(x[l]+a[i][l],p);
                    pos2 += x[l]*cnt;
                    cnt *= 10;
                }
                dp[i+1][pos2] = min(dp[i][j]+c[i],dp[i+1][pos2]);
            }
        }
    }
    ll ans = 1e15;
    ll key = p;
    if(k > 1){
        rep(i,0,k-1){
            key *= 10;
            key += p;
        }
    }
    rep(i,0,n){
        ans = min(ans,dp[i+1][key]);
    }
    if(ans == 1e15)ans = -1;
    cout << ans << endl;
}