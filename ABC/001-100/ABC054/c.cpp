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
    ll n,m;
    cin >> n >> m;
    vll a(m),b(m);
    vvll g(n+1);
    rep(i,0,m){
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    vll array;
    rep(i,1,n+1)array.push_back(i);
    ll ans = 0;
    do{
        if(array[0] != 1)break;
        ll pos = array[0];
        rep(i,1,n){
            bool f = false;
            rep(j,0,g[pos].size()){
                if(g[pos][j] == array[i]){
                    pos = array[i];
                    f = true;
                    break;
                }
            }
            if(!f)break;
            if(i == n-1){
                ans++;
            }
        }
    }while(next_permutation(array.begin(),array.end()));
    cout << ans << endl;
}