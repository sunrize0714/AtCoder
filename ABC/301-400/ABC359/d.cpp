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
    ll n,k;
    string s;
    cin >> n >> k >> s;
    //あり得る長さkの文字列を列挙
    vector<string> st(1LL<<k);
    vll ok(1LL<<k,0);
    rep(i,0,1LL<<k){
        string x;
        rep(j,0,k){
            if(i & 1LL<<j)x += 'A';
            else x += 'B';
        }
        st[i] = x;
    }
    rep(i,0,1LL<<k){
        ll p = 0;
        rep(j,0,k/2){
            if(st[i][j] != st[i][k-1-j])p = 1;
        }
        ok[i] = p;
    }
    //dp[i][j] i文字目まで決まった時、末尾k文字がjに対応する文字列になっている、条件を満たす文字列の数
    // AABA = 1101(2) = 13 - 8 = 5
    // BABA = 0101 = 5
    //  ABA = 101(2) = 5
    // ABAA = 1011 = 11
    // ABAB = 1010 = 10
    // A ABAB 
    
    vvll dp(n+1,vll(1LL<<k,0));
    rep(i,0,1LL<<k){
        ll p = 1;
        rep(j,0,k){
            if(st[i][j] != s[j] && s[j] != '?')p = 0;
        }
        dp[k][i] = p;
        dp[k][i] *= ok[i];
    }
    rep(i,k,n){
        rep(j,0,1LL<<k){
            ll to = j/2;
            if(s[i] == 'A' || s[i] == '?'){
                to += 1LL<<(k-1);
                dp[i+1][to] += dp[i][j] *ok[to];
                dp[i+1][to] %= mod;
                to -= 1LL<<(k-1);
            }
            if(s[i] == 'B' || s[i] == '?'){
                dp[i+1][to] += dp[i][j]*ok[to];
                dp[i+1][to] %= mod;
            }
        }
    }
    ll ans = 0;
    rep(i,0,1LL<<k){
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
}