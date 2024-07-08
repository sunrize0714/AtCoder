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

ll n,m;
ll a[200],b[200],c[200];
vll ans(n);
ll idx[20];
bool exist = false;
void dfs(ll query,vll& ans){
    if(query == m){
        exist = true;
        return;
    }
    else{
        ll x = -1,y = -1;
        rep(i,0,n){
            if(ans[i] == a[query])x = i;
            if(ans[i] == b[query])y = i;
        }
        if(x != -1 && y != -1){
            if(y-x == c[query]){
                dfs(query+1,ans);
            }
        }
        else if(x != -1){
            ll to = y+c[query];
            if(to < n){
                if(ans[to] == -1){
                ans[to] = a[query];
                dfs(query+1,ans);
                ans[to] = -1;
                }
            }
        }
        else if(y != -1){
            ll to = x - c[query];
            if(to >= 0){
                if(ans[to] == -1){
                    ans[to] = b[query];
                    dfs(query+1,ans);
                    ans[to] = -1;
                }
            }
        }
        else{
            rep(i,0,n-c[query]){
                ll pos = i+c[query];
                if(ans[i] == -1 && ans[pos] == -1){
                    ans[i] = a[query];
                    ans[pos] = b[query];
                    dfs(query+1,ans);
                    ans[i] = ans[pos] = -1;
                }
            }
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    rep(i,0,m)cin >> a[i] >> b[i] >> c[i];
    rep(i,0,m){
        a[i]--,b[i]--;
    }
    rep(i,0,n)idx[i] = 1e18;
    rep(i,0,n){
        rep(j,0,n){
            rep(l,0,n)ans[i] = -1;
            exist = false;
            ans[j] = i;
            dfs(0,ans);
            if(exist && idx[i] == 1e18)idx[i] = j+1;
            else if(exist){
                idx[i] = -1;
                break;
            }
        }
        if(idx[i] = 1e18)idx[i] = -1;
    }
    rep(i,0,n)cout << idx[i] << " ";
}