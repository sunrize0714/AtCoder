#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
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
    ll n;
    cin >> n;
    ll m = 1;
    ll cnt = 0;
    while(m < n){
        m *= 2;
        cnt++;
    }
    cout << cnt << endl;
    
    vvll g(cnt);
    rep(i,0,n){
        rep(j,0,cnt){
            if(i & (1 << j)){
                g[j].push_back(i);
            }
        }
    }
    rep(i,0,cnt){
        cout << g[i].size() << " ";
        rep(j,0,g[i].size()){
            cout << g[i][j]+1 << " ";
        }
        cout << endl;
    }
    string s;
    cin >> s;
    ll ans = 0;
    rep(i,0,s.size()){
        if(s[i] == '1'){
            ans += (1 << i);
        }
    }
    cout << ans+1 << endl;
    return 0;
}   