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
    string s,t;
    cin >> s >> t;
    ll cnt = 0;
    vb ans1(s.size()+1,false);
    ans1[0] = true;
    rep(i,0,s.size()+1){
        if(s[i] != t[i] && s[i] != '?' && t[i] != '?')break;
        ans1[i+1] = true;
    }
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    vb ans2(s.size()+1,false);
    ans2[0] = true;
    rep(i,0,s.size()+1){
        if(s[i] != t[i] && s[i] != '?' && t[i] != '?')break;
        ans2[i+1] = true;
    }
    rep(i,0,t.size()+1){
        if(ans1[i] && ans2[t.size()-i]){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}