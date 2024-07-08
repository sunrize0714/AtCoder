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
    set<string> t;
    bool ans = true;
    string a1 = "HDCS",a2 = "A23456789TJQK";
    rep(i,0,n){
        cin >> s[i];
        t.insert(s[i]);
        rep(j,0,4){
            if(s[i][0] == a1[j])break;
            if(j == 3)ans = false;
        }
        rep(j,0,13){
            if(s[i][1] == a2[j])break;
            if(j == 12)ans = false;
        }
    }
    if(t.size() != n)ans = false;
    ans ? cout << "Yes" << endl : cout << "No" << endl;
}