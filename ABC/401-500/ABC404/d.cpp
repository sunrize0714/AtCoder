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
    ll n,m;
    cin >> n >> m;
    vll c(n);
    rep(i,0,n)cin >> c[i];
    vll k(m);
    vvll a(n);
    //vvll a(m);
    rep(i,0,m){
        cin >> k[i];
        rep(j,0,k[i]){
            ll x;
            cin >> x;
            x--;
            a[x].push_back(i);
        }
    }

    /*rep(i,0,n){
        rep(j,0,a[i].size())cout << a[i][j] << " ";
        cout << endl;
    }*/

    ll ans = 1e18;
    rep(idx,0,1LL<<(2*n)){
        vll cnt(m,0);
        ll cost = 0;
        bool ok = true;
        rep(i,0,n){
            if(!(idx & (1LL<<i))&&(idx & (1LL<<(i+n))))ok = false;
        }
        if(!ok)continue;
        rep(i,0,n){
            ll visit = 0;
            if(idx & (1LL<<(i+n)))visit = 2;
            else if(idx & (1LL<<i))visit = 1;
            rep(j,0,visit){
                cost += c[i];
                rep(kk,0,a[i].size()){
                    cnt[a[i][kk]]++;
                }
            }
        }
        ok = true;
        rep(i,0,m)if(cnt[i] <= 1)ok = false;
        if(ok)ans = min(ans,cost);
    }

    cout << ans;
    /*vll dp(1LL<<(2*n),1e12);
    dp[0] = 0;
    rep(idx,0,1LL<<(2*n)){
        bool ok = true;
        rep(i,0,n){
            if((idx & (1LL<<i) == 0)&&(idx & (1LL<<(i+n)) == 1))ok = false;
        }
        if(!ok)continue;
        rep(i,0,n){
            ll cnt = idx;
            rep(j,0,a[i].size()){
                ll pos = a[i][j];
                if(cnt & (1LL<<pos) == 0)cnt += 1LL<<pos;
                else if(cnt & (1LL<<(pos+n)) == 0)cnt += 1LL<<(pos+n);
            }
            dp[cnt] = min(dp[cnt],dp[idx]+c[i]);
        }
    }
    cout << dp[1LL<<(2*n)-1];*/
}
