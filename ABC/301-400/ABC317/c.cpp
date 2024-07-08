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
    ll n,m;
    cin >> n >> m;
    vvll dist(n+1,vll(n+1,-1));
    rep(i,0,m){
        ll a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    ll ans = 0;
    vll array(n);
    rep(i,0,n)array[i] = i+1;
    do{
        ll cnt = 0;
        rep(i,0,n-1){
            if(dist[array[i]][array[i+1]] == -1){
                break;
            }
            cnt += dist[array[i]][array[i+1]];
        }
        ans = max(ans,cnt);
    }while(next_permutation(all(array)));
    cout << ans << endl;
}