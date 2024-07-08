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
    string x;
    cin >> x;
    ll n;
    cin >> n;
    vs s(n);
    rep(i,0,n)cin >> s[i];
    vll pos(26);
    rep(i,0,26){
        pos[x[i] - 'a'] = i;
    }
    sort(s.begin(),s.end(),[&](const string& s,const string& t){
        ll len = min(s.size(),t.size());
        rep(i,0,len){
            if(s[i] != t[i]){
                return pos[s[i] - 'a'] < pos[t[i] - 'a'];
            }
        }
        return s.size() < t.size();
    });
    rep(i,0,n)cout << s[i] << endl;    
}