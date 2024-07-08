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
    ll n,x,y;
    cin >> n >> x >> y;
    vll a(n);
    rep(i,0,n){
        cin >> a[i];
    }
    ll ans = 0;
    ll cnt = 0;
    while(cnt < n){
        vll ok;
        while(a[cnt] >= y && a[cnt] <= x){
            ok.push_back(a[cnt]);
            cnt++;
        }
        cnt++;
        ll l=0,r=0;
        ll cntx = 0,cnty = 0;
        while(l < ok.size()){
            while(r < ok.size() && (cntx == 0 || cnty == 0)){
                if(ok[r] == x)cntx++;
                if(ok[r] == y)cnty++;
                r++;
            }
            if(cntx && cnty){
                ans += ok.size()-r+1;
            }
            if(ok[l] == x)cntx--;
            if(ok[l] == y)cnty--;
            l++;
        }
    }
    cout << ans << endl;
}