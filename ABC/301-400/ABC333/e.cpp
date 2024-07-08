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

int main(){
    ll n;
    cin >> n;
    vll t(n),x(n);
    rep(i,0,n)cin >> t[i] >> x[i];
    reverse(all(t));
    reverse(all(x));
    ll ans = 0,cnt = 0;
    map<ll,ll> m;
    vll act;
    rep(i,0,n){
        if(t[i] == 1){
            if(m[x[i]] > 0){
                act.push_back(1);
                m[x[i]]--;
                cnt--;
            }
            else act.push_back(0);
        }
        if(t[i] == 2){
            m[x[i]]++;
            cnt++;
            ans = max(ans,cnt);
        }
    }
    if(cnt != 0){
        cout << -1 << endl;
        return 0;
    }
    else{
        cout << ans << endl;
        reverse(all(act));
        rep(i,0,act.size())cout << act[i] << " ";
        cout << endl;
    }
}