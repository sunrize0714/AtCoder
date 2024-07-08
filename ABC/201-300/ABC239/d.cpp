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
    set<ll> s;
    rep(i,2,201){
        bool ok = true;
        if(i <= 3)s.insert(i);
        rep(j,2,sqrt(i)+1){
            if(i%j == 0)ok = false;
        }
        if(ok)s.insert(i);
    }
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    rep(i,a,b+1){
        ll cnt = 0;
        rep(j,c,d+1){
            ll pos = i+j;
            if(s.count(pos) == 1)cnt++;
        }
        if(cnt == 0){
            cout << "Takahashi";
            return 0;
        }
    }
    cout << "Aoki";
}