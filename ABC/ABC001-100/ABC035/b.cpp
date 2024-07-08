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
    string s;
    ll t;
    cin >> s >> t;
    ll x = 0,y = 0,move = 0;
    rep(i,0,s.size()){
        if(s[i] == 'L')x--;
        if(s[i] == 'R')x++;
        if(s[i] == 'U')y++;
        if(s[i] == 'D')y--;
        if(s[i] == '?')move++;
    }
    if(t == 1){
        cout << abs(x) + abs(y) + move << endl;
    }
    else{
        ll dist = abs(x) + abs(y);
        if(dist >= move)cout << dist - move << endl;
        else{
            cout << (move-dist)%2 << endl;
        }
    }
}