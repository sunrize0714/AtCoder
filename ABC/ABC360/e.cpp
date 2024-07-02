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
#define rrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

ll modinv(ll a, ll m) {
    ll b=m,u=1LL,v=0LL;
    while(b){
        ll t=a/b;
        a-=t*b;swap(a,b);
        u-=t*v;swap(u,v);
    }
    u%=m; 
    if(u<0)u+=m;
    return u;
}

int main(){
    ll n,k;
    cin >> n >> k;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    if(n == 2){
        cout << 499122178;
        return 0;
    }
    ll modn = n*(n-2);
    modn %= mod;
    modn += 2;
    modn %= mod;
    ll nn = n*n;
    nn %= mod;
    ll one_to_one = modn;
    one_to_one *= modinv(nn,mod);
    one_to_one %= mod;
    ll one_to_all = 2*(n-1);
    one_to_all %= mod;
    one_to_all *= modinv(nn,mod);
    one_to_all %= mod;
    ll all_to_one = 2;
    all_to_one *= modinv(nn,mod);
    all_to_one %= mod;
    ll all_to_all = n*n-2;
    if(all_to_all < 0)all_to_all += mod;
    all_to_all %= mod;
    all_to_all *= modinv(nn,mod);
    all_to_all %= mod;
    vvll dp(2,vll(k+1,0));
    dp[0][0] = 1;
    rep(i,0,k){
        dp[0][i+1] = (dp[0][i]%mod*one_to_one)%mod + (dp[1][i]%mod*all_to_one)%mod;
        dp[1][i+1] = (dp[0][i]%mod*one_to_all)%mod + (dp[1][i]%mod*all_to_all)%mod;
        dp[0][i+1] %= mod;
        dp[1][i+1] %= mod;
    }
    ll ans = dp[0][k];
    ll pos = dp[1][k];
    pos *= modinv(n-1,mod);
    pos %= mod;
    ll x = (n+1)*n/2-1;
    x %= mod;
    pos *= x;
    pos %= mod;
    ans += pos;
    cout << ans%mod << endl;
}