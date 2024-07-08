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

ll n;
ll a[20][20];
bool used[20];
ll ans = 0;
void dfs(ll x){
    ll pos = 0;
    while(pos < 2*n && used[pos])pos++;
    if(pos == 2*n){
        ans = max(ans,x);
        return;
    }
    rep(i,pos+1,2*n){
        if(!used[i]){
            used[i] = true;
            used[pos] = true;
            dfs(x^a[pos][i]);
            used[i] = false;
            used[pos] = false;
        }
    }
}

int main(){
    cin >> n;
    rep(i,0,2*n){
        rep(j,i+1,2*n){
            cin >> a[i][j];
        }
    }
    rep(i,0,2*n)used[i] = false;
    dfs(0);
    cout << ans << endl;
}
