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
    cin >> n;
    vector<string> s(n);
    rep(i,0,n){
        cin >> s[i];
    }
    vll win(n,1000);
    rep(i,0,n){
        rep(j,0,n){
            if(s[i][j] == 'o')win[i]--;
        }
    }
   
    vector<pair<ll,ll>> p;
    rep(i,0,n){
        p.push_back(make_pair(win[i],i+1));
    }
    sort(p.begin(),p.end());
    rep(i,0,n){
        cout << p[i].second;
        if(i == n-1)cout << endl;
        else cout << " ";
    }

}