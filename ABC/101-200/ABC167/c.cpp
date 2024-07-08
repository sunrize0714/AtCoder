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
    ll n,m,x;
    cin >> n >> m >> x;
    vll c(n);
    vvll a(n,vll(m));
    vll total(m,0);
    rep(i,0,n){
        cin >> c[i];
        rep(j,0,m){
            cin >> a[i][j];
            total[j] += a[i][j];
        } 
    }

    rep(i,0,m){
        if(total[i] < x){
            cout << -1 << endl;
            return 0;
        }
    }

    ll ans = 1e10;
    rep(i,0,(1<<n)){
        vll skill(m,0);
        ll cnt = 0;
        rep(j,0,n){
            if(i & (1 << j)){
                rep(k,0,m){
                    skill[k] += a[j][k];
                }
                cnt += c[j];
            }
        }
        rep(j,0,m){
            if(skill[j] < x)break;
            if(j == m-1){
                ans = min(ans,cnt);
            }
        }
    }
    cout << ans << endl;
}