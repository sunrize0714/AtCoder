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
    string n;
    cin >> n;
    if(n.size() == 1){
        cout << n << endl;
        return 0;
    }
    ll ans = 0;
    ll cnt = n.size()-1;
    rep(i,0,(1<<cnt)){
        ll pos = n[0]-'0';
        rep(j,0,cnt){
            if(i & (1 << j)){
                ans += pos;
                pos = n[j+1]-'0';
                if(j == cnt-1)ans += pos;
            }
            else{
                pos *= 10;
                pos += n[j+1]-'0';
                if(j == cnt-1)ans += pos;
            }
        }
    }
    cout << ans << endl;
}