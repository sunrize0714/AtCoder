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
    ll n;
    cin >> n;
    vs s(n);
    vll moji(26,1e10);
    rep(i,0,n)cin >> s[i];
    rep(i,0,n){
        sort(s[i].begin(),s[i].end());
        vll ji(26,0);
        rep(j,0,s[i].size()){
            ll pos = s[i][j] - 'a';
            ji[pos]++;
        }
        rep(j,0,26){
            moji[j] = min(moji[j],ji[j]);
        }
    }
    string t;
    rep(i,0,26){
        while(moji[i] > 0){
            char u = 'a' + i;
            t += u;
            moji[i]--;
        }
    }
    cout << t << endl;
}