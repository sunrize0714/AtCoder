#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
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

int main(){
    ll n,m;
    cin >> n >> m;
    vll a(m),cop(m);
    rep(i,0,m){
        cin >> a[i];
        cop[i] = a[i];
    }
    vector<string> s(n);
    rep(i,0,n)cin >> s[i];
    vll cur(n,0);
    rep(i,0,n){
        rep(j,0,m){
            if(s[i][j] == 'o')cur[i] += a[j];
        }
        cur[i] += i+1;
    }

    vector<pair<ll,ll>> point;
    rep(i,0,m){
        point.push_back(make_pair(10000-a[i],i));
    }
    sort(point.begin(),point.end());
    rep(i,0,m){
        cop[i] = point[i].second;
    }
    ll ma = 0;
    rep(i,0,n)ma = max(ma,cur[i]);

    rep(i,0,n){
        if(cur[i] == ma){
            cout << 0 << endl;
        }
        else{
            ll ans = 0;
            ll poi = cur[i];
            ll count = 0;
            while(poi <= ma){
                if(s[i][cop[count]] == 'x'){
                    ans++;
                    poi += a[cop[count]];
                } 
                count++;
            }
            cout << ans << endl;
        }
    }
}