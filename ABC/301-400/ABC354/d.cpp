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
    ll a,b ,c,d;
    cin >> a >> b >> c >> d;
    if(a < 0){
        ll x = abs(a)/4;
        x++;
        a += x*4,c += x*4;
    }
    if(b < 0){
        ll x = abs(b)/4;
        x++;
        b += x*4,d += x*4;
    }
    ll ans = 0;
    ll roop = (d-b)/2, amari = (d-b)%2;
    ll wave = (c-a)/4;
    ll start = a%4;
    ans += wave*(d-b)*4;
    
    ll pos[4] = {3,3,1,1};
    ll pos2[4] = {2,1,0,1};
    ll pos3[4] = {1,2,1,0};
    rep(i,start,start+(c-a)%4){
        ll p = i%4;
        ans += pos[p]*roop;
        if(amari == 1){
            if(b%2 == 0){
                ans += pos2[p];
            }
            else{
                ans += pos3[p];
            }
        }
    }
    cout << ans << endl;
}