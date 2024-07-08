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
    map<ll,ll> ma;
    vll a(n);
    rep(i,0,n){
        cin >> a[i];
        ma[a[i]]++;
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    ll now = 0;
    ll get = 0;
    ll ans = 0;
    ll gift = 0;
    
    while(true){
        if(a[get] - a[now] < m){
            ans += ma[a[get]];
            gift = max(gift,ans);
            get++;
            if(get == a.size()){
                cout << gift;
                return 0;
            }
        }
        else{
            ans -= ma[a[now]];
            now++;
        }
    }
    cout << gift;
}