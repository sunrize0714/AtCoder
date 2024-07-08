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
    ll n,x,y;
    cin >> n >> x >> y;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vll hor,var;
    rep(i,1,n){
        if(i%2 == 1)var.push_back(a[i]);
        else hor.push_back(a[i]);
    }
    x -= a[0];
    bool f = true;
    ll wa = 0;
    rep(i,0,var.size()){
        wa += var[i];
    }
    vector<vb> dp(var.size()+1,vb(20001,false));
    dp[0][10000] = true;
    rep(i,0,var.size()){
        rep(j,0,20001){
            if(j >= var[i]){
                if(dp[i][j-var[i]])dp[i+1][j] = true;
            }
            if(j <= 20000 - var[i]){
                if(dp[i][j+var[i]])dp[i+1][j] = true;
            } 
        }
    }
    if(!dp[var.size()][10000+y])f = false;


    wa = 0;
    rep(i,0,hor.size()){
        wa += hor[i];
    }
    vector<vb> dp2(hor.size()+1,vb(20001,false));
    dp2[0][10000] = true;
    rep(i,0,hor.size()){
        rep(j,0,20001){
            if(j >= hor[i]){
                if(dp2[i][j-hor[i]])dp2[i+1][j] = true;
            }
            if(j <= 20000 - hor[i]){
                if(dp2[i][j+hor[i]])dp2[i+1][j] = true;
            } 
        }
    }
    if(!dp2[hor.size()][10000+x])f = false;
    if(f)cout << "Yes" << endl;
    else cout << "No" << endl;
}