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
    string s,t;
    cin >> s >> t;
    sort(all(s));
    sort(all(t));
    string x = "ABCDEA";
    ll a = 0,b = 0;
    rep(i,0,5){
        if(s == x.substr(i,2) || s == "AE")a = 1;
        if(t == x.substr(i,2) || t == "AE")b = 1;
    }
    a == b ? cout << "Yes" << endl:cout << "No" << endl;
}