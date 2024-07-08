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
    ll n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    sort(s.begin(),s.end());
    rep(i,0,10000000){
        ll hei = i*i;
        string t;
        while(hei > 0){
            char e = '0' + hei%10;
            t += e;
            hei /= 10;
        }

        if(s.size() > t.size()){
            rep(j,0,t.size()-s.size()){
                t += '0';
            }
        }
        sort(t.begin(),t.end());
        if(t == s)ans++;
        
    }
    cout << ans << endl;
}