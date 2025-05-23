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
    ll h,w;
    cin >> h >> w;
    vs c(h);
    rep(i,0,h)cin >> c[i];
    ll n = min(h,w);
    map<ll,ll> ans;
    rep(i,1,h-1){
        rep(j,1,w-1){
            if(c[i][j] == '#' && c[i+1][j-1] == '#' && c[i-1][j-1] == '#' && c[i-1][j+1] == '#' && c[i+1][j+1] == '#'){
                ll cnt = 1;
                while(true){
                    if(c[i+cnt][j-cnt] == '#' && c[i-cnt][j-cnt] == '#' && c[i-cnt][j+cnt] == '#' && c[i+cnt][j+cnt] == '#'){
                        if(i+cnt == h-1 || i-cnt == 0 || j+cnt == w-1 || j-cnt == 0){
                            break;
                        }
                        else cnt++;
                    }
                    else{
                        cnt--;
                        break;
                    }
                }
                ans[cnt]++;
            }
        }
    }

    rep(i,1,n+1)cout << ans[i] << endl;
}