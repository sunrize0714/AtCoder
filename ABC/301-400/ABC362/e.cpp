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

bool in_field(ll l,ll r,ll x){
    if(l <= x && x < r)return true;
    else return false;
}

ll distance(ll ax,ll ay,ll bx, ll by){
    return (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
}

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
    ll n;
    cin >> n;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    else if(n == 2){
        cout << "2 1" << endl;
        return 0;
    }
    else if(n == 3){
        cout << 3 << " " << 3 << " ";
        if(a[2]-a[1] == a[1]-a[0])cout << 1;
        else cout << 0;
        return 0;
    }
    vll sa;
    rep(i,0,n){
        rep(j,i+1,n){
            sa.push_back(a[j]-a[i]);
        }
    }
    sort(all(sa));
    sa.erase(unique(all(sa)),sa.end());
    // i番目まで,差がj,長さk
    vvvll dp(n,vvll(sa.size(),vll(n+1,0)));
    rep(i,0,n)rep(j,0,sa.size())dp[i][j][1] = 1;
    rep(i,1,n){
        rep(j,0,sa.size()){
            rep(k,2,n+1){
                //dp[i][j][k] += dp[i-1][j][k];
                rep(ii,0,i){
                    if(a[ii] + sa[j] == a[i]){
                        dp[i][j][k] += dp[ii][j][k-1];
                        dp[i][j][k] %= mod;
                    }
                }
            }
        }
    }
    vll ans(n,0);
    rep(i,0,n){
        rep(j,0,sa.size()){
            rep(k,1,n+1){
                ans[k] += dp[i][j][k];
                ans[k] %= mod;
            }
        }
    }
    cout << n << " ";
    rep(i,2,n)cout << ans[i] << " ";
    ll to = a[1]-a[0];
    
    rep(i,2,n){
        if(a[i]-a[i-1] != to){
            cout << 0;
            return 0;
        }
        if(i == n-1)cout << 1;
    }
    
}
