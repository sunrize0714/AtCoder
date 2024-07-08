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

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    vll c(m);
    vector<char> r(m);
    vvll a(m);
    rep(i,0,m){
        cin >> c[i];
        rep(j,0,c[i]){
            ll x;
            cin >> x;
            x--;
            a[i].push_back(x);
        }
        cin >> r[i];
    }
    ll ans = 0;
    rep(i,0,1LL<<n){
        vll ok(n,0);
        ll cnt = 0;
        rep(j,0,n){
            if(i & (1LL<<j)){
                ok[j] = 1;
                cnt++;
            }
        }
        bool okay = true;
        rep(j,0,m){
            ll p = 0;
            rep(l,0,c[j]){
                if(ok[a[j][l]] == 1)p++;
            }
            if(p >= k && r[j] == 'x')okay = false;
            if(p < k && r[j] == 'o')okay = false;
        }
        if(okay)ans++;
    }
    cout << ans << endl;
}